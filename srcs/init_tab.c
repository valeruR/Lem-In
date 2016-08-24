/*
** init_tab.c for lem_in in /home/valeru_r/rendu/Prog_Elem/Lemin/my_part
**
** Made by Reever Valerus
** Login   <valeru_r@epitech.net>
**
** Started on  Fri Apr 15 16:35:51 2016 Reever Valerus
** Last update Mon Apr 25 22:54:44 2016 Reever Valerus
*/

#include <stdlib.h>
#include "lemin.h"
#include "my.h"

static int	init_tab(t_info *data, t_int_tab *toto)
{
  int	i;
  int	u;
  int	k;

  i = 0;
  u = 0;
  k = 0;
  while (data->rooms[i])
    i++;
  toto->len = i;
  if ((toto->tab = malloc(sizeof(int *) * i + 10)) == NULL)
    return (-1);
  if ((toto->tab_len = malloc(sizeof(int) * i + 2)) == NULL)
    return (-1);
  while (data->links[k])
    k++;
  while (u < i)
    {
      if ((toto->tab[u] = malloc(sizeof(int) * 2)) == NULL)
	return (-1);
      toto->tab[u][0]  = -1;
      toto->tab_len[u] = 1;
      u++;
    }
  return (0);
}

int		len_tab(char **links, char *str)
{
  int		d;
  int		i;

  i = 0;
  d = 0;
  while (links[i])
    {
      if (my_strcmp(links[i], str) == 0)
	d++;
      i++;
    }
  return (d);
}

int		put_int_tab(char **link, int i, char **room)
{
  int		u;

  u = 0;
  if (i == 1)
    {
      while (room[u])
	{
	  if (my_strcmp(link[0], room[u]) == 0)
	    return (u);
	  u++;
	}
    }
  else if (i == 0)
    {
      while (room[u])
	{
	  if (my_strcmp(link[1], room[u]) == 0)
	    return (u);
	  u++;
	}
      return (u);
    }
  return (-1);
}

int		*my_realloc_tab(char **links, char **rooms, int idx,
				t_int_tab *rat)
{
  int		*tab;
  int		i;
  int		k;

  if ((tab = malloc(sizeof(int) * rat->tab_len[idx] + 20)) == NULL)
    return (NULL);
  i = 0;
  k = 0;
  if (rat->tab[idx][0] != -1 && rat->tab_len[idx] > 0)
    while (k < rat->tab_len[idx] -1)
      {
	tab[k] = rat->tab[idx][k];
	k++;
      }
  while (links[i])
    {
      if (my_strcmp(links[i], rooms[idx]) == 0)
	tab[k++] = put_int_tab(links, i, rooms);
      i++;
    }
  tab[k] = -1;
  rat->tab_len[idx] = rat->tab_len[idx] + 1;
  free(rat->tab[idx]);
  return (tab);
}

int		**your_tab_sir(t_info *data, t_int_tab *ro)
{
  t_variab	to;

  init_tab(data, ro);
  to.idx_link = 0;
  while (data->links[to.idx_link])
    {
      to.u_link = 0;
      while (data->links[to.idx_link][to.u_link])
	{
	  to.idx_roo = 0;
	  while (data->rooms[to.idx_roo])
	    {
	      if (my_strcmp(data->links[to.idx_link][to.u_link],
			    data->rooms[to.idx_roo]) == 0)
		ro->tab[to.idx_roo] = my_realloc_tab(data->links[to.idx_link],
							data->rooms, to.idx_roo,
						     ro);
	      to.idx_roo++;
	    }
	  to.u_link++;
	}
      to.idx_link++;
    }
  ro->tab[to.idx_roo] = NULL;
  return (ro->tab);
}

int		val_room(char **rooms, char *start)
{
  int		idx;
  int		u;

  idx = 0;
  u = 0;
  while (start[u] != ' ')
    u++;
  while (rooms[idx])
    {
      if (my_strncmp(rooms[idx], start, u) == 0)
	return (idx);
      idx++;
    }
  return (-1);
}
