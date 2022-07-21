/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-01 13:12:06
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-01 13:12:08
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __GUI_H__
#define __GUI_H__

#include <lapin.h>
#include <stdarg.h>

typedef void (*function_gui)();

size_t std_strlen(const char *str);
char *std_strcpy(char *dest, const char *src);
char *std_strdup(const char *s);
int std_strcmp(const char *str1, const char *str2);

void std_set_pixel(t_bunny_pixelarray *px, t_bunny_position pos, unsigned int color);
void std_text(t_bunny_pixelarray *pix, t_bunny_pixelarray *font, t_bunny_position pos, const char *str, unsigned int color);

typedef struct s_gui
{
    int numberOfButton;
    t_bunny_color *color;
    t_bunny_position *posButton;
    t_bunny_position *buttonSize;
    char **name;
    char **shape;
    function_gui *gui_function;
    void **argument;
} t_gui;

t_gui *std_new_gui(const char *file);
void std_delete_gui(t_gui *gui);
void std_interact_gui(t_gui *ck, const char *obj, int nbr_args, ...);
void std_display_gui(t_gui *ck, t_bunny_pixelarray *px);
void std_print(t_gui *gui);

#endif /* __GUI_H__ */