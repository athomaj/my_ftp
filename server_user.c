/*
** server_user.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 16:55:18 2015 julien athomas
** Last update Wed Mar 25 09:13:28 2015 julien athomas
*/

#include "server.h"

void		my_user(UNUSED char *com, t_user *user)
{
  char		*val;

  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if (val == NULL)
    {
      write(user->fd, "500", 3);
      return ;
    }
  if (strcmp(val, "Anonymous") == 0)
    {
      write(user->fd, "230", 3);
      user->password = strdup("");
    }
  else
    write(user->fd, "331", 4);
  user->name = strdup(val);
}

void		my_passwd(char *com, t_user *user)
{
  char		*val;

  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if (user->name == NULL || val == NULL)
    {
      write(user->fd, "332", 4);
      return ;
    }
  else if (strcmp(user->name, "Anonymous") == 0)
    {
      write(user->fd, "912", 4);
      return ;
    }
  if ((strcmp(user->name, USERNAME1) == 0 && strcmp(val, USERPASSWD1) == 0) ||
      (strcmp(user->name, USERNAME2) == 0 && strcmp(val, USERPASSWD2) == 0) ||
      (strcmp(user->name, USERNAME3) == 0 && strcmp(val, USERPASSWD3) == 0))
    {
      user->password = strdup(val);
      write(user->fd, "230", 3);
    }
  else
    write(user->fd, "332", 4);
}
