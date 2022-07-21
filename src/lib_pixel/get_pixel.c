#include "spectrum.h"

unsigned int get_pixel(const t_bunny_pixelarray *px,
                       t_bunny_position pos)
{
  unsigned int *pixel;

  pixel = px->pixels;
  if (pos.x >= 0 && pos.x < px->clipable.buffer.width &&
      pos.y >= 0 && pos.y < px->clipable.buffer.height)
    return (pixel[px->clipable.buffer.width * pos.y + pos.x]);
  return (0);
}