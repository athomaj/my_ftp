/*
** server_extra_com.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:04:03 2015 julien athomas
** Last update Sun Mar 22 15:55:41 2015 julien athomas
*/

#include "server.h"

void		my_quit(UNUSED char *com, t_user *user)
{
  write(user->fd, "221", 3);
}

void		my_noop(UNUSED char *com, t_user *user)
{
  usleep(1000);
  write(user->fd, "200", 3);
}

void		my_help(UNUSED char *com, t_user *user)
{
  int		i;
  char		*val;

  usleep(1000);
  write(user->fd, "214", 3);
  val = strtok(com, " ");
  val = strtok(NULL, " ");
  usleep(1000);
  if (val == NULL)
    {
      user->fptr[11](user->fd);
      return ;
    }
  i = -1;
  while (++i < NB_COM)
    if (strcmp(val, user->tab[i]) == 0)
      {
	user->fptr[i](user->fd);
	return ;
      }
  usleep(10000);
  write(user->fd, "Command Not found\n", sizeof("Command Not found\n"));
}
