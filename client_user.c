/*
** client_user.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:34:38 2015 julien athomas
** Last update Sun Mar 22 18:31:41 2015 julien athomas
*/

#include "client.h"

void	my_user(char *buf, t_info *info)
{
  char	*socket;

  if (!buf)
    {
      fprintf(stderr, "Please enter a username\n");
      return ;
    }
  if ((socket = malloc(sizeof("USER \r\n") + strlen(buf))) == NULL)
    return ;
  memset(socket, 0, sizeof("USER \r\n") + strlen(buf));
  socket = strcat(socket, "USER ");
  socket = strcat(socket, buf);
  socket = strcat(socket, "\r\n");
  write(info->fd, socket, strlen(socket));
  if (check_command_return(info) == 0)
    info->user_name = strdup(buf);
  else
    info->tmp_name = strdup(buf);
  free(socket);
}

void	my_password(char *buf, t_info *info)
{
  char	*socket;

  if (!buf)
    {
      fprintf(stderr, "Please enter a password\n");
      return ;
    }
  if ((socket = malloc(sizeof("PASS \r\n") + strlen(buf))) == NULL)
    return ;
  memset(socket, 0, sizeof("PASS \r\n") + strlen(buf));
  socket = strcat(socket, "PASS ");
  socket = strcat(socket, buf);
  socket = strcat(socket, "\r\n");
  write(info->fd, socket, strlen(socket));
  if (check_command_return(info) == 0)
    info->user_name = info->tmp_name;
  free(socket);
}
