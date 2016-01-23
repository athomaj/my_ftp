/*
** client_help.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 20:33:45 2015 julien athomas
** Last update Wed Mar 25 09:28:25 2015 julien athomas
*/

#include "client.h"

void		my_help(char *buf, t_info *info)
{
  char		*socket;

  if (buf == NULL)
    write(info->fd, "HELP\r\n", 5);
  else
    {
      if ((socket = malloc(sizeof("HELP \r\n") + strlen(buf))) == NULL)
	return ;
      sprintf(socket, "HELP %s\r\n", buf);
      write(info->fd, socket, strlen(socket));
    }
  check_command_return(info);
}

int		help_com(UNUSED t_info *info)
{
  char		buf[BUF_SIZE];

  if (read(info->fd, buf, BUF_SIZE) <= 0)
    return (-1);
  printf("%s", buf);
  fflush(stdout);
  return (0);
}

int		com_not_found(UNUSED t_info *info)
{
  printf(KRED"%s: Command not found"RESET"\n", COM_NOT_FOUND);
  return (-1);
}
