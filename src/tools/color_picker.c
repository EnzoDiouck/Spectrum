/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-09 10:50:46
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-09 10:51:07
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#include "color_picker.h"

void color_picker(t_main_data *data)
{
    const t_bunny_position *pos = bunny_get_mouse_position();
    t_bunny_position origin, color;

    origin.x = 720;
    origin.y = 100;
    if (pos->x >= 720 && pos->y >= 100 && pos->x <= data->px->clipable.buffer.width && pos->y <= data->px->clipable.buffer.height)
    {
        if (!data->check)
        {
            color.x = pos->x - origin.x;
            color.y = pos->y - origin.y;
        }
        if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
        {
            color.x = pos->x - origin.x;
            color.y = pos->y - origin.y;
	    data->save_color = get_pixel(data->rgb, color);
	    if (data->greyed == true)
	      {
		t_bunny_color color_grey, pixelColor;
		unsigned int grey_color;

		pixelColor.full = get_pixel(data->rgb, color);
		grey_color = (pixelColor.argb[RED_CMP] + pixelColor.argb[BLUE_CMP] + pixelColor.argb[GREEN_CMP]) / 3;
		color_grey.argb[RED_CMP] = grey_color;
		color_grey.argb[BLUE_CMP] = grey_color;
		color_grey.argb[GREEN_CMP] = grey_color;
		data->color = color_grey.full;
	      }
	      else if (data->reversed == false)
                data->color = get_pixel(data->rgb, color);
	      else
                data->color = 0xFFFFFF - get_pixel(data->rgb, color);
        }
    }
}
