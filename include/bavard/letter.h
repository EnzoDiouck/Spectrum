/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-28 11:55:38
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-28 11:55:39
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __LETTER_H__
#define __LETTER_H__

#include <lapin.h>
#include <liblapin.h>

unsigned int std_get_pixel(const t_bunny_pixelarray *px, t_bunny_position pos);
void std_set_pixel(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);
void std_letter(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, char c, unsigned int color);

#endif /* __LETTER_H__ */