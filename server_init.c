/*
** server_init.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 16:48:37 2015 julien athomas
** Last update Sun Mar 22 15:00:19 2015 julien athomas
*/

#include "server.h"

void		init_user(t_user *user, int fd_c)
{
  user->fd = fd_c;
  user->file = fdopen(fd_c, "r+");
  user->path = malloc(sizeof(char) * 2);
  user->path = strcat(user->path, "/\0");
  user->name = NULL;
  user->password = NULL;
  user->main_path = malloc(MAXPATHLEN);
  getcwd(user->main_path, MAXPATHLEN);
  user->main_path = realloc(user->main_path,
			    strlen(user->main_path) + sizeof("/ftp"));
  strcat(user->main_path, "/ftp");
  init_help(user);
}

void	init_func_tab(char *tab[NB_COM],
		      void (*fptr[NB_COM])(char *, t_user *))
{
  tab[0] = "LIST";
  tab[1] = "PWD";
  tab[2] = "CWD";
  tab[3] = "QUIT";
  tab[4] = "STOR";
  tab[5] = "USER";
  tab[6] = "PASS";
  tab[7] = "NOOP";
  tab[8] = "CDUP";
  tab[9] = "RETR";
  tab[10] = "DELE";
  tab[11] = "HELP";
  fptr[0] = &my_ls;
  fptr[1] = &my_pwd;
  fptr[2] = &my_cd;
  fptr[3] = &my_quit;
  fptr[4] = &my_put;
  fptr[5] = &my_user;
  fptr[6] = &my_passwd;
  fptr[7] = &my_noop;
  fptr[8] = &my_cdup;
  fptr[9] = &my_get;
  fptr[10] = &my_delete;
  fptr[11] = &my_help;
}

void	init_help(t_user *info)
{
  info->fptr[0] = &my_help_ls;
  info->fptr[1] = &my_help_pwd;
  info->fptr[2] = &my_help_cd;
  info->fptr[3] = &my_help_quit;
  info->fptr[4] = &my_help_put;
  info->fptr[5] = &my_help_user;
  info->fptr[6] = &my_help_passwd;
  info->fptr[7] = &my_help_noop;
  info->fptr[8] = &my_help_cdup;
  info->fptr[9] = &my_help_get;
  info->fptr[10] = &my_help_delete;
  info->fptr[11] = &my_help_help;
}

int	init_proto(struct protoent **pe, struct sockaddr_in *s_in, int port)
{
  if ((*pe = getprotobyname("TCP")) == NULL)
    return (-1);
  s_in->sin_family = AF_INET;
  s_in->sin_port = htons(port);
  s_in->sin_addr.s_addr = INADDR_ANY;
  return (0);
}

int	init_socket(struct protoent *pe, struct sockaddr_in *s_in)
{
  int	fd;

  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  if (bind(fd, (const struct sockaddr *)s_in, sizeof(*s_in)) == -1)
    {
      fprintf(stderr, "bind failed\n");
      if (close(fd) == -1)
	return (-1);
      return (-1);
    }
  if (listen(fd, 42) == -1)
    {
      if (close(fd) == -1)
	return (-1);
      return (-1);
    }
  return (fd);
}
