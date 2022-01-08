/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 12:54:22 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/07 18:00:51 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "pipex.h"

void	close_pipes(t_pipex *pipex)
{
	close(pipex->infile);
	close(pipex->outfile);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	if (pipex->infile != -1)
		waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	envp_check(envp);
	if (argc != 5)
		return (msg(ERR_INPUT));
	if (pipe(pipex.fd) == -1)
		msg_perror(ERR_PIPE);
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile == -1)
		perror(ERR_INFILE);
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex.outfile == -1)
		msg_perror(ERR_OUTFILE);
	pipex.path = get_path(envp);
	pipex.cmd_path = ft_split(pipex.path, ':');
	if (pipex.infile != -1)
		fork_init1(&pipex);
	if (pipex.pid1 == 0 && pipex.infile != -1)
		child_first(pipex, argv, envp);
	fork_init2(&pipex);
	if (pipex.pid2 == 0)
		child_second(pipex, argv, envp);
	close_pipes(&pipex);
	free_parent(&pipex);
	return (0);
}
