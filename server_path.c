/*
** server_path.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 16:56:07 2015 julien athomas
** Last update Wed Mar 25 18:45:53 2015 julien athomas
*/

#include "server.h"

int	is_path_right(t_user *user, char *str, int letter)
{
  int	i;

  if (strchr(str, '/'))
    {
      write(user->fd, "550", 3);
      return (0);
    }
  if (letter)
    {
      if (str[0] == '.' && strlen(str) == 1)
	return (1);
      i = -1;
      while (str[++i])
	if ((str[i] <= 'a' || str[i] >= 'z') && (str[i] <= 'A' || str[i] >= 'Z'))
	  {
	    printf("%c\n", str[i]);
	    write(user->fd, "550", 3);
	    return (0);
	  }
    }
  return (1);
}

void	my_ls(char *com, t_user *user)
{
  FILE	*file;
  char	buf[BUF_SIZE];
  char	*val;
  char	*path;

  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if (val && is_path_right(user, val, 1) == 0)
    return ;
  write(user->fd, "150", 3);
  if (!val)
    file = popen("ls", "r");
  else
    {
      path = malloc(strlen(val) + 3);
      sprintf(path, "ls %s", val);
      file = popen(path, "r");
    }
  memset(buf, 0, BUF_SIZE);
  while (fgets(buf, BUF_SIZE, file))
    write(user->fd, buf, strlen(buf));
  usleep(10000);
  write(user->fd, "226", 3);
}

void	my_pwd(__attribute__((unused))char *com, t_user *user)
{
  char	path[MAXPATHLEN];
  char	*new_path;

  write(user->fd, "257", 3);
  usleep(1000);
  getcwd(path, MAXPATHLEN);
  if ((new_path = malloc(MAXPATHLEN)) == NULL)
    {
      write(user->fd, "552", 3);
      return ;
    }
  sprintf(new_path, "/%s\n", (strlen(path) == strlen(user->main_path) ?
			       "" : path + strlen(user->main_path) + 1));
  write(user->fd, new_path, strlen(new_path));
  free(new_path);
}

void	my_cd(char *com, t_user *user)
{
  char	*val;

  write(user->fd, "250", 3);
  usleep(1000);
  val = strtok(com, " ");
  val = strtok(NULL, " ");
  if (val == NULL)
    {
      write(user->fd, "500", 3);
      return ;
    }
  get_new_path(user, val);
}

void	my_cdup(UNUSED char *com, t_user *user)
{
  char	*new_path;
  char	cur_path[MAXPATHLEN];
  char	new_real_path[MAXPATHLEN];
  char	*val;

  val = "..";
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
  write(user->fd, "200", 3);
}
