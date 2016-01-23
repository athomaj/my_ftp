/*
** server_help_user.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sun Mar 22 14:52:30 2015 julien athomas
** Last update Sun Mar 22 15:28:44 2015 julien athomas
*/

#include "server.h"

void		my_help_passwd(int fd)
{
  usleep(10000);
  write(fd, "Enter user password\nPASS/pass usage: PASS/pass password\n",
	sizeof("Enter user password\nPASS/pass usage: PASS/pass password\n"));
}

void		my_help_user(int fd)
{
  usleep(10000);
  write(fd, "Enter username\nUSER/user usage: USER/user username\n",
	sizeof("Enter username\nUSER/user usage: USER/user username\n"));
}
