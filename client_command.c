/*
** client_command.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:46:34 2015 julien athomas
** Last update Sun Mar 22 18:26:36 2015 julien athomas
*/

#include "client.h"

int	which_command(char buf[BUF_SIZE], t_info *info, char *tab[NB_COM],
		      void (*fptr[NB_COM])(char *, t_info *))
{
  char	*com;
  int	i;

  if ((com = strtok(buf, " ")) == NULL)
    return (1);
  i = -1;
  while (++i < NB_COM)
    {
      if (strcmp(tab[i], com) == 0)
	{
	  fptr[i](strtok(NULL, " "), info);
	  return (0);
	}
    }
  fprintf(stderr, KRED"Invalid Command"RESET"\n");
  return (1);
}

void	my_command_loop(t_info *info)
{
  int	ret;
  char	buf[BUF_SIZE];
  char	*tab[NB_COM];
  void	(*fptr[NB_COM])(char *, t_info *);

  init_msg(info);
  init_func_tab(tab, fptr);
  memset(buf, 0, BUF_SIZE);
  check_command_return(info);
  printf("%s: ", info->user_name);
  fflush(stdout);
  while ((ret = read(0, buf, BUF_SIZE)) > 0)
    {
      buf[ret - 1] = 0;
      if (which_command(buf, info, tab, fptr) == -1)
	return ;
      printf("%s: ", info->user_name);
      fflush(stdout);
      memset(buf, 0, BUF_SIZE);
    }
}

int	check_command_return(t_info *info)
{
  int	ret;
  char	buf[BUF_SIZE];
  int	i;

  memset(buf, 0, BUF_SIZE);
  if ((ret = read(info->fd, buf, BUF_SIZE)) <= 0)
    {
      close(info->fd);
      fprintf(stderr, "Connection with server closed\n");
      exit(-1);
    }
  i = -1;
  buf[ret] = 0;
  while (++i < NB_CODE)
    if (strcmp(info->tab[i], buf) == 0)
      return (info->fptr[i](info));
  fprintf(stderr, "Unknown code\n");
  return (-2);
}

int	ok_com(UNUSED t_info *info)
{
  printf(KGRN "%s: OK" RESET"\n", OK_COM);
  return (0);
}

void	my_quit(UNUSED char *buf, t_info *info)
{
  write(info->fd, "QUIT\r\n", 5);
  check_command_return(info);
}
