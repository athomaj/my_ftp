/*
** client_init.c for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Sat Mar 21 17:30:08 2015 julien athomas
** Last update Wed Mar 25 09:18:11 2015 julien athomas
*/

#include "client.h"

void	init_funcs(t_info *info)
{
  info->fptr[0] = &user_logged_in;
  info->fptr[1] = &asking_password;
  info->fptr[2] = &no_account;
  info->fptr[3] = &open_data_connection;
  info->fptr[4] = &close_data_connection;
  info->fptr[5] = &get_pathname;
  info->fptr[6] = &syntax_error;
  info->fptr[7] = &critical_error;
  info->fptr[8] = &anonymous_passwd;
  info->fptr[9] = &file_action;
  info->fptr[10] = &file_not_accesible;
  info->fptr[11] = &not_logged_in;
  info->fptr[12] = &stop_connection;
  info->fptr[13] = &open_failed;
  info->fptr[14] = &ok_com;
  info->fptr[15] = &init_com;
  info->fptr[16] = &help_com;
  info->fptr[17] = &com_not_found;
}

void	init_msg(t_info *info)
{
  info->tab[0] = LOGGED_IN;
  info->tab[1] = USER;
  info->tab[2] = PASS;
  info->tab[3] = DATA_CO;
  info->tab[4] = CLOSE_CO;
  info->tab[5] = PATHNAME;
  info->tab[6] = SYNTAX_ERR;
  info->tab[7] = CRITICAL_ERR;
  info->tab[8] = ANON_PASS;
  info->tab[9] = FILE_ACT;
  info->tab[10] = FILE_NOT_ACESS;
  info->tab[11] = NOT_LOGGED_IN;
  info->tab[12] = STOP_CO;
  info->tab[13] = OPEN_FAIL;
  info->tab[14] = OK_COM;
  info->tab[15] = INIT_COM;
  info->tab[16] = HELP_COM;
  info->tab[17] = COM_NOT_FOUND;
  init_funcs(info);
}

int		init_connection(struct sockaddr_in *s_in, int fd)
{
  t_info	info;

  signal(SIGINT, catch_sigint);
  if (connect(fd, (const struct sockaddr *)s_in, sizeof(*s_in)) == -1)
    return (-1);
  printf("Welcome\n");
  info.user_name = strdup("Unknown");
  info.cur_fd = 1;
  fflush(stdout);
  info.fd = fd;
  my_command_loop(&info);
  return (0);
}

void	init_my_funcs(void (*fptr[NB_COM])(char *, t_info *))
{
  fptr[0] = &my_ls;
  fptr[1] = &my_pwd;
  fptr[2] = &my_cd;
  fptr[3] = &my_quit;
  fptr[4] = &my_put;
  fptr[5] = &my_user;
  fptr[6] = &my_password;
  fptr[7] = &my_noop;
  fptr[8] = &my_cdup;
  fptr[9] = &my_get;
  fptr[10] = &my_delete;
  fptr[11] = &my_user;
  fptr[12] = &my_password;
  fptr[13] = &my_cd;
  fptr[14] = &my_quit;
  fptr[15] = &my_get;
  fptr[16] = &my_put;
  fptr[17] = &my_pwd;
  fptr[18] = &my_ls;
  fptr[19] = &my_help;
}

void	init_func_tab(char *tab[NB_COM],
		      void (*fptr[NB_COM])(char *, t_info *))
{
  tab[0] = "ls";
  tab[1] = "pwd";
  tab[2] = "cd";
  tab[3] = "quit";
  tab[4] = "put";
  tab[5] = "user";
  tab[6] = "pass";
  tab[7] = "NOOP";
  tab[8] = "CDUP";
  tab[9] = "get";
  tab[10] = "DELE";
  tab[11] = "USER";
  tab[12] = "PASS";
  tab[13] = "CWD";
  tab[14] = "QUIT";
  tab[15] = "RETR";
  tab[16] = "STOR";
  tab[17] = "PWD";
  tab[18] = "LIST";
  tab[19] = "HELP";
  init_my_funcs(fptr);
}
