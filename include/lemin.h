/*
** lemin.h for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/include
**
** Made by maxime ancellin
** Login   <ancell_m@PC-Ubuntech-NEO>
**
** Started on  Tue Apr 12 15:52:04 2016 maxime ancellin
** Last update Sun Apr 24 22:12:55 2016 Reever Valerus
*/

#ifndef LEMIN_H_
# define LEMIN_H_

typedef struct	s_data
{
  int		i;
  int		u;
  int		r;
  int		k;
  char		*s;
  char		*t;
  int		*tab;
}		t_data;

typedef struct	s_picsou
{
  int		h;
  int		c;
  int		poutiz;
  int		tours;
  int		*path;
}		t_picsou;

typedef struct	s_info
{
  int		error;
  int		ants;
  char		*start;
  char		*end;
  char		**rooms;
  char		***links;
}		t_info;

typedef struct	s_int_tab
{
  int		**tab;
  int		*tab_len;
  int		len;
}		t_int_tab;

typedef struct	s_variab
{
  int		idx_roo;
  int		idx_link;
  int		u_room;
  int		u_link;
}		t_variab;

int	init_struct(t_info *info);
int	set_for_rooms(t_info *info, char *str);
int	set_for_links(t_info *info, char *str);
int	my_exit(t_info *info, int type);
char	**realloc_tab(char **tab, char *input);
char	***realloc_links(char ***tab, char *input1, char *input2);
void	free_simple_tab(char **tab);
void	free_complex_tab(char ***tab);
void	free_all(t_info *info);
int	**your_tab_sir(t_info *data, t_int_tab *ro);
int	finding(int **links, int **path, int end);
int	**init(int nb, int start);
void	set_for_start(t_info *info);
void	set_for_end(t_info *info);
int	check_rooms(char *str);
int	check_links(char *str);
int	val_room(char **, char *);
void	print_struct(t_info info);
void	antpath(int *, int, t_int_tab , t_info );
int	**another_tab(int *, t_int_tab *);
int	*fourmiz(int nb, int start);
void	path(t_int_tab *data, t_info *info, int nb);
void	dispanou(int **src, int end, int fourmiz, t_info);
int	check_input(char *str, t_info *info);

#endif /* !LEMIN_H_ */
