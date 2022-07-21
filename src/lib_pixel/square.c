/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-08 15:49:32
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-08 16:26:06
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#include "square.h"

void std_square(t_bunny_pixelarray *px, t_bunny_position *pos, unsigned int color)
{
    t_bunny_position draw[2];
    t_bunny_position drawBot;

    draw[0].x = pos[0].x;
    draw[0].y = pos[0].y;
    draw[1].x = pos[1].x;
    draw[1].y = pos[0].y;
    std_set_line(px, draw, color);
    drawBot.x = draw[1].x;
    drawBot.y = draw[1].y;
    draw[0].x = drawBot.x;
    draw[0].y = drawBot.y;
    draw[1].x = pos[1].x;
    draw[1].y = pos[1].y;
    std_set_line(px, draw, color);
    draw[0].x = pos[0].x;
    draw[0].y = pos[0].y;
    draw[1].x = pos[0].x;
    draw[1].y = pos[1].y;
    std_set_line(px, draw, color);
    drawBot.x = draw[1].x;
    drawBot.y = draw[1].y;
    draw[0].x = drawBot.x;
    draw[0].y = drawBot.y;
    draw[1].x = pos[1].x;
    draw[1].y = pos[1].y;
    std_set_line(px, draw, color);
}