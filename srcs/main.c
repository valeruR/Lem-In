/*
** main.c for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin
**
** Made by maxime ancellin
** Login   <ancell_m@epitech.net>
**
** Started on  Tue Apr 12 14:47:11 2016 maxime ancellin
** Last update Mon Apr 25 12:06:11 2016 maxime ancellin
*/

#include <unistd.h>
#include "get_next_line.h"
#include "my.h"
#include "lemin.h"

int	check_rooms(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (str[i] == ' ')
	++count;
      ++i;
    }
  if (count != 2)
    return (-1);
  else
    return (0);
}

int	check_links(char *str)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  while (str[i] != 0)
    {
      if (str[i] == '-')
	++count;
      ++i;
    }
  i = 0;
  if (count == 1)
    {
      while (str[i] != 0 && str[i] != '-')
	++i;
      if (str[i] == '-' && str[i + 1] != 0 && i != 0)
	return (0);
    }
  return (-1);
}

static void	function_comment(t_info *info, char *str)
{
  if (my_strcmp(str, "##start") == 0 || my_strcmp(str, "##end") == 0)
    {
      if (my_strcmp(str, "##start") == 0)
	set_for_start(info);
      else
	set_for_end(info);
    }
  else if (str[0] == '#' && str[1] == '#')
    my_putstr(str);
}

static int	parsing(t_info *info)
{
  char		*str;

  while ((str = get_next_line(0)) && info->error == 0)
    {
      str = epur_str(str);
      if (str[0] == '#' && str[1] == '#')
	function_comment(info, str);
      else if (my_getnbr(str) > 0 && str[0] != '#' &&
	       info->ants == 0)
	info->ants = my_getnbr(str);
      else if (str[0] != '#')
	if (check_input(str, info) == -1)
	  return (-1);
      if (info->error == 0)
	{
	  my_putstr(str);
	  my_putchar('\n');
	}
    }
  if (info->error != 0)
    return (-1);
  if (check_double_elem(info->rooms) == -1)
    info->error = 3;
  return (0);
}

int		main()
{
  t_info	info;
  t_int_tab	dat;
  int		**path;

  if ((init_struct(&info)) == -1 || parsing(&info) != 0)
    info.error = 1;
  else if (info.error == 0 && (info.start != NULL || info.end != NULL) && info.links != NULL)
    {
      your_tab_sir(&info, &dat);
      path = init(dat.len, val_room(info.rooms, info.start));
      finding(dat.tab, path, val_room(info.rooms, info.end));
      dispanou(path, val_room(info.rooms, info.end), info.ants, info);
    }
  else
    {
      free_all(&info);
      return (-1);
    }
  free_all(&info);
  return (0);
}
