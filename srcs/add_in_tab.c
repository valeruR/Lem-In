/*
** add_in_tab.c for add_in_tab in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/srcs
**
** Made by maxime ancellin
** Login   <ancell_m@PC-Ubuntech-NEO>
**
** Started on  Wed Apr 13 09:48:09 2016 maxime ancellin
** Last update Mon Apr 25 15:40:45 2016 maxime ancellin
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

char	**realloc_tab(char **tab, char *input)
{
  char	**tmp;
  int	i;
  int	j;

  if ((tmp = malloc(sizeof(char *) * (my_tablen(tab) + 2))) == NULL)
    return (NULL);
  i = 0;
  if (tab != NULL)
    while (tab[i] != NULL)
      {
	j = -1;
	if ((tmp[i] = malloc(sizeof(char) * (my_strlen(tab[i]) + 1))) == NULL)
	  return (NULL);
	while (tab[i][++j] != 0)
	  tmp[i][j] = tab[i][j];
	tmp[i++][j] = 0;
      }
  if ((tmp[i] = malloc(sizeof(char) * (my_strlen(input) + 1))) == NULL)
    return (NULL);
  tmp[i] = input;
  tmp[i + 1] = NULL;
  if (tab != NULL)
    free_simple_tab(tab);
  return (tmp);
}

static int	links_cpy(char ***tab, char ***tmp, int i)
{
  t_data	da;

  while (tab[i] != NULL)
    {
      da.i = 0;
      if ((tmp[i] = malloc(sizeof(char *) * (my_tablen(tab[i]) + 2))) == NULL)
	return (-1);
      while (tab[i][da.i] != NULL)
	{
	  da.u = 0;
	  if ((tmp[i][da.i] = malloc(sizeof(char) * (my_strlen(tab[i][da.i])
						      + 1))) == NULL)
	    return (-1);
	  while (tab[i][da.i][da.u] != 0)
	    {
	      tmp[i][da.i][da.u] = tab[i][da.i][da.u];
	      ++da.u;
	    }
	  tmp[i][da.i][da.u] = 0;
	  ++da.i;
	}
      tmp[i][da.i] = NULL;
      ++i;
    }
  return (i);
}

char	***realloc_links(char ***tab, char *input1, char *input2)
{
  char	***tmp;
  int	i;

  if ((tmp = malloc(sizeof(char **) * (count_triplechar(tab) + 2))) == NULL)
    return (NULL);
  i = 0;
  if (tab != NULL)
    if ((i = links_cpy(tab, tmp, i)) == -1)
      return (NULL);
  tmp[i] = xmalloc(sizeof(char *) * 3);
  tmp[i][0] = input1;
  tmp[i][1] = input2;
  tmp[i][2] = NULL;
  tmp[i + 1] = NULL;
  if (tab != NULL)
    free_complex_tab(tab);
  return (tmp);
}
