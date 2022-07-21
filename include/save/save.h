#ifndef __SAVE_H__
#define __SAVE_H__

#include "struct.h"
#include "printbase10.h"
#include "itoa.h"
#include "get_pixel.h"
#include <unistd.h>
#include <fcntl.h>

void save(t_main_data *data,
	  char *file_name);

#endif /* __SAVE_H__ */
