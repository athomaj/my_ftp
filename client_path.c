/*
** client_path.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:42:27 2015 julien athomas
** Last update Sun Mar 22 18:29:16 2015 julien athomas
*/

#include "client.h"

int	get_pathname(t_info *info)
{
  int	ret;
  char	buf[BUF_SIZE];
  int	i;

  memset(buf, 0, BUF_SIZE);
  if ((ret = read(info->fd, buf, BUF_SIZE)) <= 0)
    return (-2);
  i = -1;
  while (++i < NB_CODE)
    if (strcmp(info->tab[i], buf) == 0)
      return (info->fptr[i](info));
  write(1, buf, ret);
  return (0);
}

void	my_pwd(UNUSED char *buf, t_info *info)
{
  write(info->fd, "PWD\r\n", 4);
  check_command_return(info);
}

void	my_cd(char *buf, t_info *info)
{
  char	*socket;

  if (!buf)
    {
      fprintf(stderr, "Please enter a destination\n");
      return ;
    }
  if ((socket = malloc(sizeof("CWD \r\n") + strlen(buf))) == NULL)
    return ;
  memset(socket, 0, sizeof("CWD \r\n") + strlen(buf));
  socket = strcat(socket, "CWD ");
  socket = strcat(socket, buf);
  socket = strcat(socket, "\r\n");
  write(info->fd, socket, strlen(socket));
  check_command_return(info);
  free(socket);
}

void	my_cdup(UNUSED char *buf, t_info *info)
{
  write(info->fd, "CDUP\r\n", 5);
  check_command_return(info);
}

void	my_delete(char *buf, t_info *info)
{
  char	*socket;

  if ((socket = malloc(sizeof("DELE \r\n") + strlen(buf))) == NULL)
    return ;
  sprintf(socket, "DELE %s\r\n", buf);
  write(info->fd, socket, strlen(socket));
  check_command_return(info);
}
