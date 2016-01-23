/*
** client_signal.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sun Mar 22 13:24:14 2015 julien athomas
** Last update Sun Mar 22 13:30:13 2015 julien athomas
*/

#include "client.h"

void	catch_sigint(UNUSED int sig)
{
  fprintf(stderr, KRED"You can't interupt"RESET"\n");
}
