/*
** client_file_command.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:51:41 2015 julien athomas
** Last update Sun Mar 22 18:27:53 2015 julien athomas
*/

#include "client.h"

int	file_not_accesible(UNUSED t_info *info)
{
  fprintf(stderr, KRED"%s: File is not found"RESET"\n", FILE_NOT_ACESS);
  return (-1);
}

void	my_ls(char *buf, t_info *info)
{
  char	*socket;

  if ((socket = malloc(sizeof("LIST \r\n") + (buf ? strlen(buf) : 1))) == NULL)
    return ;
  memset(socket, 0, sizeof("LIST \r\n") + (buf ? strlen(buf) : 1));
  socket = strcat(socket, "LIST ");
  socket = strcat(socket, (buf ? buf : "."));
  socket = strcat(socket, "\r\n");
  write(info->fd, socket, strlen(socket));
  check_command_return(info);
  free(socket);
}

int	open_failed(UNUSED t_info *info)
{
  fprintf(stderr, KRED"%s: File could not be open"RESET"\n", OPEN_FAIL);
  return (-1);
}

int	syntax_error(UNUSED t_info *info)
{
  fprintf(stderr, KRED"%s: Syntax Error"RESET"\n", SYNTAX_ERR);
  return (-1);
}

int	critical_error(t_info *info)
{
  fprintf(stderr, KRED"%s: A critical error has occured"RESET"\n",
	  CRITICAL_ERR);
  close(info->fd);
  return (-1);
}
