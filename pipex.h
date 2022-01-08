/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpouchep <bpouchep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:08:06 by bpouchep          #+#    #+#             */
/*   Updated: 2022/01/04 16:08:37 by bpouchep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/* perror */
# include <stdio.h>

# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_OUTFILE "OUTFILE "
# define ERR_INFILE "INFILE "
# define ERR_PIPE "PIPE "
# define ERR_FORK "FORK "
# define ERR_DUP2 "DUP2 "

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	*path;
	char	*cmd;
	char	**cmd_path;
	char	**cmd_arg;
}t_pipex;

char	*ft_strchr(const char *str, int c);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	free_parent(t_pipex *pipex);
void	free_child(t_pipex *pipex);
char	*get_path(char **envp);
void	child_first(t_pipex pipex, char *argv[], char *envp[]);
void	child_second(t_pipex pipex, char *argv[], char *envp[]);
void	msg_perror(char *err);
int		msg(char *err);
void	envp_check(char **err);
void	fork_init1(t_pipex *pipex);
void	fork_init2(t_pipex *pipex);

#endif
