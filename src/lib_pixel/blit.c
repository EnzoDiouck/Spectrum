/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-08 15:49:32
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-09 10:51:14
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#include "spectrum.h"
#include "blit.h"

void std_blit(t_bunny_pixelarray *target, const t_bunny_pixelarray *src, const t_bunny_position *pos)
{
    t_bunny_position clip, posSet;

    if (!pos)
    {
        clip.x = 0;
        clip.y = 0;
        while (clip.y <= src->clipable.buffer.height)
        {
            clip.x = 0;
            while (clip.x <= src->clipable.buffer.width)
            {
                std_set_pixel(target, clip, get_pixel(src, clip));
                clip.x++;
            }
            clip.y++;
        }
    }
    else
    {
        clip.x = pos->x;
        clip.y = pos->y;
        posSet.x = 0;
        posSet.y = 0;
        while (posSet.y <= src->clipable.buffer.height)
        {
            posSet.x = 0;
            clip.x = pos->x;
            while (posSet.x <= src->clipable.buffer.width)
            {
                std_set_pixel(target, clip, get_pixel(src, posSet));
                clip.x++;
                posSet.x++;
            }
            clip.y++;
            posSet.y++;
        }
    }
}
