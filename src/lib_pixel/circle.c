
#include "spectrum.h"

void std_set_circle(t_bunny_pixelarray *px,
                    t_bunny_position pos,
                    unsigned int color,
                    int width,
                    int height)
{
  double tour;
  t_bunny_position posc[2];

  posc[0] = pos;
  tour = 0.0;
  while (tour < 2 * M_PI)
  {
    posc[1].x = width * cos(tour) + pos.x;
    posc[1].y = height * sin(tour) + pos.y;
    std_set_pixel(px, posc[1], color);
    tour += M_PI / 2048;
  }
}
