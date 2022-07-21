#include "spectrum.h"
#include "draw_struct.h"

static void draw_init_1(t_main_data *data, t_draw_position *draw, const t_bunny_position *position)
{
  data->temp[0] = *position;
  draw->draw[0].x = data->temp[1].x - data->pos_dessin.x;
  draw->draw[0].y = data->temp[1].y - data->pos_dessin.y;
  draw->draw1[0].x = data->temp[1].x - data->pos_dessin.x + 1;
  draw->draw1[0].y = data->temp[1].y - data->pos_dessin.y;
  draw->draw2[0].x = data->temp[1].x - data->pos_dessin.x - 1;
  draw->draw2[0].y = data->temp[1].y - data->pos_dessin.y;
  draw->draw3[0].x = data->temp[1].x - data->pos_dessin.x;
  draw->draw3[0].y = data->temp[1].y - data->pos_dessin.y - 1;
  draw->draw4[0].x = data->temp[1].x - data->pos_dessin.x;
  draw->draw4[0].y = data->temp[1].y - data->pos_dessin.y + 1;
  draw->draw[1].x = position->x - data->pos_dessin.x;
  draw->draw[1].y = position->y - data->pos_dessin.y;
  draw->draw1[1].x = position->x - data->pos_dessin.x + 1;
  draw->draw1[1].y = position->y - data->pos_dessin.y;
  draw->draw2[1].x = position->x - data->pos_dessin.x - 1;
  draw->draw2[1].y = position->y - data->pos_dessin.y;
  draw->draw3[1].x = position->x - data->pos_dessin.x;
  draw->draw3[1].y = position->y - data->pos_dessin.y - 1;
  draw->draw4[1].x = position->x - data->pos_dessin.x;
  draw->draw4[1].y = position->y - data->pos_dessin.y + 1;
}

static void draw_init_2(t_main_data *data, t_draw_position *draw, const t_bunny_position *position)
{
  data->temp[1] = *position;
  draw->draw[0].x = data->temp[0].x - data->pos_dessin.x;
  draw->draw[0].y = data->temp[0].y - data->pos_dessin.y;
  draw->draw1[0].x = data->temp[0].x - data->pos_dessin.x + 1;
  draw->draw1[0].y = data->temp[0].y - data->pos_dessin.y;
  draw->draw2[0].x = data->temp[0].x - data->pos_dessin.x - 1;
  draw->draw2[0].y = data->temp[0].y - data->pos_dessin.y;
  draw->draw3[0].x = data->temp[0].x - data->pos_dessin.x;
  draw->draw3[0].y = data->temp[0].y - data->pos_dessin.y - 1;
  draw->draw4[0].x = data->temp[0].x - data->pos_dessin.x;
  draw->draw4[0].y = data->temp[0].y - data->pos_dessin.y + 1;
  draw->draw[1].x = position->x - data->pos_dessin.x;
  draw->draw[1].y = position->y - data->pos_dessin.y;
  draw->draw1[1].x = position->x - data->pos_dessin.x + 1;
  draw->draw1[1].y = position->y - data->pos_dessin.y;
  draw->draw2[1].x = position->x - data->pos_dessin.x - 1;
  draw->draw2[1].y = position->y - data->pos_dessin.y;
  draw->draw3[1].x = position->x - data->pos_dessin.x;
  draw->draw3[1].y = position->y - data->pos_dessin.y - 1;
  draw->draw4[1].x = position->x - data->pos_dessin.x;
  draw->draw4[1].y = position->y - data->pos_dessin.y + 1;
}

static void square_line(t_main_data *data, t_draw_position *draw)
{
  std_set_line(data->dessin, draw->draw1, data->color);
  std_set_line(data->dessin, draw->draw2, data->color);
  std_set_line(data->dessin, draw->draw3, data->color);
  std_set_line(data->dessin, draw->draw4, data->color);
}

void stylo(t_main_data *data)
{
  t_draw_position draw;
  const t_bunny_position *position = bunny_get_mouse_position();

  if (data->check == false)
  {
    data->temp[0] = *position;
    data->temp[1] = *position;
    std_blit(data->tmp_px, data->dessin, NULL);
  }
  if (data->check == false && data->trigger == 1)
  {
    data->trigger = 0;
    data->saved_px = false;
  }
  if (bunny_get_mouse_button()[BMB_LEFT] && data->check == true)
  {
    data->trigger = 1;
    if (data->i % 2 == 0)
    {
      draw_init_1(data, &draw, position);
      if (!draw_zone())
        return;
    }
    else
    {
      draw_init_2(data, &draw, position);
      if (!draw_zone())
        return;
    }
    std_set_line(data->dessin, draw.draw, data->color);
    if (data->square_draw)
      square_line(data, &draw);
    data->i++;
  }
}
