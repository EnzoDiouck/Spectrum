#include "inverse.h"

void inverse(t_bunny_pixelarray *px)
{
  int j;
  int *pixel;

  j = 0;
  pixel = px->pixels;
  while (j < px->clipable.buffer.width * px->clipable.buffer.height)
  {
    pixel[j] = 0xFFFFFF - pixel[j];
    j++;
  }
}
