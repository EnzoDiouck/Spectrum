#include "spectrum.h"
#include "draw_struct.h"
#include <stdio.h>

static void point_one(t_main_data *data, t_draw_position *draw, const t_bunny_position *pos, t_bunny_position *tmp)
{
    draw->draw[0].x = tmp[0].x - data->pos_dessin.x;
    draw->draw[0].y = tmp[0].y - data->pos_dessin.y;
    draw->draw[1].x = pos->x - data->pos_dessin.x;
    draw->draw[1].y = pos->y - data->pos_dessin.y;
    draw->draw1[0].x = tmp[0].x - data->pos_dessin.x + 1;
    draw->draw1[0].y = tmp[0].y - data->pos_dessin.y;
    draw->draw1[1].x = pos->x - data->pos_dessin.x + 1;
    draw->draw1[1].y = pos->y - data->pos_dessin.y;
    draw->draw2[0].x = tmp[0].x - data->pos_dessin.x - 1;
    draw->draw2[0].y = tmp[0].y - data->pos_dessin.y;
    draw->draw2[1].x = pos->x - data->pos_dessin.x - 1;
    draw->draw2[1].y = pos->y - data->pos_dessin.y;
    draw->draw3[0].x = tmp[0].x - data->pos_dessin.x;
    draw->draw3[0].y = tmp[0].y - data->pos_dessin.y + 1;
    draw->draw3[1].x = pos->x - data->pos_dessin.x;
    draw->draw3[1].y = pos->y - data->pos_dessin.y + 1;
    draw->draw4[0].x = tmp[0].x - data->pos_dessin.x;
    draw->draw4[0].y = tmp[0].y - data->pos_dessin.y - 1;
    draw->draw4[1].x = pos->x - data->pos_dessin.x;
    draw->draw4[1].y = pos->y - data->pos_dessin.y - 1;
}

static void square_line(t_main_data *data, t_draw_position *draw)
{
    std_square(data->dessin, draw->draw1, data->color);
    std_square(data->dessin, draw->draw2, data->color);
    std_square(data->dessin, draw->draw3, data->color);
    std_square(data->dessin, draw->draw4, data->color);
}

void rectangle_not_full(t_main_data *data)
{
    t_draw_position draw;
    const t_bunny_position *pos = bunny_get_mouse_position();

    if (data->check == false)
    {
        data->temp[0] = *pos;
        data->temp[1] = *pos;
        std_blit(data->tmp_px, data->dessin, NULL);
    }
    if (data->check == false && data->trigger == 1)
    {
        data->trigger = 0;
        data->saved_px = false;
    }
    if (bunny_get_mouse_button()[BMB_LEFT] && data->check)
    {
        data->trigger = 1;
        point_one(data, &draw, pos, data->temp);
        std_blit(data->dessin, data->tmp_px, NULL);
        std_square(data->dessin, draw.draw, data->color);
        if (data->square_draw)
            square_line(data, &draw);
    }
}
