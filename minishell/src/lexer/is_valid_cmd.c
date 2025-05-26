/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 12:02:49 by ctravers42        #+#    #+#             */
/*   Updated: 2025/04/14 09:08:47 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_in_path(char *cmd, char *path)
{
	char		full_path[1024];
	struct stat	buffer;

	if (cmd == NULL || cmd[skip_space(cmd)] == (int)ft_strlen(cmd)
		|| cmd[0] == '\0')
		return (false);
	ft_strlcpy(full_path, path, sizeof(full_path));
	if (full_path[ft_strlen(full_path) - 1] != '/')
		ft_strlcat(full_path, "/", sizeof(full_path));
	ft_strlcat(full_path, cmd, sizeof(full_path));
	if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		return (true);
	return (false);
}

bool	direct_path_check(char *cmd)
{
	struct stat	buffer;

	if (ft_strchr(cmd, '/') != NULL)
		return (stat(cmd, &buffer) == 0 && (buffer.st_mode & S_IXUSR));
	return (false);
}

bool	check_env_paths(char *cmd, char *path_env)
{
	char	*path_copy;
	char	*current;
	char	*next_colon;
	bool	result;

	if (!check_env_paths_part1(path_env, &path_copy))
		return (false);
	current = path_copy;
	result = false;
	while (current && *current)
	{
		next_colon = ft_strchr(current, ':');
		if (next_colon)
			*next_colon = '\0';
		if (check_in_path(cmd, current))
		{
			result = true;
			break ;
		}
		if (next_colon)
			current = next_colon + 1;
		else
			break ;
	}
	return (free(path_copy), result);
}

bool	cmd_in_path(char *cmd)
{
	char	*path_env;

	if (direct_path_check(cmd))
		return (true);
	path_env = getenv("PATH");
	if (path_env == NULL)
		return (false);
	return (check_env_paths(cmd, path_env));
}

bool	is_builtin(char *cmd)
{
	int		i;
	char	*builtins[7];

	builtins[0] = "echo";
	builtins[1] = "cd";
	builtins[2] = "pwd";
	builtins[3] = "export";
	builtins[4] = "unset";
	builtins[5] = "env";
	builtins[6] = "exit";
	i = 0;
	while (i < 7)
	{
		if (strncmp(builtins[i], cmd, ft_strlen(cmd)) == 0)
			return (true);
		i++;
	}
	return (false);
}
