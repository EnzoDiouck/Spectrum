#include "load.h"
#include <stdio.h>

static char *
verif_name (char *file_name)
{
  int comp;
  char *str;

  str = malloc (sizeof (char) * 256);
  if (!str)
    return (NULL);
  comp = 0;
  while (file_name[comp] != 0)
    {
      if (file_name[comp] == '.' && file_name[comp + 1] == 'p'
          && file_name[comp + 2] == 'n' && file_name[comp + 3] == 't'
          && open (file_name, O_RDONLY) != -1)
        return file_name;
      comp++;
    }
  if (!write (1, "write a valide file name with .pnt extension\n", 46))
    return (NULL);
  comp = read (0, str, 256);
  str[comp - 1] = '\0';
  return (verif_name (str));
}

void
load (t_main_data *data, char *file_name)
{
  int i = 0, i_tmp = i, load = 0;
  int fd;
  int count;
  int compteur;
  char temp;
  int *pixel;
  int comp;
  char *color;

  count = 1;
  compteur = 0;
  comp = 0;
  file_name = verif_name (file_name);
  fd = open (file_name, O_RDONLY);
  if (fd == -1)
    return;
  color = malloc (sizeof (char) * 20);
  if (color == NULL)
    return;
  pixel = data->dessin->pixels;
  if (!write (1, "Loading\n", 9) || !write (1, "[ . . . . . . ]", 16))
    return;
  while (count != 0)
    {
      count = read (fd, &temp, 1);
      if (temp == ',')
        {
          i++;
          color[comp] = '\0';
          pixel[compteur] = std_negatoi (color);
          if (!read (fd, &temp, 1))
            break;
          comp = 0;
          compteur++;
          free (color);
          color = malloc (sizeof (char) * 20);
          if (color == NULL)
            return;
          if (i == i_tmp + 50000)
            {
              i_tmp = i;
              if (load == 0)
                {
                  if (!write (1, "\r[ * . . . . . ]", 17))
                    return;
                  load = 20;
                }
              else if (load == 20)
                {
                  if (!write (1, "\r[ * * . . . . ]", 17))
                    return;
                  load = 40;
                }
              else if (load == 40)
                {
                  if (!write (1, "\r[ * * * . . . ]", 17))
                    return;
                  load = 60;
                }
              else if (load == 60)
                {
                  if (!write (1, "\r[ * * * * . . ]", 17))
                    return;
                  load = 80;
                }
              else if (load == 80)
                {
                  if (!write (1, "\r[ * * * * * . ]", 17))
                    return;
                  load = 100;
                }
            }
        }
      color[comp] = temp;
      comp++;
    }
  if (!write (1, "\r[ * * * * * * ]", 17))
    return;
  // free(color);
  close (fd);
  if (!write (1, "\rPicture loaded  \n", 19))
    return;
}
