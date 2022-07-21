/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-09 16:23:50
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-09 16:23:51
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#include "draw_zone.h"

bool draw_zone(void)
{
    const t_bunny_position *pos = bunny_get_mouse_position();

    if (pos->x >= 20 && pos->x <= 20 + 680 && pos->y >= 100 && pos->y <= 100 + 490)
        return (true);
    return (false);
}