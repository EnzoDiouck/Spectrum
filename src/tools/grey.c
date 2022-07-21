/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-09 16:12:13
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-09 16:12:14
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#include "grey.h"

void grey(t_bunny_pixelarray *px)
{
    t_bunny_color color, pixelColor;
    int j = 0;
    unsigned int *pixel, grey;

    pixel = px->pixels;
    while (j < px->clipable.buffer.width * px->clipable.buffer.height)
    {
        pixelColor.full = pixel[j];
        grey = (pixelColor.argb[RED_CMP] + pixelColor.argb[BLUE_CMP] + pixelColor.argb[GREEN_CMP]) / 3;
        color.argb[RED_CMP] = grey;
        color.argb[BLUE_CMP] = grey;
        color.argb[GREEN_CMP] = grey;
        pixel[j] = color.full;
        j++;
    }
}