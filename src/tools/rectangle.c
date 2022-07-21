#include "spectrum.h"

static void point_one(t_main_data *data, t_bunny_position *draw, const t_bunny_position *pos, t_bunny_position *tmp)
{
  (void)data;
  draw[0].x = tmp[0].x - data->pos_dessin.x;
  draw[0].y = tmp[0].y - data->pos_dessin.y;
  draw[1].x = pos->x - data->pos_dessin.x;
  draw[1].y = pos->y - data->pos_dessin.y;
}

void rectangle(t_main_data *data)
{
  const t_bunny_position *pos = bunny_get_mouse_position();
  t_bunny_position draw[2];
  t_bunny_area area;

  if (data->check == false && data->trigger == 1)
  {
    data->trigger = 0;
    data->saved_px = false;
  }
  if (data->check == false)
  {
    data->temp[0] = *pos;
    data->temp[1] = *pos;
    std_blit(data->tmp_px, data->dessin, NULL);
  }
  if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
  {
    data->trigger = 1;
    point_one(data, draw, pos, data->temp);
    std_blit(data->dessin, data->tmp_px, NULL);
    if (draw[0].x <= draw[1].x && draw[0].y <= draw[1].y)
    {
      area.x = draw[0].x;
      area.y = draw[0].y;
      area.w = draw[1].x - draw[0].x;
      area.h = draw[1].y - draw[0].y;
      std_set_rectangle(data->dessin, area, data->color);
    }
    else if (draw[1].x <= draw[0].x && draw[1].y <= draw[0].y)
    {
      area.x = draw[1].x;
      area.y = draw[1].y;
      area.w = draw[0].x - draw[1].x;
      area.h = draw[0].y - draw[1].y;
      std_set_rectangle(data->dessin, area, data->color);
    }
    else if (draw[1].x <= draw[0].x && draw[0].y <= draw[1].y)
    {
      area.x = draw[1].x;
      area.y = draw[0].y;
      area.w = draw[0].x - draw[1].x;
      area.h = draw[1].y - draw[0].y;
      std_set_rectangle(data->dessin, area, data->color);
    }
    else if (draw[0].x <= draw[0].x && draw[1].y <= draw[0].y)
    {
      area.x = draw[0].x;
      area.y = draw[1].y;
      area.w = draw[1].x - draw[0].x;
      area.h = draw[0].y - draw[1].y;
      std_set_rectangle(data->dessin, area, data->color);
    }
  }
}
