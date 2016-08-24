/*
** my.h for my in /home/ancell_m/rendu/CPE/CPE_2015_Lemin/include
** 
** Made by maxime ancellin
** Login   <ancell_m@epitech.net>
** 
** Started on  Tue Apr 12 15:49:32 2016 maxime ancellin
** Last update Sun Apr 24 22:34:57 2016 Reever Valerus
*/

#include <stdlib.h>

#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
void	my_put_nbr(int nbr);
void	my_putstr(char *str);
void	*xmalloc(size_t size);
int	my_error(char *str);
int	my_getnbr(char *str);
int	my_getnbr_position(char *str, int position);
int	my_strlen(char *str);
int	my_strlen_char(char *str, char ascii);
int	count_triplechar(char ***tab);
int	my_tablen(char **tab);
int	my_strcmp(char *str1, char *str2);
int	my_strncmp(char *, char *, int);
int	check_double_elem(char **tab);
char	*epur_str(char *str);
int	*my_revstr_int(int *path);

#endif /* !MY_H_ */
