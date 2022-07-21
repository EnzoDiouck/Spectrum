#include "spectrum.h"

void chose(t_main_data *data)
{
  if (bunny_get_keyboard()[BKS_1])
    data->chose = BRUSH;
  else if (bunny_get_keyboard()[BKS_2])
    data->chose = BUCKET;
  else if (bunny_get_keyboard()[BKS_3])
    data->chose = LINE;
  else if (bunny_get_keyboard()[BKS_5])
    data->chose = RECTANGLE;
  else if (bunny_get_keyboard()[BKS_SPACE])
    data->chose = RECTANGLENF;
  else if (bunny_get_keyboard()[BKS_7])
    data->chose = CIRCLE;
}
