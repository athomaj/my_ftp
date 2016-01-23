/*
** server_path_manage.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:01:22 2015 julien athomas
** Last update Sat Mar 21 17:01:37 2015 julien athomas
*/

#include "server.h"

char	*create_new_path(char *old_path, char *new_path)
{
  free(old_path);
  old_path = malloc(strlen(new_path));
  strcat(old_path, new_path);
  return (old_path);
}

void	get_new_path(t_user *user, char *val)
{
  char	*new_path;
  char	cur_path[MAXPATHLEN];
  char	new_real_path[MAXPATHLEN];

  getcwd(cur_path, MAXPATHLEN);
  new_path = malloc(strlen(cur_path) + strlen(val) + 1);
  sprintf(new_path, "%s/%s", cur_path, val);
  if (chdir(new_path) == -1)
    {
      write(user->fd, "550", 3);
      return ;
    }
  getcwd(new_real_path, MAXPATHLEN);
  if (strncmp(new_real_path, user->main_path,
	      strlen(user->main_path) - 1) != 0)
    {
      chdir(cur_path);
      write(user->fd, "550", 3);
      return ;
    }
  write(user->fd, "Path changed", sizeof("Path changed"));
}
