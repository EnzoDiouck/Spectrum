#include "spectrum.h"

void std_set_rectangle(t_bunny_pixelarray *px,
		   t_bunny_area area,
		   unsigned int color)
{
  t_bunny_position pos;
  pos.y = area.y;
  while (pos.y < area.y + area.h)
    {
      pos.x = area.x;
      while (pos.x < area.x + area.w)
        {
          std_set_pixel(px, pos, color);
          pos.x = pos.x + 1;
        }
      pos.y = pos.y + 1;
    }
}
