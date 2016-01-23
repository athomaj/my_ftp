/*
** server_file.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 16:51:59 2015 julien athomas
** Last update Sun Mar 22 18:40:38 2015 julien athomas
*/

#include "server.h"

void		my_delete(char *com, t_user *user)
{
  char		*val;

  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if (val && is_path_right(user, val, 0) == 0)
    return ;
  if (unlink(val) == -1)
    {
      write(user->fd, "550", 3);
      return ;
    }
  write(user->fd, "250", 3);
}

void		my_get(char *com, t_user *user)
{
  char		*val;
  char		*buf;
  size_t	buf_size;
  int		ret;
  FILE		*file;

  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if ((file = fopen(val, "r")) == NULL)
    {
      write(user->fd, "915", 3);
      return ;
    }
  usleep(1000);
  write(user->fd, "150", 3);
  buf = NULL;
  buf_size = (size_t)BUF_SIZE;
  while ((ret = getline(&buf, &buf_size, file)) > 0)
    {
      usleep(10000);
      write(user->fd, buf, ret);
    }
  usleep(1000);
  write(user->fd, "226", 3);
}

void		my_put(char *com, t_user *user)
{
  char		buf[4096];
  int		ret;
  int		fd;
  char		*val;

  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if (val && is_path_right(user, val, 0) == 0)
    return ;
  if ((fd = manage_creation_of_file(user, val)) == -1)
    return ;
  while ((ret = read(user->fd, buf, BUF_SIZE)) > 0 &&
	 strcmp(buf, "0123 Transfer Finished 0123"))
    {
      if (strstr(buf, "0123 Transfer Finished 0123") != NULL)
	{
	  write(user->fd, "226", 3);
	  write(fd, buf, ret - sizeof("0123 Transfer Finished 0123"));
	  return ;
	}
      buf[ret] = 0;
      write(fd, buf, ret);
      memset(buf, 0, BUF_SIZE);
    }
  write(user->fd, "226", 3);
}

int		manage_creation_of_file(UNUSED t_user *user, char *file_name)
{
  int		fd;

  if ((fd = open(file_name, O_RDWR | O_TRUNC | O_CREAT, 422)) == -1)
    {
      write(user->fd, "915", 3);
      return (-1);
    }
  return (fd);
}
