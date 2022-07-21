/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-03-04 10:51:24
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-03-04 10:51:26
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __CLICKEVENT_H__
#define __CLICKEVENT_H__

#include "struct_data.h"

t_bunny_response click_function(t_bunny_event_state state, t_bunny_mouse_button button, void *data);

#endif /* __CLICKEVENT_H__ */