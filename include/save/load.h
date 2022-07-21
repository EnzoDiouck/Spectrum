#ifndef __LOAD_H__
#define __LOAD_H__

#include "struct.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "atoi.h"

void load(t_main_data *data,
          char *file_name);

#endif /* __LOAD_H__ */
