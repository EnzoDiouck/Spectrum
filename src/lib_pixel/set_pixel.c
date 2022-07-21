#include "spectrum.h"

void std_set_pixel(t_bunny_pixelarray *px,
                   t_bunny_position pos,
                   unsigned int color)
{
  int *pixel;

  pixel = px->pixels;
  if(pos.x >= 0 && pos.x < px->clipable.buffer.width &&
     pos.y >= 0 && pos.y < px->clipable.buffer.height)
  pixel[px->clipable.buffer.width * pos.y + pos.x] = color;
}
