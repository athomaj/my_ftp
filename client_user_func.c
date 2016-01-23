/*
** client_user_func.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:35:53 2015 julien athomas
** Last update Sat Mar 21 17:36:36 2015 julien athomas
*/

#include "client.h"

int	user_logged_in(UNUSED t_info *info)
{
  printf(KGRN"%s: You are now logged in"RESET"\n", LOGGED_IN);
  return (0);
}

int	asking_password(UNUSED t_info *info)
{
  printf(KGRN"%s: Please enter your password"RESET"\n", USER);
  return (-1);
}

int	no_account(UNUSED t_info *info)
{
  printf(KRED"%s: Authentification failed"RESET"\n", PASS);
  return (-1);
}

int	anonymous_passwd(UNUSED t_info *info)
{
  fprintf(stderr, KRED"%s: You can't set a password as Anonymous"RESET"\n",
	  ANON_PASS);
  return (-1);
}

int	not_logged_in(UNUSED t_info *info)
{
  fprintf(stderr, KRED"%s: You are not logged in"RESET"\n", NOT_LOGGED_IN);
  return (-1);
}
