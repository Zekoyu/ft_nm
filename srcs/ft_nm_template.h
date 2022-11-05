// https://stackoverflow.com/questions/2873850/is-there-an-equivalent-in-c-for-c-templates
#ifndef SUFFIX
    #define SUFFIX
#endif
#define CCAT2(x, y) x ## y
#define CCAT(x, y) CCAT2(x, y)
#define FN(x) CCAT(x, SUFFIX)

#ifndef ARCHITECTURE
    #error Template argument missing.
#endif

#define CCAT_NAME(prefix, suffix) CCAT(prefix, CCAT(ARCHITECTURE, suffix))

#include "./ft_nm.h"

void FN(ft_nm)() {
    CCAT_NAME(Elf, _Ehdr) pouet;
	return;
}


// #include "./ft_nm.h"

// void nm_64bits(char *filename, char *file_content, size_t file_size)
// {
// 	if (file_size < sizeof(Elf64_Ehdr))
// 	{
// 		ft_printf("File '%s' header has been truncated\n", filename);
// 		return;
// 	}
// 	//http://www.skyfree.org/linux/references/ELF_Format.pdf

// 	Elf64_Ehdr header = *(Elf64_Ehdr *)file_content;

// 	void *header_section_start = file_content + header.e_shoff;
// 	size_t header_section_size = header.e_shentsize;
// 	size_t header_section_entries_count = header.e_shnum;
// 	size_t shstrtab_section_index = header.e_shstrndx;

// 	if ((char *)header_section_start + (header_section_size * header_section_entries_count) > file_content + file_size)
// 	{
// 		ft_printf("File '%s' section headers have been truncated\n", filename);
// 		return;
// 	}

// 	if (shstrtab_section_index >= header_section_entries_count)
// 	{
// 		ft_printf("File '%s' shstrtab section index is wrong");
// 		return;
// 	}

// 	Elf64_Shdr *section_header_table = (Elf64_Shdr *)header_section_start;

// 	Elf64_Shdr shstrtab = section_header_table[shstrtab_section_index];

// 	if (shstrtab.sh_type != SHT_STRTAB)
// 	{
// 		ft_printf("File '%s' shstrab table not found (invalid sh_type)\n", filename);
// 		return;
// 	}

// 	if (shstrtab.sh_offset + shstrtab.sh_size > file_size)
// 	{
// 		ft_printf("File '%s' shstrab size does not match\n", filename);
// 		return;
// 	}

// 	Elf64_Shdr strtab;
// 	Elf64_Shdr symtab;
// 	ft_bzero(&strtab, sizeof(strtab));
// 	ft_bzero(&symtab, sizeof(symtab));

// 	for (size_t i = 0; i < header_section_entries_count; i++)
// 	{
// 		Elf64_Shdr section_header = section_header_table[i];

// 		char *name = file_content + shstrtab.sh_offset + section_header.sh_name;
// 		if (name >= file_content + file_size)
// 		{
// 			ft_printf("File '%s' header %u name is located outside executable\n", filename, i);
// 			return;
// 		}

// 		if (!ft_strncmp(".strtab", name, ft_strlen(".strtab") + 1) && section_header.sh_type == SHT_STRTAB)
// 		{
// 			// Name cannot be NULL, so if already there it means multiple .strtab sections (since we bzero before)
// 			if (strtab.sh_name != 0)
// 			{
// 				ft_printf("File '%s' has multiple .strtab sections\n", filename);
// 				return;
// 			}
// 			strtab = section_header;
// 		}
// 		else if (!ft_strncmp(".symtab", name, ft_strlen(".symtab") + 1) && section_header.sh_type == SHT_SYMTAB)
// 		{
// 			if (symtab.sh_name != 0)
// 			{
// 				ft_printf("File '%s' has multiple .symtab sections\n", filename);
// 				return;
// 			}
// 			symtab = section_header;
// 		}

// 		// ft_printf("Section %u name is %s\n", i, name);
// 	}

// 	if (strtab.sh_name == 0)
// 	{
// 		ft_printf("File '%s' has no .strtab section\n");
// 		return;
// 	}
// 	if (symtab.sh_name == 0)
// 	{
// 		ft_printf("File '%s' has no .symtab section\n");
// 		return;
// 	}
// 	if (strtab.sh_offset + strtab.sh_size > file_size)
// 	{
// 		ft_printf("File '%s' .strtab size is wrong\n");
// 		return;
// 	}
// 	if (symtab.sh_offset + symtab.sh_size > file_size)
// 	{
// 		ft_printf("File '%s' .symtab size is wrong\n");
// 		return;
// 	}

// 	Elf64_Sym *symbol_table = (Elf64_Sym *)(file_content + symtab.sh_offset);

// 	size_t symbol_count = symtab.sh_size / sizeof(Elf64_Sym);
// 	t_symbol *symbols = malloc(symbol_count * sizeof(t_symbol));
// 	if (!symbols)
// 	{
// 		ft_printf("Malloc error in '%s' file while trying to allocate size for %u symbols\n", filename, symbol_count);
// 		return;
// 	}
// 	ft_bzero(symbols, sizeof(t_symbol) * symbol_count);

// 	for (size_t i = 0, symbol_index = 0; i < symtab.sh_size / sizeof(Elf64_Sym); i++)
// 	{
// 		t_symbol *symbol = symbols + symbol_index;

// 		symbol->name = NULL;

// 		// st_name can be NULL meaning no name
// 		// st_shndx is the section index the symbol is in, if none (SHN_abs = 65521), don't count
// 		// real nm doesn't show symbols marked as ABS (readelf -s ./ft_nm)
// 		// see https://stackoverflow.com/questions/3065535/what-are-the-meanings-of-the-columns-of-the-symbol-table-displayed-by-readelf
// 		if (symbol_table[i].st_name == 0 || symbol_table[i].st_shndx == SHN_ABS)
// 		{
// 			symbol_count--; // dont count symbol in list if no name
// 			continue;
// 		}

// 		// STB_WEAK

// 		symbol->name = (file_content + strtab.sh_offset) + symbol_table[i].st_name;

// 		symbol->offset = symbol_table[i].st_value;
// 		unsigned char st_bind = ELF64_ST_BIND(symbol_table[i].st_info);
// 		unsigned char st_type = ELF64_ST_TYPE(symbol_table[i].st_info);

// 		// https://stackoverflow.com/questions/15225346/how-to-display-the-symbols-type-like-the-nm-command
// 		Elf64_Sym *elf_symbol = &(symbol_table[i]);

// 		if (st_bind == STB_GNU_UNIQUE)
// 			symbol->type = 'u';
// 		else if (st_bind == STB_WEAK)
// 		{
// 			// st_shndx holds index of section of symbol (undef = external)
// 			if (elf_symbol->st_shndx == SHN_UNDEF)
// 				symbol->type = 'w';
// 			else
// 				symbol->type = 'W'; // upercase means a default value has been specified
// 		}
// 		else if (st_bind == STB_WEAK && st_type == STT_OBJECT)
// 		{
// 			if (elf_symbol->st_shndx == SHN_UNDEF)
// 				symbol->type = 'v';
// 			else
// 				symbol->type = 'V';
// 		}
// 		else if (elf_symbol->st_shndx == SHN_UNDEF)
// 		{
// 			symbol->type = 'U';
// 		}
// 		else if (elf_symbol->st_shndx == SHN_ABS)
// 		{
// 			symbol->type = 'A';
// 		}
// 		else if (elf_symbol->st_shndx == SHN_COMMON)
// 		{
// 			symbol->type = 'C';
// 		}
// 		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_NOBITS \
// 				 && section_header_table[elf_symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
// 		{
// 			symbol->type = 'B';
// 		}
// 		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_PROGBITS \
// 				 && section_header_table[elf_symbol->st_shndx].sh_flags == SHF_ALLOC)
// 		{
// 			symbol->type = 'R';
// 		}
// 		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_PROGBITS \
// 				 && section_header_table[elf_symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_WRITE))
// 		{
// 			symbol->type = 'D';
// 		}
// 		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_PROGBITS \
// 				 && section_header_table[elf_symbol->st_shndx].sh_flags == (SHF_ALLOC | SHF_EXECINSTR))
// 		{
// 			symbol->type = 'T';
// 		}
// 		else if (section_header_table[elf_symbol->st_shndx].sh_type == SHT_DYNAMIC)
// 		{
// 			symbol->type ='D';
// 		}
// 		else
// 		{
// 			symbol->type = '?';
// 		}

// 		// make lowercase if local
// 		if (symbol->type != '?' && st_bind == STB_LOCAL)
// 			symbol->type += 32;

// 		// printf("%s: ", symbol->name);

// 		// printf("%04X ", *((Elf64_Word *)elf_symbol));
// 		// printf("%X ", *((unsigned char *)elf_symbol + sizeof(Elf64_Word)));
// 		// printf("%X ", *((unsigned char *)elf_symbol + sizeof(Elf64_Word) + 1));
// 		// printf("%04X ", *((Elf64_Word *)elf_symbol + sizeof(Elf64_Word) + 2));
// 		// printf("%02X ", *((Elf64_Half *)((char *)elf_symbol + sizeof(Elf64_Word) + 2)));
// 		// printf("%08lX ", *((Elf64_Addr *)((char *)elf_symbol + sizeof(Elf64_Word) + 2 + sizeof(Elf64_Half))));
// 		// printf("%08lX\n", *((Elf64_Xword*)((char *)elf_symbol + sizeof(Elf64_Word) + 2 + sizeof(Elf64_Half) + sizeof(Elf64_Xword))));

// 		symbol_index++;
// 	}

// 	// sort_symbols:
// 	for (size_t i = 0; i < symbol_count - 1; i++)
// 	{
// 		for (size_t j = 0; j < symbol_count - i - 1; j++)
// 		{
// 			if (i == j)
// 				continue;

// 			int str_diff = ft_strcmp(symbols[j].name, symbols[j + 1].name);

// 			if ((str_diff > 0 && !(g_flags & NM_FLAG_PRINT_REVERSE)) \
// 				|| (str_diff < 0 && (g_flags & NM_FLAG_PRINT_REVERSE)))
// 			{
// 				t_symbol tmp = symbols[j];
// 				symbols[j] = symbols[j + 1];
// 				symbols[j + 1] = tmp;
// 			}
// 			// // nm seems to sort from biggest value to lowest if the name is the same
// 			// else if (str_diff == 0 && symbols[j].offset != 0 && symbols[j].offset != 0 \
// 			// 	&& ((!(g_flags | NM_FLAG_PRINT_REVERSE)) && symbols[j].offset > symbols[j + 1].offset) \
// 			// 		|| ((g_flags | NM_FLAG_PRINT_REVERSE) && symbols[j].offset < symbols[j + 1].offset))
// 			// {
// 			// 	t_symbol tmp = symbols[j];
// 			// 	symbols[j] = symbols[j + 1];
// 			// 	symbols[j + 1] = tmp;
// 			// }
// 		}
// 	}


// 	// print_symbols:
// 	for (size_t i = 0; i < symbol_count; i++)
// 	{
// 		t_symbol symbol = symbols[i];

// 		__uint128_t offset_clone = symbol.offset;
// 		while (symbol.name != NULL && offset_clone != 0 && offset_clone < (0x0fffffffffffffff))
// 		{
// 			ft_printf("0");
// 			offset_clone *= 16;
// 		}

// 		if (symbol.name != NULL)
// 		{
// 			if (symbol.offset == 0)
// 				ft_printf("                 %c %s\n", symbol.type, symbol.name);
// 			else
// 				ft_printf("%x %c %s\n", symbol.offset, symbol.type, symbol.name);
// 		}
// 	}
// }


#undef T
#undef PREFIX
#undef CCAT2
#undef CCAT
#undef FN
#undef CCAT_NAME