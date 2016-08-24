##
## Makefile for lemin in /home/ancell_m/rendu/CPE/CPE_2015_Lemin
## 
## Made by maxime ancellin
## Login   <ancell_m@epitech.net>
## 
## Started on  Sun Apr 24 22:40:51 2016 maxime ancellin
## Last update Mon Apr 25 12:10:02 2016 maxime ancellin
##

CC	=	gcc -I./include -o

RM	=	rm -f

NAME	=	lem_in

SRCS	=	share/get_next_line.c \
		share/my_error.c \
		share/my_getnbr.c \
		share/my_putchar.c \
		share/my_put_nbr.c \
		share/my_putstr.c \
		share/my_strlen.c \
		share/my_tablen.c \
		share/my_revstr_int.c \
		share/count_triple_char.c \
		share/xmalloc.c \
		share/my_strcmp.c \
		share/my_getnbr_position.c \
		share/my_strlen_char.c \
		share/check_double_elem.c \
		share/epur_str.c \
		srcs/add_in_tab.c \
		srcs/set_for_add.c \
		srcs/my_free.c \
		srcs/init_tab.c \
		srcs/main.c \
		srcs/another_tab.c \
		srcs/pathfinding.c \
		srcs/display.c \
		srcs/parsing.c

CFLAGS  +=	-Wextra -Wall -Werror -W
CFLAGS  +=	-Iinclude

OBJS	= 	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(NAME) $(SRCS)

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
