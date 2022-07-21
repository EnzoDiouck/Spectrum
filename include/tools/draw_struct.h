/**
 * @ Author: Your name
 * @ Create Time: 2022-03-11 10:28:07
 * @ Modified by: Your name
 * @ Modified time: 2022-03-11 10:29:54
 * @ Copyright: Antoine ROSPARS - All Rights Reserved - 2022
 */

#ifndef __SDRAW_H__
#define __SDRAW_H__

#include <lapin.h>

typedef struct s_draw_position
{
    t_bunny_position draw[2];
    t_bunny_position draw1[2];
    t_bunny_position draw2[2];
    t_bunny_position draw3[2];
    t_bunny_position draw4[2];
} t_draw_position;
#endif /* __SDRAW_H__ */