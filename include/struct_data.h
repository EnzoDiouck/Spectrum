/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-28 12:00:31
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-28 12:00:33
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __DATA_H__
#define __DATA_H__

#include <lapin.h>
#include "gui.h"

typedef struct s_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *px;
  t_gui *gui;
  t_bunny_position pos;
} t_data;

#endif /* __DATA_H__ */
