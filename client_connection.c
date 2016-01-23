/*
** client_connection.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:55:40 2015 julien athomas
** Last update Sun Mar 22 18:32:22 2015 julien athomas
*/

#include "client.h"

int	open_data_connection(UNUSED t_info *info)
{
  int	ret;
  char	buf[BUF_SIZE];
  int	i;

  memset(buf, 0, BUF_SIZE);
  while ((ret = read(info->fd, buf, BUF_SIZE)) > 0)
    {
      i = -1;
      buf[ret] = 0;
      while (++i < NB_CODE)
	if (strcmp(info->tab[i], buf) == 0)
	  return (info->fptr[i](info));
      write(info->cur_fd, buf, ret);
    }
  return (-2);
}

int	close_data_connection(UNUSED t_info *info)
{
  return (-1);
}

int	stop_connection(UNUSED t_info *info)
{
  printf("Logout\n");
  close(info->fd);
  exit(0);
}

void	my_noop(UNUSED char *buf, t_info *info)
{
  write(info->fd, "NOOP\r\n", 5);
  check_command_return(info);
}
