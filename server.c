/*
** main.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Tue Mar  3 14:01:04 2015 julien athomas
** Last update Wed Mar 25 09:15:37 2015 julien athomas
*/

#include "server.h"

void	check_functions(char *buf, char *tab[NB_COM],
			void (*fptr[NB_COM])(char *, t_user *), t_user *user)
{
  int	i;
  char	*tmp;
  char	*com;

  tmp = strdup(buf);
  i = -1;
  com = strtok(tmp, " ");
  while (++i < NB_COM)
    {
      if (strcmp(tab[i], com) == 0)
	{
	  if (strcmp(tab[i], "USER") != 0 && strcmp(tab[i], "QUIT") &&
	      strcmp(tab[i], "PASS") && strcmp(tab[i], "HELP") &&
	      (user->name == NULL || (user->password == NULL &&
				      strcmp(user->name, "Anonymous") != 0)))
	    {
	      write(user->fd, "530", 3);
	      return ;
	    }
	  fptr[i](buf, user);
	  return ;
	}
    }
  write(user->fd, "502", 3);
}

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;

  if (argc != 2)
    {
      fprintf(stderr, "Usage: ./server port\n");
      return (-1);
    }
  init_proto(&pe, &s_in, atoi(argv[1]));
  fd = init_socket(pe, &s_in);
  receive_clients(fd);
  if (close(fd) == -1)
    return (-1);
  return (0);
}
