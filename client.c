/*
** client.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Tue Mar  3 14:51:34 2015 julien athomas
** Last update Sat Mar 21 23:50:00 2015 julien athomas
*/

#include "client.h"

int		init_com(UNUSED t_info *info)
{
  printf(KGRN"%s: Connection established"RESET"\n", INIT_COM);
  return (0);
}

int			main(int argc, char **argv)
{
  struct protoent	*pe;
  int			fd;
  struct sockaddr_in	s_in;
  int			port;
  char			*ip;

  if (argc != 3)
    {
      fprintf(stderr, "Usage: ./client ip port\n");
      return (-1);
    }
  ip = argv[1];
  port = atoi(argv[2]);
  if ((pe = getprotobyname("TCP")) == NULL)
    return (-1);
  s_in.sin_family = AF_INET;
  s_in.sin_port = htons(port);
  s_in.sin_addr.s_addr = inet_addr(ip);
  if ((fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (-1);
  init_connection(&s_in, fd);
  if (close(fd) == -1)
    return (-1);
  return (0);
}
