#include "save.h"
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
          && file_name[comp + 2] == 'n' && file_name[comp + 3] == 't')
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
save (t_main_data *data, char *file_name)
{
  int l = 0, i_tmp = l, load = 0;
  int fd;
  int i;
  char *color;
  t_bunny_position pos;

  file_name = verif_name (file_name);
  fd = open (file_name, O_CREAT | O_TRUNC | O_WRONLY, 00700);
  if (fd == -1)
    return;
  color = bunny_malloc (sizeof (char) * 20);
  if (color == NULL)
    return;
  pos.x = 0;
  pos.y = 0;
  i = 0;
  if (!write (1, "Loading\n", 9) || !write (1, "[ . . . . . . ]", 16))
    return;
  while (i < data->dessin->clipable.buffer.width
                 * data->dessin->clipable.buffer.height)
    {
      if (pos.x == data->dessin->clipable.buffer.width)
        {
          pos.y++;
          pos.x = 0;
        }
      color = std_strcpy (color,
                          std_print_base10 (get_pixel (data->dessin, pos)));
      if (!write (fd, color, std_strlen (color)) || !write (fd, ",", 1))
        return;
      else
        l++;
      if (l == i_tmp + 50000)
        {
          i_tmp = l;
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
      pos.x++;
      i++;
    }
  close (fd);
  if (!write (1, "\r[ * * * * * * ]", 17))
    return;
  // bunny_free(color);
  if (!write (1, "\rPicture saved   \n", 19))
    return;
  return;
}
