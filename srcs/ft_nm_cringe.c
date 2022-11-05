#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/mman.h>
#include <stdint.h>

// https://github.com/torvalds/linux/blob/master/include/uapi/linux/elf.h
#ifdef __linux__
# include <elf.h>
#elif __APPLE__
# include "./elf.h" // for autocompletion
#endif

#include "./libft/libft.h"
#include "./ft_nm.h"

unsigned int g_flags;

void nm_64bits(char *filename, char *file_content, size_t file_size)
{
	if (file_size < sizeof(Elf64_Ehdr))
	{
		ft_printf("File '%s' header has been truncated\n", filename);
		return;
	}
	//http://www.skyfree.org/linux/references/ELF_Format.pdf

	Elf64_Ehdr header = *(Elf64_Ehdr *)file_content;

	void *section_header_start = file_content + header.e_shoff;
	size_t section_header_size = header.e_shentsize;
	size_t section_header_count = header.e_shnum;
	size_t shstrtab_index = header.e_shstrndx;


	if ((char *)section_header_start + (section_header_size * section_header_count) > file_content + file_size)
	{
		ft_printf("File '%s' section headers have been truncated\n", filename);
		return;
	}

	Elf64_Shdr *section_header_table = (Elf64_Shdr *)section_header_start;

	Elf64_Shdr shstrtab = section_header_table[shstrtab_index];

	if (shstrtab.sh_type != SHT_STRTAB)
	{
		ft_printf("File '%s' shstrab table not found (invalid sh_type)\n", filename);
		return;
	}

	if (shstrtab.sh_offset + shstrtab.sh_size > file_size)
	{
		ft_printf("File '%s' shstrab size does not match\n", filename);
		return;
	}

	Elf64_Shdr strtab;
	Elf64_Shdr symtab;
	ft_bzero(&strtab, sizeof(strtab));
	ft_bzero(&symtab, sizeof(symtab));

	for (size_t i = 0; i < section_header_count; i++)
	{
		Elf64_Shdr section_header = section_header_table[i];

		char *name = file_content + shstrtab.sh_offset + section_header.sh_name;
		if (name >= file_content + file_size)
		{
			ft_printf("File '%s' header %u name is located outside executable\n", filename, i);
			return;
		}

		if (!ft_strncmp(".strtab", name, ft_strlen(".strtab") + 1) && section_header.sh_type == SHT_STRTAB)
		{
			// Name cannot be NULL, so if already there it means multiple .strtab sections (since we bzero before)
			if (strtab.sh_name != 0)
			{
				ft_printf("File '%s' has multiple .strtab sections\n", filename);
				return;
			}
			strtab = section_header;
		}
		else if (!ft_strncmp(".symtab", name, ft_strlen(".symtab") + 1) && section_header.sh_type == SHT_SYMTAB)
		{
			if (symtab.sh_name != 0)
			{
				ft_printf("File '%s' has multiple .symtab sections\n", filename);
				return;
			}
			symtab = section_header;
		}

		// ft_printf("Section %u name is %s\n", i, name);
	}

	if (strtab.sh_name == 0)
	{
		ft_printf("File '%s' has no .strtab section\n");
		return;
	}
	if (symtab.sh_name == 0)
	{
		ft_printf("File '%s' has no .symtab section\n");
		return;
	}
	if (strtab.sh_offset > file_size)
	{
		ft_printf("File '%s' .strtab size is wrong\n");
		return;
	}
	if (symtab.sh_offset > file_size)
	{
		ft_printf("File '%s' .symtab size is wrong\n");
		return;
	}



	// no mo check

	Elf64_Sym *symbol_table = (Elf64_Sym *)(file_content + symtab.sh_offset);

	size_t symbol_count = symtab.sh_size / sizeof(Elf64_Sym);
	t_symbol *symbols = malloc(symbol_count * sizeof(t_symbol));
	ft_bzero(symbols, sizeof(t_symbol) * symbol_count);

	for (size_t i = 0, symbol_index = 0; i < symtab.sh_size / sizeof(Elf64_Sym); i++)
	{
		t_symbol *symbol = symbols + symbol_index;

		symbol->name = NULL;

		// st_name can be NULL meaning no name
		// st_shndx is the section index the symbol is in, if none (SHN_abs = 65521), don't count
		// real nm doesn't show symbols marked as ABS (readelf -s ./ft_nm)
		// see https://stackoverflow.com/questions/3065535/what-are-the-meanings-of-the-columns-of-the-symbol-table-displayed-by-readelf
		if (symbol_table[i].st_name == 0 || symbol_table[i].st_shndx == SHN_ABS)
		{
			symbol_count--; // dont count symbol in list if no name
			continue;
		}

		// STB_WEAK

		symbol->name = (file_content + strtab.sh_offset) + symbol_table[i].st_name;

		symbol->offset = symbol_table[i].st_value;
		unsigned char st_bind = ELF64_ST_BIND(symbol_table[i].st_info);
		unsigned char st_type = ELF64_ST_TYPE(symbol_table[i].st_info);

		// https://stackoverflow.com/questions/15225346/how-to-display-the-symbols-type-like-the-nm-command
		Elf64_Sym *elf_symbol = &(symbol_table[i]);

		if (st_bind == STB_GNU_UNIQUE)
			symbol->type = 'u';
		else if (st_bind == STB_WEAK)
		{
			// st_shndx holds index of section of symbol (undef = external)
			if (elf_symbol->st_shndx == SHN_UNDEF)
				symbol->type = 'w';
			else
				symbol->type = 'W'; // upercase means a default value has been specified
		}
		else if (st_bind == STB_WEAK && st_type == STT_OBJECT)
		{
			if (elf_symbol->st_shndx == SHN_UNDEF)
				symbol->type = 'v';
			else
				symbol->type = 'V';
		}
		else if (elf_symbol->st_shndx == SHN_UNDEF)
		{
			symbol->type = 'U';
		}
		else if (elf_symbol->st_shndx == SHN_ABS)
		{
			symbol->type = 'A';
		}
		else if (elf_symbol->st_shndx == SHN_COMMON)
		{
			symbol->type = 'C';
		}
		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_NOBITS \
				 && section_header_table[elf_symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
		{
			symbol->type = 'B';
		}
		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_PROGBITS \
				 && section_header_table[elf_symbol->st_shndx].sh_flags == SHF_ALLOC)
		{
			symbol->type = 'R';
		}
		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_PROGBITS \
				 && section_header_table[elf_symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
		{
			symbol->type = 'D';
		}
		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_PROGBITS \
				 && section_header_table[elf_symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
		{
			symbol->type = 'T';
		}
		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_DYNAMIC)
		{
			symbol->type ='D';
		}
		else
		{
			symbol->type = '?';
		}

		// make lowercase if local
		if (symbol->type != '?' && st_bind == STB_LOCAL)
			symbol->type += 32;

		// printf("%s: ", symbol->name);

		// printf("%04X ", *((Elf64_Word *)elf_symbol));
		// printf("%X ", *((unsigned char *)elf_symbol + sizeof(Elf64_Word)));
		// printf("%X ", *((unsigned char *)elf_symbol + sizeof(Elf64_Word) + 1));
		// printf("%04X ", *((Elf64_Word *)elf_symbol + sizeof(Elf64_Word) + 2));
		// printf("%02X ", *((Elf64_Half *)((char *)elf_symbol + sizeof(Elf64_Word) + 2)));
		// printf("%08lX ", *((Elf64_Addr *)((char *)elf_symbol + sizeof(Elf64_Word) + 2 + sizeof(Elf64_Half))));
		// printf("%08lX\n", *((Elf64_Xword*)((char *)elf_symbol + sizeof(Elf64_Word) + 2 + sizeof(Elf64_Half) + sizeof(Elf64_Xword))));

		symbol_index++;
	}

	// sort_symbols:
	for (size_t i = 0; i < symbol_count - 1; i++)
	{
		for (size_t j = 0; j < symbol_count - i - 1; j++)
		{
			if (i == j /*|| symbols[j].name == NULL || symbols[j + 1].name == NULL*/)
				continue;

			int str_diff = ft_strcmp(symbols[j].name, symbols[j + 1].name);

			if ((str_diff > 0 && !(g_flags & NM_FLAG_PRINT_REVERSE)) \
				|| (str_diff < 0 && (g_flags & NM_FLAG_PRINT_REVERSE)))
			{
				t_symbol tmp = symbols[j];
				symbols[j] = symbols[j + 1];
				symbols[j + 1] = tmp;
			}
			// // nm seems to sort from biggest value to lowest if the name is the same
			// else if (str_diff == 0 && symbols[j].offset != 0 && symbols[j].offset != 0 \
			// 	&& ((!(g_flags | NM_FLAG_PRINT_REVERSE)) && symbols[j].offset > symbols[j + 1].offset) \
			// 		|| ((g_flags | NM_FLAG_PRINT_REVERSE) && symbols[j].offset < symbols[j + 1].offset))
			// {
			// 	t_symbol tmp = symbols[j];
			// 	symbols[j] = symbols[j + 1];
			// 	symbols[j + 1] = tmp;
			// }
		}
	}


	// print_symbols:
	for (size_t i = 0; i < symbol_count; i++)
	{
		t_symbol symbol = symbols[i];

		__uint128_t offset_clone = symbol.offset;
		while (symbol.name != NULL && offset_clone != 0 && offset_clone < (0x0fffffffffffffff))
		{
			ft_printf("0");
			offset_clone *= 16;
		}

		if (symbol.name != NULL)
		{
			if (symbol.offset == 0)
				ft_printf("                 %c %s\n", symbol.type, symbol.name);
			else
				ft_printf("%x %c %s\n", symbol.offset, symbol.type, symbol.name);
		}
	}
}

void ft_nm(char *filename)
{
	int fd;
	struct stat file_infos;
	char *file_content;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_printf("Cannot open file %s\n", filename);
		return;
	}

	if (fstat(fd, &file_infos) < 0)
	{
		ft_printf("Cannot stat file %s\n", filename);
		close(fd);
		return;
	}

	if (file_infos.st_size < EI_NIDENT) // If we cannot get identification infos (magic number, architecture etc.)
	{
		ft_printf("File '%s' has been truncated\n", filename);
		close(fd);
		return;
	}

	// open read only (and not shared with other processes)
	if((file_content = mmap(NULL, file_infos.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_printf("Cannot map file %s\n", filename);
		close(fd);
		return;
	}

	// from the man, we can close the fd without invalidating the mapping, so close it asap
	close(fd);
	// ft_printf("File %s successfully opened and mapped\n", filename);


	// only read first bytes to check magic number and 32/64 bits
	// see https://github.com/torvalds/linux/blob/master/include/uapi/linux/elf.h
	// and https://en.wikipedia.org/wiki/Executable_and_Linkable_Format
	unsigned char *elf_identification = (unsigned char*)file_content;

	if (elf_identification[EI_MAG0] == ELFMAG0 && elf_identification[EI_MAG1] == ELFMAG1 && elf_identification[EI_MAG2] == ELFMAG2 && elf_identification[EI_MAG3] == ELFMAG3)
	{
		if (elf_identification[EI_VERSION] != EV_CURRENT)
		{
			ft_printf("File '%s' ELF version is invalid\n", filename);
			return;
		}

		int is_32bits;
		unsigned char class = elf_identification[EI_CLASS];

		if (class == 1)
		{
			is_32bits = 1;
		}
		else if(class == 2)
		{
			is_32bits = 0;
		}
		else
		{
			ft_printf("File '%s' header is invalid\n", filename);
			return;
		}


		if (is_32bits)
		{

		}
		else
			nm_64bits(filename, file_content, file_infos.st_size);
	}
	else
	{
		ft_printf("File '%s' is not an ELF file\n", filename);
		return;
	}
}

// https://medium.com/a-42-journey/nm-otool-everything-you-need-to-know-to-build-your-own-7d4fef3d7507
int main(int argc, char **argv)
{
	char *filenames[argc];
	int filecount;
	g_flags = 0;

	for (int i = 1; i < argc; i++)
	{
		if (!ft_strcmp("-r", argv[i]))
		{
			g_flags |= NM_FLAG_PRINT_REVERSE;
		}
		else
		{
			filenames[filecount++] = argv[i];
		}
	}


	if (filecount == 0)
	{
		filecount = 1;
		filenames[0] = "a.out";
	}

	for (int i = 0; i < filecount; i++)
	{
		char *file = filenames[i];

		if (filecount != 1) // print filenames
			ft_putstr_fd("test", STDOUT_FILENO);
			// ft_printf("\n%s:\n", file);

		ft_nm(file);
	}
}