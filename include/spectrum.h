#include <lapin.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"
#include "gui.h"
#include "struct.h"

#ifndef __SPECTRUM_H__
#define __SPECTRUM_H__


void std_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   unsigned int color);
//void std_bunny_clear(t_bunny_pixelarray *px, unsigned int color);
void std_set_line(t_bunny_pixelarray *px,
                  t_bunny_position *pos,
                  unsigned int color);
void std_set_rectangle(t_bunny_pixelarray *px,
                       t_bunny_area area,
                       unsigned int color);
void std_set_circle(t_bunny_pixelarray *px,
                    t_bunny_position pos,
                    unsigned int color,
                    int width,
                    int height);
void stylo(t_main_data *data);
void straight_line(t_main_data *data);
void rectangle(t_main_data *data);
void circle(t_main_data *data);
void color(t_main_data *data);
void peinture(t_main_data *data);
void bucket(t_main_data *data);
void chose(t_main_data *data);
unsigned int get_pixel(const t_bunny_pixelarray *px,
		       t_bunny_position pos);
void std_blit(t_bunny_pixelarray *target, const t_bunny_pixelarray *src, const t_bunny_position *pos);
void std_square(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color);
void rectangle_not_full(t_main_data *data);
void color_picker(t_main_data *data);
void button(t_main_data *data);
void grey(t_bunny_pixelarray *px);
bool draw_zone(void);
bool undo_saver(t_main_data *data);

void save(t_main_data *data,
          char *file_name);

void load(t_main_data *data,
          char *file_name);

#endif
