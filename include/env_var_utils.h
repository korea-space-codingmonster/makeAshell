/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: napark <napark@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:04:54 by napark            #+#    #+#             */
/*   Updated: 2021/12/12 23:55:00 by napark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_VAR_UTILS_H
# define ENV_VAR_UTILS_H

/*환경변수 저장 구조체*/
typedef struct s_env
{
    char    **envp;
    char    **env_var;
    char    **pwd;
    char    **oldpwd;
}   t_env;

//get //set
void	set_envv(t_env *envv);
t_env	*get_envv(void);
char	**get_env_var(void);


#endif