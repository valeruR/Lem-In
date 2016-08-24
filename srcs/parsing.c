/*
** parsing.c for parsing in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/srcs
**
** Made by maxime ancellin
** Login   <ancell_m@PC-Ubuntech-NEO>
**
** Started on  Sun Apr 24 21:40:11 2016 maxime ancellin
** Last update Sun Apr 24 21:44:32 2016 maxime ancellin
*/

#include "lemin.h"

int	check_input(char *str, t_info *info)
{
  if (check_rooms(str) == 0)
    {
      if (set_for_rooms(info, str) != 0)
	return (-1);
    }
  else if (check_links(str) == 0)
    {
      if (set_for_links(info, str) != 0)
	return (-1);
    }
  else
    info->error = 1;
  return (0);
}
