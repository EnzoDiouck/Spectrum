#include "spectrum.h"

static void point_one(t_main_data *data, t_bunny_position *draw, const t_bunny_position *pos, t_bunny_position *tmp)
{
  (void)data;
  draw[0].x = tmp[0].x - data->pos_dessin.x;
  draw[0].y = tmp[0].y - data->pos_dessin.y;
  draw[1].x = pos->x - data->pos_dessin.x;
  draw[1].y = pos->y - data->pos_dessin.y;
}

static void square_line(t_main_data *data, t_bunny_position *draw, t_bunny_position centre)
{
  std_set_circle(data->dessin, centre, data->color, (draw[1].x - draw[0].x) / 2 + 1, (draw[1].y - draw[0].y) / 2);
  std_set_circle(data->dessin, centre, data->color, (draw[1].x - draw[0].x) / 2, (draw[1].y - draw[0].y) / 2 + 1);
  std_set_circle(data->dessin, centre, data->color, (draw[1].x - draw[0].x) / 2 - 1, (draw[1].y - draw[0].y) / 2);
  std_set_circle(data->dessin, centre, data->color, (draw[1].x - draw[0].x) / 2, (draw[1].y - draw[0].y) / 2 - 1);
}

void circle(t_main_data *data)
{
  const t_bunny_position *pos = bunny_get_mouse_position();
  t_bunny_position draw[2];
  t_bunny_position centre;
  if (data->check == false)
  {
    data->temp[0] = *pos;
    data->temp[1] = *pos;
    std_blit(data->tmp_px, data->dessin, NULL);
  }
  if (data->check == false && data->trigger == 1)
  {
    data->trigger = 0;
    data->saved_px = false;
  }
  if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
  {
    data->trigger = 1;
    point_one(data, draw, pos, data->temp);
    std_blit(data->dessin, data->tmp_px, NULL);
    centre.x = draw[0].x + ((draw[1].x - draw[0].x) / 2);
    centre.y = draw[0].y + ((draw[1].y - draw[0].y) / 2);
    std_set_circle(data->dessin, centre, data->color, (draw[1].x - draw[0].x) / 2, (draw[1].y - draw[0].y) / 2);
    if (data->square_draw)
      square_line(data, draw, centre);
  }
}
