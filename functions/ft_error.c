/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 13:45:56 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/07 13:46:06 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	msg_perror(char *err)
{
	perror(err);
	exit(1);
}

int	msg(char *err)
{
	ft_putstr_fd(err, 2);
	return (1);
}

void	envp_check(char **err)
{
	if (!*err)
	{
		ft_putstr_fd("Environment Path not found\n", 2);
		exit(1);
	}
}

void	fork_init1(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
	{
		perror(ERR_FORK);
		exit(1);
	}
}

void	fork_init2(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
	{
		perror(ERR_FORK);
		exit(1);
	}
}
