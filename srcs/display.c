/*
** display.c for display in /home/blerio_h/Rendu/C_Elementary/Clone/CPE_2015_Lemin/srcs
**
** Made by Harold Blériot
** Login   <blerio_h@blerio-h-pc>
**
** Started on  Sat Apr 23 23:53:58 2016 Harold Blériot
** Last update Sun Apr 24 22:58:47 2016 maxime ancellin
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	int_len(int **path, int end)
{
  int		i;
  int		c;

  i = end;
  c = 1;
  while (i != path[i][1])
    {
      i = path[i][1];
      ++c;
    }
  return (c);
}

static int	path_len(int *path)
{
  int		i;

  i = 0;
  while (path[i] != -1)
    ++i;
  return (i);
}

static int	*my_path(int **path, int end)
{
  int		*pathou;
  int		i;
  int		j;

  i = end;
  j = 0;
  if ((pathou = malloc(sizeof(int) * (int_len(path, end) + 1))) == NULL)
    return (NULL);
  pathou[j++] = i;
  while (path[i][1] != i)
    {
      pathou[j++] = path[i][1];
      i = path[i][1];
    }
  pathou[j] = -1;
  pathou = my_revstr_int(pathou);
  return (pathou);
}

static int	printou(t_picsou data, int end, int total, t_info info)
{
  int		i;
  int		u;

  i = data.poutiz;
  u = 0;
  while (data.poutiz <= data.tours && data.poutiz <= total)
    {
      if (u != 0)
	my_putchar(' ');
      my_putchar('P');
      my_put_nbr(data.poutiz);
      my_putchar('-');
      my_putstr(info.rooms[data.path[data.tours - data.c]]);
      ++data.poutiz;
      if (data.path[data.tours - data.c] == end)
	i = data.poutiz;
      ++data.c;
      u++;
    }
  return (i);
}

void		dispanou(int **src, int end, int fourmiz, t_info info)
{
  t_picsou	data;

  data.path = my_path(src, end);
  data.tours = 1;
  data.poutiz = 1;
  data.h = 1;
  data.c = 0;
  while (data.poutiz <= fourmiz)
    {
      data.poutiz = printou(data, end, fourmiz, info);
      if (data.poutiz != data.h)
	  data.h = data.poutiz;
      if (++data.tours > path_len(data.path) - 1)
	++data.c;
      my_putchar('\n');
    }
}
