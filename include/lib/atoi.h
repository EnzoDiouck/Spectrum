#ifndef __ATOI_H__
#define __ATOI_H__

#include <errno.h>

#define MAX_INT 2147483647
#define MIN_INT -2147483647

int std_atoi(const char *nptr);

int     std_negatoi(const char *str);

#endif /* __ATOI_H__ */
