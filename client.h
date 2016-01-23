/*
** client.h for  in /home/athoma_j/rendu/PSU_2014_myftp
** 
** Made by julien athomas
** Login   <athoma_j@epitech.net>
** 
** Started on  Fri Mar 20 19:41:21 2015 julien athomas
** Last update Wed Mar 25 09:27:57 2015 julien athomas
*/

#ifndef CLIENT_H_
# define CLIENT_H_

# include <stdio.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>

# define UNUSED __attribute__((unused))

# define NB_COM 20
# define BUF_SIZE 4096
# define NB_CODE 18

# define LOGGED_IN "230"
# define USER "331"
# define PASS "332"
# define DATA_CO "150"
# define CLOSE_CO "226"
# define PATHNAME "257"
# define SYNTAX_ERR "500"
# define CRITICAL_ERR "552"
# define ANON_PASS "912"
# define FILE_ACT "250"
# define FILE_NOT_ACESS "550"
# define NOT_LOGGED_IN "530"
# define STOP_CO "221"
# define OPEN_FAIL "915"
# define OK_COM "200"
# define COM_NOT_FOUND "502"
# define INIT_COM "220"
# define HELP_COM "214"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define RESET "\033[0m"

typedef struct	s_info
{
  int		fd;
  int		cur_fd;
  char		*user_name;
  char		*tmp_name;
  int		(*fptr[NB_CODE])(struct s_info *);
  char		*tab[NB_CODE];
}		t_info;

void		init_func_tab(char *tab[NB_COM],
			      void (*fptr[NB_COM])(char *, t_info *));
int		init_connection(struct sockaddr_in *s_in, int fd);
void		init_msg(t_info *info);
void		init_funcs(t_info *info);
int		init_com(UNUSED t_info *info);
int		not_logged_in(UNUSED t_info *info);
int		anonymous_passwd(UNUSED t_info *info);
int		no_account(UNUSED t_info *info);
int		asking_password(UNUSED t_info *info);
int		user_logged_in(UNUSED t_info *info);
void		my_user(char *buf, t_info *info);
void		my_password(char *buf, t_info *info);
void		my_delete(char *buf, t_info *info);
void		my_cdup(UNUSED char *buf, t_info *info);
void		my_cd(char *buf, t_info *info);
void		my_pwd(UNUSED char *buf, t_info *info);
int		get_pathname(t_info *info);
void		my_quit(UNUSED char *buf, t_info *info);
int		ok_com(UNUSED t_info *info);
int		check_command_return(t_info *info);
void		my_command_loop(t_info *info);
int		which_command(char buf[BUF_SIZE],
			      t_info *info, char *tab[NB_COM],
			      void (*fptr[NB_COM])(char *, t_info *));
int		file_action(t_info *info);
void		my_read_file(FILE *file, int fd);
void		my_put(char *buf, t_info *info);
int		manage_creation_of_file(char *file_name);
void		my_get(char *buf, t_info *info);
int		critical_error(t_info *info);
int		syntax_error(UNUSED t_info *info);
int		open_failed(UNUSED t_info *info);
void		my_ls(char *buf, t_info *info);
int		file_not_accesible(UNUSED t_info *info);
int		open_data_connection(UNUSED t_info *info);
int		close_data_connection(UNUSED t_info *info);
int		stop_connection(UNUSED t_info *info);
void		my_noop(UNUSED char *buf, t_info *info);
int		init_com(UNUSED t_info *info);
void		my_help(char *buf, t_info *info);
int		help_com(t_info *info);
void		catch_sigint(int sig);
int		com_not_found(t_info *info);

#endif
