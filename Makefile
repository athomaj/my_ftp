##
## Makefile for  in /home/athoma_j/rendu/PSU_2014_malloc
## 
## Made by julien athomas
## Login   <athoma_j@epitech.net>
## 
## Started on  Mon Feb  2 21:35:53 2015 julien athomas
## Last update Sun Mar 22 15:43:42 2015 julien athomas
##

SRCC=		client.c		\
		client_command.c	\
		client_connection.c	\
		client_file.c		\
		client_file_command.c	\
		client_init.c		\
		client_path.c		\
		client_user.c		\
		client_user_func.c	\
		client_help.c		\
		client_signal.c		\

SRCS=		server.c		\
		client_management.c	\
		server_extra_com.c	\
		server_file.c		\
		server_init.c		\
		server_path.c		\
		server_path_manage.c	\
		server_user.c		\
		server_help_command.c	\
		server_help_file.c	\
		server_help_user.c	\

NAMEC=		client

NAMES=		serveur

OBJS=		$(SRCS:.c=.o)

OBJC=		$(SRCC:.c=.o)

CFLAGS=		-W -Wall -Werror -Wextra


all:		$(NAMEC) $(NAMES)

$(NAMEC):	$(OBJC)
		gcc $(SRCC) -o $(NAMEC)

$(NAMES):	$(OBJS)
		gcc $(SRCS) -o $(NAMES)

clean:
		rm -f $(OBJS) $(OBJC)

fclean:		clean
		rm -f $(NAMES) $(NAMEC)

re:		fclean all

.PHONY:		all clean fclean re
