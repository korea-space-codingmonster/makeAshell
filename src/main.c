/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:09:04 by napark            #+#    #+#             */
/*   Updated: 2021/12/13 01:03:05 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int routine(void)
{
    while (true)
    {
        
    } 
}

static int handle_flags(int argc, char *argv)
{
    int exit_code;

    if (argc != 3 || ft_strcmp(argv[1], "-c") != 0)
	{
		ft_putstr_fd("Usage: ./minishell [Flag] \"[Command]\"\n", STDERR_FILENO);
		ft_putstr_fd("\t-c\tExecute Command without promot\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
    exit_code = lexer(argv[2]);
    free_env(get_envv);
    return (exit_code);
}

static void handle_signals(void)
{
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);
}

int main(int    argc, char *argv[], char *envp[])//, char *argv[], char *envp[])
{
    t_env   *envv;
    
    handle_signals();
    envv = init_envv(envp);
    if (envv == NULL)
        return (EXIT_FAILURE);
    set_envp(envp);//
    set_envv(envv);
    /*환경변수 setting*/
    if (argc != 1)
        return (handle_flags(argc, argv));
    if (routine() == EXIT_FAILURE)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}