/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 22:57:00 by f██████           #+#    #+#             */
/*   Updated: 2023/12/29 15:05:17 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./microshell.h"

int d_fd;

void putstr(char *str) {
	while (*str)
		write(2, str++, 1);
}

void cd(char **argv, int i) {
	if (strcmp(argv[i -1], "-") == 0 || i == 1)
		putstr("error: cd: bad arguments\n");
	else if (chdir(argv[i -1])) {
		putstr("error: cd: cannot change directory to ");
		putstr(argv[i -1]);
		putstr("\n");
	}
}

void execute(char **argv, char **env, int i) {
	int p_fd[2];
	int pid;
	int is_pipe = (argv[i] && strcmp(argv[i], "|") == 0);

	pipe(p_fd);
	pid = fork();
	if (pid == 0) {
		argv[i] = 0;
		dup2(d_fd, 0);
		close(d_fd);
		if (is_pipe) {
			dup2(p_fd[1], 1);
			close(p_fd[0]);
			close(p_fd[1]);
		}
		execve(*argv, argv, env);
		putstr("error: cannot execute ");
		putstr(*argv);
		putstr("\n");
	}
	if (is_pipe) {
		dup2(p_fd[0], d_fd);
		close(p_fd[0]);
		close(p_fd[1]);
	} else {
		dup2(0, d_fd);
	}
	waitpid(pid, 0, 0);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	int i = 0;
	
	d_fd = dup(0);
	while (argv[i] && argv[i +1]) {
		argv = &argv[i + 1];
		i = 0;
		while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
			i++;
		if (strcmp(*argv, "cd") == 0)
			cd(argv, i);
		else
			execute(argv, env, i);
	}
	dup2(0, d_fd);
	return (0);
}