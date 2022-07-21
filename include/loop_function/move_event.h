/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-04 10:54:51
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-04 10:54:52
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __MOVEEVENT_H__
#define __MOVEEVENT_H__

#include "struct_data.h"

t_bunny_response move_function(const t_bunny_position *relative, void *d);
void std_clear_pixelarray(t_bunny_pixelarray *picture, unsigned int color);
void std_display_gui(t_gui *ck, t_bunny_pixelarray *px);
void std_print(t_gui *gui);

#endif /* __MOVEEVENT_H__ */