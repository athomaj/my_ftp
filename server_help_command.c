/*
** server_help_command.c for $ in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sun Mar 22 14:48:55 2015 julien athomas
** Last update Sun Mar 22 15:28:02 2015 julien athomas
*/

#include "server.h"

void	my_help_pwd(int fd)
{
  usleep(10000);
  write(fd, "Print current location\npwd usage: pwd\n",
	sizeof("Print current location\npwd usage: pwd\n"));
}

void	my_help_cd(int fd)
{
  usleep(10000);
  write(fd, "Change directory location\ncd usage: cd pathname\n",
	sizeof("Change directory location\ncd usage: cd pathname\n"));
}

void	my_help_quit(int fd)
{
  usleep(10000);
  write(fd, "Close client connection\nquit usage: quit",
	sizeof("Close client connection\nquit usage: quit"));
}

void	my_help_noop(int fd)
{
  usleep(10000);
  write(fd, "Server send OK reply\nNOOP usage: NOOP",
	sizeof("Server send OK reply\nNOOP usage: NOOP"));
}

void	my_help_cdup(int fd)
{
  usleep(10000);
  write(fd, "Change to parent location\nCDUP usage: CDUP",
	sizeof("Change to parent location\nCDUP usage: CDUP"));
}
