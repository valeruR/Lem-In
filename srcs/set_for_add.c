/*
** set_for_add.c for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/srcs
**
** Made by maxime ancellin
** Login   <ancell_m@epitech.net>
**
** Started on  Fri Apr 15 14:47:29 2016 maxime ancellin
** Last update Sun Apr 24 22:38:49 2016 Reever Valerus
*/

#include <stdlib.h>
#include "my.h"
#include "lemin.h"
#include "get_next_line.h"

int	init_struct(t_info *info)
{
  info->error = 0;
  info->ants = 0;
  info->start = NULL;
  info->end = NULL;
  info->rooms = NULL;
  info->links = NULL;
  return (0);
}

int	set_for_rooms(t_info *info, char *str)
 {
  char	*tmp;
  int	i;

  i = my_strlen_char(str, ' ');
  if ((tmp = malloc(sizeof(char) * (i + 1))) == NULL)
    return (-1);
  i = 0;
  while (str[i] != ' ')
    {
      tmp[i] = str[i];
      ++i;
    }
  tmp[i] = 0;
  if ((info->rooms = realloc_tab(info->rooms, tmp)) == NULL)
    return (-1);
  return (0);
}

int	set_for_links(t_info *info, char *str)
{
  t_data	da;

  da.u = 0;
  da.i = my_strlen_char(str, '-');
  if ((da.s = malloc(sizeof(char) * (da.i + 1))) == NULL)
    return (-1);
  da.i = 0;
  while (str[da.i] != '-')
    {
      da.s[da.i] = str[da.i];
      ++da.i;
    }
  da.s[da.i] = 0;
  if ((da.t = malloc(sizeof(char) * (my_strlen(str) - my_strlen_char(str ,'-')
				     + 1))) == NULL)
    return (-1);
  while (str[da.i++] != 0)
    {
      da.t[da.u] = str[da.i];
      ++da.u;
    }
  da.t[da.u] = 0;
  if ((info->links = realloc_links(info->links, da.s, da.t)) == NULL)
    return (-1);
  return (0);
}

void	set_for_start(t_info *info)
{
  char	*str;

  if (info->start == NULL)
    while (info->start == NULL)
      {
	str = epur_str(get_next_line(0));
	if (str[0] != '#')
	  {
	    info->start = str;
	    if (check_rooms(str) == 0)
	      set_for_rooms(info, str);
	    else
	      info->error = 1;
	  }
	else if (str[0] == '#' && str[1] == '#')
	  info->error = 1;
	if (info->error == 0)
	  {
	    my_putstr(str);
	    my_putchar('\n');
	  }
      }
  else
    info->error = 1;
}

void	set_for_end(t_info *info)
{
  char	*str;

  if (info->end == NULL)
    while (info->end == NULL)
      {
	str = epur_str(get_next_line(0));
	if (str[0] != '#')
	  {
	    info->end = str;
	    if (check_rooms(str) == 0)
	      set_for_rooms(info, str);
	    else
	      info->error = 1;
	  }
	else if (str[0] == '#' && str[1] == '#')
	  info->error = 1;
	if (info->error == 0)
	  {
	    my_putstr(str);
	    my_putchar('\n');
	  }
      }
  else
    info->error = 1;
}
