/*
** client_file.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:49:50 2015 julien athomas
** Last update Sun Mar 22 18:30:27 2015 julien athomas
*/

#include "client.h"

void		my_get(char *buf, t_info *info)
{
  int		fd;
  char		*socket;

  if ((fd = manage_creation_of_file(buf)) == -1)
    {
      fprintf(stderr, "File cannot be open\n");
      return ;
    }
  if ((socket = malloc(sizeof("RETR \r\n") + strlen(buf))) == NULL)
    return ;
  sprintf(socket, "RETR %s\r\n", buf);
  write(info->fd, socket, strlen(socket));
  info->cur_fd = fd;
  check_command_return(info);
  info->cur_fd = 1;
}

int		manage_creation_of_file(char *file_name)
{
  int		fd;

  if (!file_name)
    return (-1);
  if ((fd = open(file_name, O_RDWR | O_TRUNC | O_CREAT, 422)) == -1)
    return (-1);
  return (fd);
}

void	my_put(char *buf, t_info *info)
{
  char	*socket;
  FILE	*file;

  if (buf == NULL)
    {
      fprintf(stderr, "Invalid argument\n");
      return ;
    }
  if ((file = fopen(buf, "r")) == NULL)
    {
      fprintf(stderr, "Can't open the file\n");
      return ;
    }
  if ((socket = malloc(sizeof("STOR \r\n") + strlen(buf))) == NULL)
    return ;
  sprintf(socket, "STOR %s\r\n", buf);
  write(info->fd, socket, strlen(socket));
  my_read_file(file, info->fd);
  check_command_return(info);
  free(socket);
}

void		my_read_file(FILE *file, int fd)
{
  char		*buf;
  size_t	buf_size;
  int		ret;

  buf = NULL;
  buf_size = (size_t)BUF_SIZE;
  while ((ret = getline(&buf, &buf_size, file)) > 0)
    {
      write(fd, buf, ret);
      usleep(1000);
    }
  usleep(1000);
  write(fd, "0123 Transfer Finished 0123",
	sizeof("0123 Transfer Finished 0123"));
}

int	file_action(t_info *info)
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
  write(1, "\n", 1);
  return (0);
}
