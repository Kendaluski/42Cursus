/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:55:37 by jariza-o          #+#    #+#             */
/*   Updated: 2023/11/16 19:38:13 by jjaen-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

/* ERRORS */
enum				e_errors
{
	QUOTES,
	SLASH,
	SEMICOLON,
	CD,
	PWD,
	REDIRECTIONS,
	ENVS,
};

/* Token List */
enum				e_datatype
{
	VOID,
	NO_QUOTE,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
	PIPE,
	BUILTINS,
	COMMAND,
	ENVI_VAR,
	IN_RED,
	OUT_RED,
	HERE_DOC_RED,
	APPEND_RED,
};

typedef struct s_env
{
	char			*env;
	char			*content;
	int				i;
	int				n;
	int				aux;
}					t_env;

typedef struct s_pipe
{
	int				fds[2];
	int				prev_pipe;
	int				fd_in;
	int				fd_out;
}					t_pipe;

typedef struct s_token
{
	char			*str;
	enum e_datatype	type;
	struct s_token	*next;
	struct s_token	*prev;
}					t_token;

typedef struct s_data
{
	char			*prompt;
	char			**recieved;
	char			*line;
	t_token			*tokens;
	char			**env;
	char			*user;
	int				exit_status;
	pid_t			r_pid;
	t_pipe			spipe;
	int				vars_mod;
}					t_data;

t_data				g_data;

/* PROMPT */
int					ft_check_prompt(void);
/* ERRORS */
int					ft_initial_errors(void);
int					ft_errors(void);
/* Print error message */
void				ft_print_errors(int error);
/* Semicolon */
int					ft_check_semicolon(char **argv);
/* Slash */
int					ft_check_slash(char **argv);
/* Redirections */
int					ft_check_redirections(void);
/* Env Name */
int					ft_check_env_errors(char **received);

void				ft_cmds(void);
void				ft_cmds(void);
/* Built-ins */
/* Echo */
void				ft_echo(char **argv);
/* Cd */
void				ft_cd(char *path);

void				ft_pwd(void);

void				ft_print_matrix(char **matrix);

void				ft_export(char **argv);

void				ft_unset(char **argv);

void				ft_exit(void);

void				ft_system_cmds(char **command);

void				ft_signals(void);

char				**ft_clean_matrix(char **matrix);
void				ft_check_pipe(char *command);

char				*ft_get_cmdpath(char *cmd);

void				ft_pipe(char *line);
void				ft_signals(void);

/* SPLIT */
size_t				ft_words(char *s);
char				**ft_mini_split(char *s);
void				ft_printf_recivied(void);

/* Tokens */
t_token				*ft_init_token(void);
void				ft_tokenizer(void);
int					ft_is_command(t_token *token);
int					ft_is_env(t_token *token);
int					ft_is_double_quote(t_token *token);
void				ft_tokens_to_str(void);
void				ft_print_tokens(void);

/* Expand */
void				ft_expand_data(void);
void				ft_expand_env(t_token *tokens);
void				ft_expand_quotes(char *quote);
void				ft_len_change_env(int *len_env);

/* CLEAR FUNCTIONS */
/* Clear with Errors */
void				ft_clear_parser(int i);
/* Clear when finish the command */
void				ft_clear(void);
/* Clear Utils */
void				ft_clean_double_pointer(char **matrix);
void				ft_clear_tokens(void);

/* UTILS */
/* Print Matrix */
void				ft_printf_matrix(char **str);

char				*ft_get_env(char *str);

char				*ft_check_redir_pipe(char *line);

int					ft_exists(char *cmd);

char				**ft_dup_envs(char **env);

char				*ft_strup(char *str);

int					ft_strcmpup(char *str1, char *str2);

void				ft_sort_matrix(char **env);

void				ft_reasign(char *name, char *value);

void				ft_exec(char *cmdpath, char **command);

char				**ft_shell_lvl(char **env);

char				*ft_path(char **path, char *cmd);

void				ft_new_env(char *name, char *value);

void				ft_restore_fds(int stdout, int stdin);

int					ft_is_comma(t_token *tokens);

char				*ft_nl(char *line);

char				*ft_eof(char *limiter);

char				**ft_realloc_recieved(void);

int					ft_is_valid_name(char *name);

char				*ft_empty_var(char *name);

void				ft_export_vars(char *argv);

int					ft_exists_var(char *var);

char				**ft_split_var(char *argv);

char				*ft_check_redir_single(char *line);

void				ft_heredoc(char *limiter);

int					ft_double_redir_ck(char *line, char red);

char				*ft_in_redir(char *line);

char				*ft_out_redir(char *line);

#endif