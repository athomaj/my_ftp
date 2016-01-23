/*
** client_management.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 16:45:26 2015 julien athomas
** Last update Sun Mar 22 18:35:00 2015 julien athomas
*/

#include "server.h"

void		client_management(int fd_c, char *tab[NB_COM],
				  void (*fptr[NB_COM])(char *, t_user *))
{
  char		buf[4096];
  int		ret;
  t_user	user;

  write(fd_c, "220", 3);
  init_user(&user, fd_c);
  user.tab = tab;
  chdir(user.main_path);
  memset(buf, 0, BUF_SIZE);
  while ((ret = read(user.fd, buf, BUF_SIZE)) > 0)
    {
      if (buf[ret - 2] == '\r')
	buf[ret - 2] = 0;
      buf[ret - 1] = 0;
      check_functions(buf, tab, fptr, &user);
      memset(buf, 0, BUF_SIZE);
    }
}

int	fork_for_clients(int fd_c,
			 char *tab[NB_COM],
			 void (*fptr[NB_COM])(char *, t_user *))
{
  if (fork() == 0)
    client_management(fd_c, tab, fptr);
  else if (close(fd_c) == -1)
    return (-1);
  return (0);
}

int			receive_clients(int fd)
{
  struct sockaddr_in	s_in_c;
  socklen_t		s_size;
  int			fd_c;
  char			*tab[NB_COM];
  void			(*fptr[NB_COM])(char *, t_user *);

  init_func_tab(tab, fptr);
  s_size = sizeof(s_in_c);
  while (1)
    {
      if ((fd_c = accept(fd, (struct sockaddr *)&s_in_c, &s_size)) == -1)
	{
	  fprintf(stderr, "Accept failed\n");
	  close(fd);
	  return (-1);
	}
      fork_for_clients(fd_c, tab, fptr);
    }
  if (close(fd_c) == -1)
    return (-1);
  return (0);
}
