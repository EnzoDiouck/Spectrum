#include "clear_pixelarray.h"
#include "inverse.h"
#include "spectrum.h"
#include <stdio.h>

t_bunny_response
loop_function (void *d)
{
  t_main_data *data = (t_main_data *)d;
  t_bunny_position temp_bordure[2];

  if (draw_zone ())
    {
      if (data->chose == BRUSH)
        stylo (data);
      else if (data->chose == BUCKET)
        peinture (data);
      else if (data->chose == LINE)
        straight_line (data);
      else if (data->chose == RECTANGLE)
        rectangle (data);
      else if (data->chose == RECTANGLENF)
        rectangle_not_full (data);
      else if (data->chose == CIRCLE)
        circle (data);
    }
  else if (!draw_zone ())
    {
      button (data);
      color_picker (data);
    }
  if (data->saved_px == false)
    {
      std_stack_push (&data->stk, data->dessin);
      data->saved_px = true;
    }
  std_bunny_clear (data->px, data->color);
  temp_bordure[0].x = data->pos_dessin.x - 1;
  temp_bordure[0].y = data->pos_dessin.y - 1;
  temp_bordure[1].x = 700;
  temp_bordure[1].y = 590;
  std_square (data->px, temp_bordure, 0xFFFFFF - data->color);
  std_display_gui (data->gui, data->px);
  bunny_blit (&data->win->buffer, &data->px->clipable, NULL);
  bunny_blit (&data->win->buffer, &data->rgb->clipable, &data->pos_rgb);
  bunny_blit (&data->win->buffer, &data->dessin->clipable, &data->pos_dessin);
  bunny_display (data->win);
  return (GO_ON);
}

t_bunny_response
click_event_response (t_bunny_event_state state, t_bunny_mouse_button button,
                      void *d)
{
  t_main_data *data = (t_main_data *)d;

  if (state == GO_DOWN && button == BMB_LEFT)
    data->check = true;
  else
    data->check = false;
  return (GO_ON);
}

t_bunny_response
move_event_response (const t_bunny_position *relative, void *d)
{
  (void)relative;
  (void)d;
  return (GO_ON);
}

t_bunny_response
key_event_response (t_bunny_event_state state, t_bunny_keysym button, void *d)
{
  t_main_data *data = (t_main_data *)d;

  if (state == GO_DOWN && button == BKS_ESCAPE)
    return (EXIT_SUCCESS);
  if (state == GO_DOWN && button == BKS_I)
    {
      inverse (data->dessin);
      if (data->reversed == false)
        {
          data->reversed = true;
          data->color = 0xFFFFFF - data->color;
        }
      else
        {
          data->reversed = false;
          data->color = 0xFFFFFF - data->color;
        }
      std_display_gui (data->gui, data->px);
      bunny_blit (&data->win->buffer, &data->dessin->clipable,
                  &data->pos_dessin);
      bunny_blit (&data->win->buffer, &data->rgb->clipable, &data->pos_rgb);
      bunny_display (data->win);
    }
  if (state == GO_DOWN && button == BKS_J)
    {
      grey (data->dessin);
      std_display_gui (data->gui, data->px);
      bunny_blit (&data->win->buffer, &data->dessin->clipable,
                  &data->pos_dessin);
      bunny_blit (&data->win->buffer, &data->rgb->clipable, &data->pos_rgb);
      bunny_display (data->win);
    }
  if (state == GO_DOWN && bunny_get_keyboard ()[BKS_LCONTROL]
      && bunny_get_keyboard ()[BKS_Z])
    {
      if (data->stk->next_stk != NULL)
        {
          std_stack_pop (&data->stk);
          std_blit (data->dessin, data->stk->data, NULL);
        }
      state = GO_UP;
    }
  return (GO_ON);
}

int
main ()
{
  t_main_data main_data;
  t_bunny_position temp_bordure[2];

  if ((main_data.win = bunny_start (810, 610, false, "SPECTRUM")) == NULL)
    return (EXIT_FAILURE);
  main_data.px = bunny_new_pixelarray (main_data.win->buffer.width,
                                       main_data.win->buffer.height);

  main_data.dessin = bunny_new_pixelarray (680, 490);
  main_data.tmp_px = bunny_new_pixelarray (680, 490);
  main_data.undo = bunny_new_pixelarray (680, 490);
  main_data.rgb = bunny_load_pixelarray ("assets/rgb.png");
  main_data.rgb->clipable.scale.x = 0.25;
  main_data.rgb->clipable.scale.y = 0.8;
  main_data.pos_rgb.x = 720;
  main_data.pos_rgb.y = 100;

  main_data.gui = std_new_gui ("ui.json");
  main_data.stk = NULL;

  main_data.pos_dessin.x = 20;
  main_data.pos_dessin.y = 100;
  main_data.verif_color = WHITE;
  main_data.i = 2;
  main_data.temp[0].x = 0;
  main_data.temp[0].y = 0;
  main_data.temp[1].x = 0;
  main_data.temp[1].y = 0;
  main_data.trigger = 0;
  main_data.check = false;
  main_data.square_draw = true;
  main_data.color = BLACK;
  main_data.save_color = BLACK;
  main_data.chose = BRUSH;
  main_data.reversed = false;
  main_data.greyed = false;
  main_data.saved_px = false;
  std_bunny_clear (main_data.px, main_data.color);
  std_bunny_clear (main_data.dessin, WHITE);
  temp_bordure[0].x = main_data.pos_dessin.x - 1;
  temp_bordure[0].y = main_data.pos_dessin.y - 1;
  temp_bordure[1].x = 680 + 1;
  temp_bordure[1].y = 490 + 1;
  std_square (main_data.px, temp_bordure, 0xFFFFFF - main_data.color);
  bunny_blit (&main_data.win->buffer, &main_data.px->clipable, NULL);
  bunny_blit (&main_data.win->buffer, &main_data.rgb->clipable,
              &main_data.pos_rgb);
  bunny_blit (&main_data.win->buffer, &main_data.dessin->clipable,
              &main_data.pos_dessin);
  bunny_display (main_data.win);

  bunny_set_key_response (key_event_response);

  bunny_set_move_response (move_event_response);

  bunny_set_click_response (click_event_response);

  bunny_set_loop_main_function (loop_function);

  if (bunny_loop (main_data.win, 60, &main_data) == EXIT_ON_ERROR)
    return (EXIT_FAILURE);

  bunny_stop (main_data.win);

  std_stack_clear (&main_data.stk);

  return (EXIT_SUCCESS);
}
