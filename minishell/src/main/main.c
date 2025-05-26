/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 13:35:18 by ctravers42        #+#    #+#             */
/*   Updated: 2025/05/12 16:37:50 by ctravers42       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	update_env_value(t_env *current, int shlvl)
{
	free(current->value);
	current->value = ft_itoa(shlvl);
	free(current->full_str);
	current->full_str = get_full_str(current->key, current->value);
}

void	update_shlvl(t_env **env)
{
	t_env	*current;
	int		shlvl;
	t_env	*new_shlvl;

	shlvl = 1;
	current = *env;
	while (current)
	{
		if (!ft_strcmp(current->key, "SHLVL"))
		{
			shlvl = ft_atoi(current->value) + 1;
			update_env_value(current, shlvl);
			return ;
		}
		current = current->next;
	}
	new_shlvl = malloc(sizeof(t_env));
	if (!new_shlvl)
		return ;
	new_shlvl->key = ft_strdup("SHLVL");
	new_shlvl->value = ft_strdup("1");
	new_shlvl->full_str = get_full_str(new_shlvl->key, new_shlvl->value);
	new_shlvl->next = *env;
	*env = new_shlvl;
}

void	init_shell(t_all **all, char *envp[])
{
	*all = malloc(sizeof(t_all));
	(*all)->env = create_env_array_ms(0, 0, NULL, envp);
	update_shlvl(&(*all)->env);
	(*all)->exit_status = 0;
}

int	main_loop(t_all *all)
{
	char	*input;
	int		exit_flag;

	exit_flag = 0;
	while (1)
	{
		signal(SIGINT, sigint_handler_prompt);
		input = readline("✧ minishell$ ");
		all->tree = NULL;
		if (input == NULL)
		{
			handle_null_input(input);
			exit_flag = 1;
			break ;
		}
		handle_input(all, input);
		free(input);
	}
	return (exit_flag);
}

int	main(int argc, char **argv, char *envp[])
{
	t_all	*all;
	int		exit_code;
	int		exit_flag;

	(void)argc;
	(void)argv;
	(void)envp;
	signals_setup();
	init_shell(&all, envp);
	exit_flag = main_loop(all);
	exit_code = all->exit_status;
	free_resources(all);
	return (exit_code);
}
