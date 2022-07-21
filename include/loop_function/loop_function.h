/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-26 18:05:53
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-27 18:43:47
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __LOOPFUNCTION_H__
#define __LOOPFUNCTION_H__

#include "struct_data.h"

t_bunny_response loop_function(void *d);
void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color);

#endif /* __LOOPFUNCTION_H__ */