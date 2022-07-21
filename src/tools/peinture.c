#include "spectrum.h"

static void loop_color(t_bunny_position pos, t_main_data *data)
{
  unsigned int *pixel;
  int width;

  width = data->dessin->clipable.buffer.width;
  pixel = data->dessin->pixels;
  if (pixel[width * pos.y + pos.x + 1] == data->verif_color)
  {
    if (pos.x < width)
    {
      pos.x++;
      pixel[pos.y * width + pos.x] = data->color;
      loop_color(pos, data);
    }
  }
  if (pixel[width * pos.y + pos.x - 1] == data->verif_color)
  {
    if (pos.x > 0)
    {
      pos.x--;
      pixel[pos.y * width + pos.x] = data->color;
      loop_color(pos, data);
    }
  }
  if (pixel[width * (pos.y + 1) + pos.x] == data->verif_color)
  {
    if (pos.y < data->dessin->clipable.buffer.height)
    {
      pos.y++;
      pixel[pos.y * width + pos.x] = data->color;
      loop_color(pos, data);
    }
  }
  if (pixel[width * (pos.y - 1) + pos.x] == data->verif_color)
  {
    if (pos.y > 0)
    {
      pos.y--;
      pixel[pos.y * width + pos.x] = data->color;
      loop_color(pos, data);
    }
  }
}

void peinture(t_main_data *data)
{
  const t_bunny_position *position;
  t_bunny_position pos;

  position = bunny_get_mouse_position();
  pos.x = position->x - data->pos_dessin.x;
  pos.y = position->y - data->pos_dessin.y;
  if (data->check == true)
  {
    data->verif_color = get_pixel(data->dessin, pos);
    if (data->verif_color != data->color)
      loop_color(pos, data);
    data->check = false;
    data->saved_px = false;
  }
}
