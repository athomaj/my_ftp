/*
** server.h for  in /Users/julien/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <julien@epitech.net>
** 
** Started on  Tue Mar 10 17:19:33 2015 julien athomas
** Last update Sun Mar 22 15:02:06 2015 julien athomas
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/param.h>
# include <sys/stat.h>
# include <dirent.h>

# define NL_SIZE 1
# define UNUSED __attribute__((unused))
# define NB_COM 12
# define BUF_SIZE 4096

# define USERNAME1 "colin"
# define USERNAME2 "julien"
# define USERNAME3 "tim"
# define USERPASSWD1 "colin"
# define USERPASSWD2 "ju"
# define USERPASSWD3 "burdai"

typedef struct	s_user
{
  char		*name;
  char		*password;
  char		*path;
  char		*main_path;
  FILE		*file;
  int		fd;
  char		**tab;
  void		(*fptr[NB_COM])(int);
}		t_user;

void		client_management(int fd_c, char *tab[NB_COM],
				  void (*fptr[NB_COM])(char *, t_user *));
int		fork_for_clients(int fd_c,
				 char *tab[NB_COM],
				 void (*fptr[NB_COM])(char *, t_user *));
int		receive_clients(int fd);
int		init_socket(struct protoent *pe, struct sockaddr_in *s_in);
int		init_proto(struct protoent **pe,
			   struct sockaddr_in *s_in, int port);
void		init_func_tab(char *tab[NB_COM],
			      void (*fptr[NB_COM])(char *, t_user *));
void		init_user(t_user *user, int fd_c);
int		check_existing_file(char buf[4096], char file_name[4096],
				    t_user *user);
int		manage_creation_of_file(UNUSED t_user *user, char *file_name);
void		my_put(char *com, t_user *user);
void		my_get(char *com, t_user *user);
void		my_delete(char *com, t_user *user);
int		is_path_right(t_user *user, char *str, int letter);
void		my_ls(char *com, t_user *user);
void		my_pwd(UNUSED char *com, t_user *user);
void		my_cdup(UNUSED char *com, t_user *user);
void		my_cd(char *com, t_user *user);
void		my_passwd(char *com, t_user *user);
void		my_user(UNUSED char *com, t_user *user);
void		my_quit(UNUSED char *com, t_user *user);
void		my_noop(UNUSED char *com, t_user *user);
void		my_help(UNUSED char *com, t_user *user);
void		check_functions(char *buf, char *tab[NB_COM],
				void (*fptr[NB_COM])(char *, t_user *),
				t_user *user);
char		*create_new_path(char *old_path, char *new_path);
void		init_help(t_user *user);
void		get_new_path(t_user *user, char *val);
void		my_help_ls(int fd);
void		my_help_get(int fd);
void		my_help_help(int fd);
void		my_help_delete(int fd);
void		my_help_put(int fd);
void		my_help_pwd(int fd);
void		my_help_cd(int fd);
void		my_help_quit(int fd);
void		my_help_noop(int fd);
void		my_help_cdup(int fd);
void		my_help_user(int fd);
void		my_help_passwd(int fd);

#endif
