#include "./ft_nm.h"

#define ARCHITECTURE 64
#define SUFFIX _64bits
#include "./ft_nm_template.h"

#define ARCHITECTURE 32
#define SUFFIX _32bits
#include "./ft_nm_template.h"

unsigned int g_flags = 0;

int ft_nm(char *filename)
{
	int fd;
	struct stat file_infos;
	char *file_content;

	if ((fd = open(filename, O_RDONLY)) < 0)
	{
		ft_printf("Cannot open file %s\n", filename);
		return 1;
	}

	if (fstat(fd, &file_infos) < 0)
	{
		ft_printf("Cannot stat file %s\n", filename);
		close(fd);
		return 1;
	}

	if (file_infos.st_size < EI_NIDENT) // If we cannot get identification infos (magic number, architecture etc.)
	{
		ft_printf("File '%s' has been truncated\n", filename);
		close(fd);
		return 1;
	}

	// open read only (and not shared with other processes)
	if ((file_content = mmap(NULL, file_infos.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_printf("Cannot map file %s\n", filename);
		close(fd);
		return 1;
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
			munmap(file_content, file_infos.st_size);
			return 1;
		}

		unsigned char class = elf_identification[EI_CLASS];

		if (class == ELFCLASS32)
		{
			if (ft_nm_32bits(filename, file_content, file_infos.st_size) != 0)
				return 1;
		}
		else if (class == ELFCLASS64)
		{
			if (ft_nm_64bits(filename, file_content, file_infos.st_size) != 0)
				return 1;
		}
		else
		{
			ft_printf("File '%s' header is invalid (wrong header class)\n", filename);
			munmap(file_content, file_infos.st_size);
			return 1;
		}

		munmap(file_content, file_infos.st_size);
	}
	else
	{
		ft_printf("File '%s' is not an ELF file\n", filename);
		return 1;
	}
}

// https://www.mkssoftware.com/docs/man1/nm.1.asp
// https://sourceware.org/binutils/docs/binutils/nm.html
// https://en.wikipedia.org/wiki/Executable_and_Linkable_Format#:~:text=In%20computing%2C%20the%20Executable%20and,shared%20libraries%2C%20and%20core%20dumps.
// https://docs.oracle.com/cd/E19683-01/816-1386/chapter6-79797/index.html
int main(int argc, char **argv)
{
	char *filenames[argc];
	int filecount;

	for (int i = 1; i < argc; i++)
	{
		if (!ft_strcmp("-r", argv[i]))
		{
			g_flags |= NM_FLAG_PRINT_REVERSE;
		}
		else if (!ft_strcmp("-a", argv[i]))
		{
			g_flags |= NM_FLAG_ALL_SYMBOLS;
		}
		else if (!ft_strcmp("-g", argv[i]))
		{
			g_flags |= NM_FLAG_ONLY_GLOBAL;
		}
		else if (!ft_strcmp("-u", argv[i]))
		{
			g_flags |= NM_FLAG_ONLY_UNDEFINED;
		}
		else if (!ft_strcmp("-p", argv[i]))
		{
			g_flags |= NM_FLAG_NO_SORTING;
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

	int ret = EXIT_SUCCESS;

	for (int i = 0; i < filecount; i++)
	{
		char *file = filenames[i];

		if (filecount != 1) // print filenames
			ft_printf("\n%s:\n", file);

		ret = ft_nm(file);
	}

	if (ret != 0)
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
}