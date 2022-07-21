#include "spectrum.h"

void std_bunny_clear(t_bunny_pixelarray *px, unsigned int color)
{
  int j;
  int *pixel;

  j = 0;
  pixel = px->pixels;
  while (j < px->clipable.buffer.width * px->clipable.buffer.height)
  {
    pixel[j] = color;
    j++;
  }
}
