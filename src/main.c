/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:09:04 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 23:51:13 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
        return (handl_flags(argc, argv));
    if (routine() == EXIT_FAILURE);
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}