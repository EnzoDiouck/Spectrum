/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-26 18:05:53
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-27 18:43:41
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __DISPLAYFUNCTION_H__
#define __DISPLAYFUNCTION_H__

#include "struct_data.h"

t_bunny_response display_function(void *d);
void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color);

#endif /* __DISPLAYFUNCTION_H__ */