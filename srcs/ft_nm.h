#ifndef FT_NM_H
#define FT_NM_H

#include <stdlib.h>

#define NM_FLAG_PRINT_REVERSE 1 << 1

typedef struct s_symbol
{
	char *name;
	size_t offset;
	char type;
} t_symbol;

#endif