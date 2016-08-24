/*
** another_tab.c for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/srcs
** 
** Made by maxime ancellin
** Login   <ancell_m@epitech.net>
** 
** Started on  Sun Apr 24 22:59:52 2016 maxime ancellin
** Last update Sun Apr 24 22:59:54 2016 maxime ancellin
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	check_tab(int *tab)
{
  int		i;

  i = 0;
  while (tab[i] != -1)
    i++;
  return (i);
}

static int	**init_tab(t_int_tab *data)
{
  int		i;
  int		**tab;

  if ((tab = malloc(sizeof(int *) * data->len + 30)) == NULL)
    return (NULL);
  i = 0;
  while (data->tab[i])
    {
      tab[i] = malloc(sizeof(int) * check_tab(data->tab[i]) + 40);
      i++;
    }
  return (tab);
}

static void	inita_var(int *i, int *j, int d)
{
  if (d == 1)
    {
      *i = 0;
      *j =0;
    }
  else
    {
      *i = *i + 1;
      *j = *j + 1;
    }
}

static int	check_in_tab(int *tab, int u)
{
  int		i;

  i = 0;
  while (tab[i] != -1)
    {
      if (tab[i] == u)
	return (0);
      i++;
    }
  return (1);
}

int		**another_tab(int *tab, t_int_tab *ro)
{
  int		**tabl;
  t_data	da;

  inita_var(&da.i, &da.r, 1);
  tabl = init_tab(ro);
  while (ro->tab[da.i])
    {
      inita_var(&da.u, &da.k, 1);
      if (check_in_tab(tab, da.i) == 0)
	da.i++;
      while (ro->tab[da.i][da.u] != -1)
	{
	  if (check_in_tab(tab, ro->tab[da.i][da.u]) == 0)
	    da.u++;
	  else
	    {
	      tabl[da.r][da.k] = ro->tab[da.i][da.u];
	      inita_var(&da.u, &da.k, 2);
	    }
	}
      tabl[da.r][da.k] = -1;
      inita_var(&da.i, &da.r, 2);
    }
  tabl[da.r] = NULL;
  return (tabl);
}
