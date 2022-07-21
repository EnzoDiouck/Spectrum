/*
** @ Author: antoine.rospars@ecole-89.com
** @ Create Time: 2022-02-26 18:05:53
** @ Modified by: Antoine ROSPARS
** @ Modified time: 2022-02-27 18:43:45
** @ Copyright: 2022 © Antoine ROSPARS, All Rights Reserved.
*/

#ifndef __KEYFUNCTION_H__
#define __KEYFUNCTION_H__

#include <lapin.h>

t_bunny_response key_function(t_bunny_event_state state, t_bunny_keysym keycode, void *d);

#endif /* __KEYFUNCTION_H__ */