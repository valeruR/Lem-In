/*
** pathfinding.c for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/srcs
** 
** Made by maxime ancellin
** Login   <ancell_m@epitech.net>
** 
** Started on  Sun Apr 24 23:00:43 2016 maxime ancellin
** Last update Sun Apr 24 23:00:45 2016 maxime ancellin
*/

#include <stdlib.h>
#include <unistd.h>

int	**init(int nb, int start)
{
  int		**path;
  int		i;

  i = 0;
  if ((path = malloc(sizeof(int *) * (nb + 1))) == NULL)
    return (NULL);
  while (i < nb)
    {
      if ((path[i] = malloc(sizeof(int) * 2)) == NULL)
	return (NULL);
      path[i][0] = 0;
      path[i][1] = (i == start) ? start : -1;
      ++i;
    }
  path[i] = NULL;
  return (path);
}

static int	father(int **path)
{
  int		i;

  i = 0;
  while (path[i] != NULL)
    if (path[i][0] == 0 && path[i][1] != -1)
      {
	path[i][0] = 1;
	return (i);
      }
    else
      i++;
  return (-1);
}

static void	son(int **path, int *links, int value)
{
  int		i;

  i = 0;
  if (links == NULL)
    return;
  while (links[i] != -1 && path[links[i]] != NULL)
    {
      if (path[links[i]][0] == 0 && path[links[i]][1] == -1)
	path[links[i]][1] = value;
      ++i;
    }
}


int	finding(int **links, int **path, int end)
{
  int		i;

  i = 0;
  while (path[end][1] == -1)
    {
      i = father(path);
      if (i == -1)
	return (-1);
      son(path, links[i], i);
    }
  return (1);
}
