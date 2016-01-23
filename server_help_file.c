/*
** server_help_file.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sun Mar 22 14:13:01 2015 julien athomas
** Last update Sun Mar 22 15:28:32 2015 julien athomas
*/

#include "server.h"

void	my_help_put(int fd)
{
  usleep(10000);
  write(fd, "Upload a file on server\nput/STOR usage: put/STOR pathname\n",
	sizeof("Upload a file on server\n"
	       "put/STOR usage: put/STOR pathname\n"));
}

void	my_help_get(int fd)
{
  usleep(10000);
  write(fd, "Download a file from sever\nget/RETR usage: get/RETR pathname\n",
	sizeof("Download a file from sever\n"
	       "get/RETR usage: get/RETR pathname\n"));
}

void	my_help_help(int fd)
{
  usleep(10000);
  write(fd, "You can use ls/pwd/put/get/cd/help\n",
	sizeof("You can use ls/pwd/put/get/cd/help\n"));
}

void	my_help_delete(int fd)
{
  usleep(10000);
  write(fd, "Delete a file from sever\nDELE usage: DELE pathname\n",
	sizeof("Delete a file from sever\nDELE usage: DELE pathname\n"));
}

void	my_help_ls(int fd)
{
  usleep(10000);
  write(fd, "List file on server\nls/LIST usage: ls/LIST [pathname]\n",
	sizeof("List file on server\nls/LIST usage: ls/LIST [pathname]\n"));
}
