#ifndef FT_NM_H
#define FT_NM_H

#include <stdlib.h>

typedef struct s_symbol
{
	char *name;
	size_t offset;
	char type;
} t_symbol;

#endif