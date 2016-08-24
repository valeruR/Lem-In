/*
** get_next_line.h for get_next_line in /home/blerio_h/Rendu/C_Elementary/CPE_2015_getnextline
** 
** Made by blerio_h
** Login   <blerio_h@Elitebook-Bleriot>
** 
** Started on  Mon Jan  4 15:13:17 2016 blerio_h
** Last update Tue Apr 12 16:04:10 2016 maxime ancellin
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (256)
# endif /* !READ_SIZE */

typedef struct	s_mydouble
{
  int		i;
  int		j;
  char		*tmp;
}		t_mydouble;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
