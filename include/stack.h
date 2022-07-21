#ifndef __STACK_H__
#define __STACK_H__

#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>

#include "memcpy.h"

typedef struct s_stack
{
    void *data;
    struct s_stack *next_stk;
} t_stack;

bool std_stack_push(t_stack **stk, t_bunny_pixelarray *elem);
void *std_stack_top(t_stack **stk);
void *std_stack_pop(t_stack **stk);
void std_stack_clear(t_stack **stk);
size_t std_stack_count(t_stack *stk);

#endif /*	__STACK_H__	*/
