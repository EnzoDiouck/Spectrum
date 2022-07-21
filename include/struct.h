#ifndef __STRUCT_H__
#define __STRUCT_H__

#include <lapin.h>
#include "gui.h"
#include "stack.h"
#include <stdbool.h>


#define BRUSH 1
#define BUCKET 2
#define LINE 3
#define RECTANGLE 4
#define RECTANGLENF 5
#define CIRCLE 6
#define SAVE 8

typedef struct s_main_data
{
  t_bunny_window *win;
  t_bunny_pixelarray *px;
  t_bunny_pixelarray *dessin;
  t_bunny_pixelarray *undo;
  t_bunny_position pos_dessin;
  t_bunny_pixelarray *tmp_px;
  t_bunny_pixelarray *rgb;
  t_bunny_position temp[2];
  t_bunny_position pos_rgb;
  t_stack *stk;
  int i;
  unsigned int color;
  unsigned int save_color;
  unsigned int verif_color;
  bool check;
  int chose;
  int trigger;
  t_gui *gui;
  bool reversed;
  bool greyed;
  bool square_draw;
  bool saved_px;
} t_main_data;


#endif /* __STRUCT_H__ */
