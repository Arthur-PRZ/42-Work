/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artperez <artperez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:42:46 by artperez          #+#    #+#             */
/*   Updated: 2025/04/23 12:35:26 by artperez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_full_path(char *cmd, char *path)
{
	char		full_path[1024];
	struct stat	buffer;
	char		*result;

	if (cmd == NULL || cmd[skip_space(cmd)] == (int)ft_strlen(cmd)
		|| cmd[0] == '\0')
		return (NULL);
	ft_strlcpy(full_path, path, sizeof(full_path));
	if (full_path[ft_strlen(full_path) - 1] != '/')
		ft_strlcat(full_path, "/", sizeof(full_path));
	ft_strlcat(full_path, cmd, sizeof(full_path));
	if (stat(full_path, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
	{
		result = ft_strdup(full_path);
		return (result);
	}
	return (NULL);
}

char	*find_in_env_paths_part1(char *path_env, char **path_copy_ptr)
{
	char	*path_copy;

	path_copy = ft_strdup(path_env);
	if (!path_copy)
		return (NULL);
	*path_copy_ptr = path_copy;
	return (path_copy);
}

char	*find_in_env_paths(char *cmd, char *path_env)
{
	char	*path_copy;
	char	*current;
	char	*next_colon;
	char	*cmd_path;

	if (!find_in_env_paths_part1(path_env, &path_copy))
		return (NULL);
	current = path_copy;
	while (current && *current)
	{
		next_colon = ft_strchr(current, ':');
		if (next_colon)
			*next_colon = '\0';
		cmd_path = get_full_path(cmd, current);
		if (cmd_path)
		{
			free(path_copy);
			return (cmd_path);
		}
		if (next_colon)
			current = next_colon + 1;
		else
			break ;
	}
	return (free(path_copy), NULL);
}

char	*get_direct_path(char *cmd)
{
	struct stat	buffer;
	char		*result;

	if (ft_strchr(cmd, '/') != NULL)
	{
		if (stat(cmd, &buffer) == 0 && (buffer.st_mode & S_IXUSR))
		{
			result = ft_strdup(cmd);
			return (result);
		}
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, t_env *env)
{
	char	*path_env;
	char	*cmd_path;

	cmd_path = get_direct_path(cmd);
	if (cmd_path)
		return (cmd_path);
	path_env = get_env_value(env, "PATH");
	if (path_env == NULL)
		return (NULL);
	return (find_in_env_paths(cmd, path_env));
}
