#include "spectrum.h"

void color(t_main_data *data)
{
  if (bunny_get_keyboard()[BKS_F1])
    data->color = BLACK;
  if (bunny_get_keyboard()[BKS_F2])
    data->color = WHITE;
  if (bunny_get_keyboard()[BKS_F3])
    data->color = RED;
  if (bunny_get_keyboard()[BKS_F4])
    data->color = BLUE;
  if (bunny_get_keyboard()[BKS_F5])
    data->color = GREEN;
  if (bunny_get_keyboard()[BKS_F6])
    data->color = YELLOW;
  if (bunny_get_keyboard()[BKS_F7])
    data->color = TEAL;
  if (bunny_get_keyboard()[BKS_F8])
    data->color = PINK;
}
