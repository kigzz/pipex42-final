/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:58:45 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/07 12:58:53 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*command;

	if (!path || !*path)
		return (NULL);
	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		command = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(command, F_OK) == 0)
			return (command);
		free(command);
		path++;
	}
	return (NULL);
}

void	child_first(t_pipex pipex, char *argv[], char *envp[])
{
	if (dup2(pipex.fd[1], STDOUT_FILENO) == -1)
		msg_perror(ERR_DUP2);
	close(pipex.fd[0]);
	if (dup2(pipex.infile, STDIN_FILENO) == -1)
		msg_perror(ERR_DUP2);
	pipex.cmd_arg = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_arg[0]);
	if (pipex.cmd == NULL)
	{
		free_child(&pipex);
		free_parent(&pipex);
		perror("Command not found from 1st child ");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}

void	child_second(t_pipex pipex, char *argv[], char *envp[])
{
	if (dup2(pipex.fd[0], STDIN_FILENO) == -1)
		msg_perror(ERR_DUP2);
	close(pipex.fd[1]);
	if (dup2(pipex.outfile, STDOUT_FILENO) == -1)
		msg_perror(ERR_DUP2);
	pipex.cmd_arg = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_arg[0]);
	if (pipex.cmd == NULL)
	{
		free_parent(&pipex);
		free_child(&pipex);
		perror("Command not found from 2nd child ");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_arg, envp);
}
