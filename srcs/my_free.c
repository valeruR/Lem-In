/*
** my_free.c for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/srcs
**
** Made by maxime ancellin
** Login   <ancell_m@epitech.net>
**
** Started on  Tue Apr 19 16:09:36 2016 maxime ancellin
** Last update Mon Apr 25 12:08:32 2016 maxime ancellin
*/

#include <unistd.h>
#include <stdlib.h>
#include "lemin.h"

void	free_simple_tab(char **tab)
{
  int	i;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  ++i;
	}
      free(tab);
    }
}

void	free_complex_tab(char ***tab)
{
  int	i;
  int	j;

  i = 0;
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  j = 0;
	  while (tab[i][j] != NULL)
	    {
	      free(tab[i][j]);
	      ++j;
	    }
	  free(tab[i]);
	  ++i;
	}
      free(tab);
    }
}

void	free_all(t_info *info)
{
  free(info->start);
  free(info->end);
  free_simple_tab(info->rooms);
  free_complex_tab(info->links);
}
