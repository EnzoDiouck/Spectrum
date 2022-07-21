/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-09 15:40:02
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-09 15:40:55
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#include "load.h"
#include "button.h"
#include <stdio.h>

static void color_reset(t_main_data *data)
{
  int i = 0;

  while (i < data->gui->numberOfButton)
  {
    data->gui->color[i].argb[RED_CMP] = 220;
    data->gui->color[i].argb[BLUE_CMP] = 220;
    data->gui->color[i].argb[GREEN_CMP] = 220;
    i++;
  }
}

static void color_reset_1(t_main_data *data)
{
  int i = 0;

  while (i < data->gui->numberOfButton)
  {
    if (data->gui->color[i].argb[RED_CMP] != 100)
      data->gui->color[i].argb[RED_CMP] = 220;
    if (data->gui->color[i].argb[BLUE_CMP] != 100)
      data->gui->color[i].argb[BLUE_CMP] = 220;
    if (data->gui->color[i].argb[GREEN_CMP] != 100)
      data->gui->color[i].argb[GREEN_CMP] = 220;
    i++;
  }
}

static void button_choosen(t_main_data *data)
{
  if (data->chose == BRUSH)
  {
    color_reset(data);
    data->gui->color[0].argb[RED_CMP] = 100;
    data->gui->color[0].argb[GREEN_CMP] = 100;
    data->gui->color[0].argb[BLUE_CMP] = 100;
  }
  else if (data->chose == BUCKET)
  {
    color_reset(data);
    data->gui->color[1].argb[RED_CMP] = 100;
    data->gui->color[1].argb[GREEN_CMP] = 100;
    data->gui->color[1].argb[BLUE_CMP] = 100;
  }
  else if (data->chose == LINE)
  {
    color_reset(data);
    data->gui->color[2].argb[RED_CMP] = 100;
    data->gui->color[2].argb[GREEN_CMP] = 100;
    data->gui->color[2].argb[BLUE_CMP] = 100;
  }
  else if (data->chose == RECTANGLENF)
  {
    color_reset(data);
    data->gui->color[3].argb[RED_CMP] = 100;
    data->gui->color[3].argb[GREEN_CMP] = 100;
    data->gui->color[3].argb[BLUE_CMP] = 100;
  }
  else if (data->chose == RECTANGLE)
  {
    color_reset(data);
    data->gui->color[4].argb[RED_CMP] = 100;
    data->gui->color[4].argb[GREEN_CMP] = 100;
    data->gui->color[4].argb[BLUE_CMP] = 100;
  }
  else if (data->chose == CIRCLE)
  {
    color_reset(data);
    data->gui->color[5].argb[RED_CMP] = 100;
    data->gui->color[5].argb[GREEN_CMP] = 100;
    data->gui->color[5].argb[BLUE_CMP] = 100;
  }
  else
    color_reset(data);
}

void button(t_main_data *data)
{
  const t_bunny_position *pos = bunny_get_mouse_position();

  button_choosen(data);
  if (pos->x >= 20 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 20 + 68)
  {
    color_reset_1(data);
    if (data->gui->color[0].argb[RED_CMP] != 100)
      data->gui->color[0].argb[RED_CMP] = 200;
    if (data->gui->color[0].argb[GREEN_CMP] != 100)
      data->gui->color[0].argb[GREEN_CMP] = 200;
    if (data->gui->color[0].argb[BLUE_CMP] != 100)
      data->gui->color[0].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->chose = BRUSH;
      data->check = false;
    }
  }
  else if (pos->x >= 88 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 88 + 68)
  {
    color_reset_1(data);
    if (data->gui->color[1].argb[RED_CMP] != 100)
      data->gui->color[1].argb[RED_CMP] = 200;
    if (data->gui->color[1].argb[GREEN_CMP] != 100)
      data->gui->color[1].argb[GREEN_CMP] = 200;
    if (data->gui->color[1].argb[BLUE_CMP] != 100)
      data->gui->color[1].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->chose = BUCKET;
      data->check = false;
    }
  }
  else if (pos->x >= 156 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 156 + 68)
  {
    color_reset_1(data);
    if (data->gui->color[2].argb[RED_CMP] != 100)
      data->gui->color[2].argb[RED_CMP] = 200;
    if (data->gui->color[2].argb[GREEN_CMP] != 100)
      data->gui->color[2].argb[GREEN_CMP] = 200;
    if (data->gui->color[2].argb[BLUE_CMP] != 100)
      data->gui->color[2].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->chose = LINE;
      data->check = false;
    }
  }
  else if (pos->x >= 224 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 224 + 68)
  {
    color_reset_1(data);
    if (data->gui->color[3].argb[RED_CMP] != 100)
      data->gui->color[3].argb[RED_CMP] = 200;
    if (data->gui->color[3].argb[GREEN_CMP] != 100)
      data->gui->color[3].argb[GREEN_CMP] = 200;
    if (data->gui->color[3].argb[BLUE_CMP] != 100)
      data->gui->color[3].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->chose = RECTANGLENF;
      data->check = false;
    }
  }
  else if (pos->x >= 292 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 292 + 68)
  {
    color_reset_1(data);
    if (data->gui->color[4].argb[RED_CMP] != 100)
      data->gui->color[4].argb[RED_CMP] = 200;
    if (data->gui->color[4].argb[GREEN_CMP] != 100)
      data->gui->color[4].argb[GREEN_CMP] = 200;
    if (data->gui->color[4].argb[BLUE_CMP] != 100)
      data->gui->color[4].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->chose = RECTANGLE;
      data->check = false;
    }
  }
  else if (pos->x >= 368 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 360 + 68)
  {
    color_reset_1(data);
    if (data->gui->color[5].argb[RED_CMP] != 100)
      data->gui->color[5].argb[RED_CMP] = 200;
    if (data->gui->color[5].argb[GREEN_CMP] != 100)
      data->gui->color[5].argb[GREEN_CMP] = 200;
    if (data->gui->color[5].argb[BLUE_CMP] != 100)
      data->gui->color[5].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->chose = CIRCLE;
      data->check = false;
    }
  }
  else if (pos->x >= 428 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 428 + 68)
  {
    color_reset_1(data);
    data->gui->color[6].argb[RED_CMP] = 200;
    data->gui->color[6].argb[GREEN_CMP] = 200;
    data->gui->color[6].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->gui->color[6].argb[RED_CMP] = 100;
      data->gui->color[6].argb[GREEN_CMP] = 100;
      data->gui->color[6].argb[BLUE_CMP] = 100;
      data->reversed = false;
      data->color = data->save_color;
      std_bunny_clear(data->dessin, WHITE);
      data->saved_px = false;
      data->check = false;
    }
  }
  else if (pos->x >= 496 && pos->y >= 20 && pos->y <= 20 + 60 && pos->x <= 496 + 68)
  {
    color_reset_1(data);
    data->gui->color[7].argb[RED_CMP] = 200;
    data->gui->color[7].argb[GREEN_CMP] = 200;
    data->gui->color[7].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->gui->color[7].argb[RED_CMP] = 100;
      data->gui->color[7].argb[GREEN_CMP] = 100;
      data->gui->color[7].argb[BLUE_CMP] = 100;
      if (data->stk->next_stk != NULL)
      {
        std_stack_pop(&data->stk);
        std_blit(data->dessin, data->stk->data, NULL);
      }
      data->check = false;
    }
  }
  else if (pos->x >= 720 && pos->y >= 20 && pos->y <= 20 + 30 && pos->x <= 720 + 68)
  {
    color_reset_1(data);
    data->gui->color[10].argb[RED_CMP] = 200;
    data->gui->color[10].argb[GREEN_CMP] = 200;
    data->gui->color[10].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->gui->color[10].argb[RED_CMP] = 100;
      data->gui->color[10].argb[GREEN_CMP] = 100;
      data->gui->color[10].argb[BLUE_CMP] = 100;
      save(data, "test");
      data->check = false;
    }
  }
  else if (pos->x >= 720 && pos->y >= 20 + 30 && pos->y <= 50 + 30 && pos->x <= 720 + 68)
  {
    color_reset_1(data);
    data->gui->color[11].argb[RED_CMP] = 200;
    data->gui->color[11].argb[GREEN_CMP] = 200;
    data->gui->color[11].argb[BLUE_CMP] = 200;
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
      data->gui->color[11].argb[RED_CMP] = 100;
      data->gui->color[11].argb[GREEN_CMP] = 100;
      data->gui->color[11].argb[BLUE_CMP] = 100;
      load(data, "test");
      ;
      data->check = false;
    }
  }
}
