/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:54:17 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/12 18:25:08 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <termios.h>
# include <term.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line_bonus.h"
# include <sys/stat.h>

typedef enum s_type
{
	CMD,
	ARGS,
	PIPE,
	INPUT_REDIRECTION,
	OUTPUT_REDIRECTION,
	HEREDOC,
	OUTPUT_REDIRECTION_APPEND,
	TYPE_UNKNOW,
}	t_type;

typedef struct s_token
{
	t_type			arg_type;
	char			*str;
	struct s_token	*next;
	bool			is_clean;
	bool			is_env;
	int				*exit_status;
}	t_token;

typedef struct s_tree
{
	t_token			*token;
	struct s_tree	*right;
	struct s_tree	*left;
	int				heredoc_fd;
}	t_tree;

typedef struct s_env
{
	char			*value;
	char			*key;
	struct s_env	*next;
	char			*full_str;
}	t_env;

typedef struct s_all
{
	t_tree			*tree;
	t_token			*token;
	int				exit_status;
	int				status;
	struct s_env	*env;
}	t_all;

extern volatile sig_atomic_t	g_signal;
int				is_valid_input(char *input);
bool			pipe_rdr_follow(t_token *tokens);
void			disable_echoctl(void);
void			enable_echoctl(void);
void			process_valid_input(t_all *all);
void			handle_null_input(char *input);
int				handle_input(t_all *all, char *input);
void			free_resources(t_all *all);
size_t			ft_strlen(char *s);
int				ft_strncmp(char *s1, char *s2, size_t n);
int				get_str_size(char *str);
int				get_str_size_redirection(char *str);
t_token			*lstnew_ms(void *str);
char			*strndup_ms(const char *s, int i);
int				skip_space(char *str);
bool			is_valid_cmd(char *cmd);
t_all			*tokenizer(char *input, int *exit_status, t_all *all);
t_token			*split_list(char *str);
bool			separator(char c);
void			free_list(t_token **tokens);
int				get_env_size(char *str);
int				skip_quotes(char *str);
int				quotes_check(char *str);
int				skip_simples_quotes(char *str);
t_all			*clean_tokens_env(t_all *all, int *i, int *j, char *res);
t_token			*process_token(t_token **head, int *exit_status, t_all *all);
t_token			*process_clean_token(t_token *token);
t_token			*process_clean_token(t_token *token);
t_token			*check_pipe_redirect(t_token *token);
t_type			get_redirection_type(char *str);
int				is_rdr(char *input);
bool			is_builtin(char *cmd);
bool			cmd_in_path(char *cmd);
bool			check_env_paths(char *cmd, char *path_env);
bool			direct_path_check(char *cmd);
bool			check_in_path(char *cmd, char *path);
t_all			*clean_tokens(t_all *all, int *exit_status);
t_all			*clean_tokens_process(t_all *all, char *res, int i, int j);
t_all			*clean_tokens_double_quote(t_all *all, int *i,
					int *j, char *res);
t_token			*clean_tokens_dollar(t_all *all, int *i, int *j, char *res);
t_all			*clean_tokens_env_process(t_all *all, int *i,
					int *j, char *res);
t_token			*clean_tokens_single_quote(t_token *tokens, int *i,
					int *j, char *res);
int				quotes_check_helper(char *str, int *i, int *q, int *dq);
int				quotes_check_double(char *str, int *i, int *dq);
int				quotes_check_single(char *str, int *i, int *q);
int				get_size(char *str, t_all *all, int i, int j);
int				get_size_env(char *str, int *i, int *j, t_all *all);
int				get_size_dquotes(char *str, int *i, int *j, int *exit_status);
int				get_size_dquotes_process(char *str, int *i, int *j);
int				get_size_dquotes_env(char *str, int *i, int *j);
int				get_size_quotes(char *str, int *i, int *j);
bool			check_env_paths_part1(char *path_env, char **path_copy_ptr);
t_tree			*ast(t_token *tokens);
void			split_token(t_token **left, t_token **right,
					t_token *tokens, t_token *op);
t_token			*find_op(t_token *tokens);
t_tree			*create_node(t_token *token);
void			free_tree(t_tree *tree);
bool			errors_managements(t_token *tokens, int *exit_status);
void			signals_setup(void);
void			sig_handler(int signum);
char			*ft_itoa(int nbr);
t_token			*clean_qm(t_all *all, int *j, char *res);
int				ft_int_strlen(int nbr);
bool			is_first_cmd(t_token *head, t_token *token);
void			exec(t_tree *tree, int *exit_status, t_all *all, t_env *env);
void			exec_output_redirection(t_tree *tree, int *exit_status,
					t_all *all, t_env *envp);
void			exec_input_redirection(t_tree *tree, int *exit_status,
					t_all *all, t_env *envp);
char			*get_cmd_path(char *cmd, t_env *env);
char			*get_direct_path(char *cmd);
char			*find_in_env_paths(char *cmd, char *path_env);
char			*find_in_env_paths_part1(char *path_env, char **path_copy_ptr);
char			*get_full_path(char *cmd, char *path);
void			do_cmd(t_tree *tree, int *exit_status, t_env *envp, t_all *all);
void			exec_cmd(char *cmd_path, t_token *token,
					t_env *envp, t_all *all);
void			exec_pipe(t_tree *tree, t_all *all, t_env *envp);
void			exec_heredoc(t_tree *tree, int *exit_status,
					t_all *all, t_env *envp);
void			exec_append_mode(t_tree *tree, int *exit_status,
					t_all *all, t_env *envp);
void			which_builtin(t_tree *tree, int *exit_status,
					t_all *all, t_env *envp);
bool			has_flag(t_token **token);
void			exec_echo(t_all *all, t_tree *tree, int *exit_status);
void			exec_cd(t_all *all, t_tree *tree,
					int *exit_status, t_env *envp);
t_env			*create_env_array_ms(int i, int key_len,
					t_env *head, char **envp);
char			*get_env_value(t_env *env, const char *key);
void			set_env_value(t_env **env, char *key, char *value);
void			exec_export(t_all *all, t_tree *tree, t_env **envp);
void			exec_unset(t_all *all, t_tree *tree, t_env **envp);
void			exec_env(t_all *all, t_env *envp);
int				ft_strcmp(const char *s1, const char *s2);
char			*get_full_str(char *key, char *value);
void			free_env(t_env **tokens);
void			free_all(t_all *all);
void			sigint_handler_prompt(int signum);
void			sigint_handler_default(int signum);
void			sigquit_handler(int signum);
void			signals_setup(void);
void			reset_signals_for_child(void);
void			signal_heredoc_setup(int signum);
void			set_sigint_heredoc(void);
t_env			*create_node_env(char *key, char *value);
char			**create_args(t_token *token);
char			**create_tab(t_env *envp);
int				count_env(t_env *envp);
void			free_tab(char **envc);
void			exec_exit(int *exit_status, t_all *all);
void			exec_pwd(t_all *all, int *exit_status);
void			add_env_to_end(t_env *env, t_env *new);
void			read_heredoc_loop(char *delim, int pipefd[2], t_all *all);
bool			is_heredoc_delim(char *input, char *delim);
int				check_path(t_env *envp, char *str);
void			prepare_all_heredocs(t_tree *tree, t_all *all);
bool			dot_or_slash(char *str);

#endif
