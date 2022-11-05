#ifndef FT_NM_H
#define FT_NM_H

#include <stdlib.h>
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

#define NM_FLAG_PRINT_REVERSE 1 << 1 // -r
#define NM_FLAG_ALL_SYMBOLS 1 << 2 // -a
#define NM_FLAG_ONLY_GLOBAL 1 << 3 // -g
#define NM_FLAG_ONLY_UNDEFINED 1 << 4 // -u

typedef struct s_symbol
{
	char *name;
	size_t offset;
	char type;
} t_symbol;

extern unsigned int g_flags;

#endif