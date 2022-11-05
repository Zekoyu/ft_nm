#include "./ft_nm.h"

#define ARCHITECTURE 64
#define SUFFIX _64bits
#include "./ft_nm_template.h"

unsigned int g_flags = 0;

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
	if ((file_content = mmap(NULL, file_infos.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
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
			munmap(file_content, file_infos.st_size);
			return;
		}

		unsigned char class = elf_identification[EI_CLASS];

		if (class == ELFCLASS32)
		{

		}
		else if (class == ELFCLASS64)
		{
			ft_nm_64bits(filename, file_content, file_infos.st_size);
		}
		else
		{
			ft_printf("File '%s' header is invalid (wrong header class)\n", filename);
			munmap(file_content, file_infos.st_size);
			return;
		}

		munmap(file_content, file_infos.st_size);
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