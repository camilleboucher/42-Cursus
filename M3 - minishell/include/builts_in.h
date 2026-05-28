/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_in.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lifranco <lifranco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 13:13:34 by lifranco          #+#    #+#             */
/*   Updated: 2026/05/12 16:02:35 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTS_IN_H
# define BUILTS_IN_H

/* FT_ECHO_C */
int		ft_echo(t_minishell *sh, t_cmd *cmd);

/* FT_CD_C */
int		ft_cd(t_minishell *sh, t_cmd *cmd);

/* FT_PWD_C */
int		ft_pwd(t_minishell *sh, t_cmd *cmd);

/* FT_EXPORT_C */
int		ft_export(t_minishell *sh, t_cmd *cmd);

/* SET_ENV_C */
void	ft_set_env(char *var, t_minishell *shell);

/* FT_EXIT_C */
int		ft_exit(t_minishell *sh, t_cmd *cmd);

/* FT_ENV_C */
int		ft_env(t_minishell *sh, t_cmd *cmd);

/*FT_UNSET_C */
int		ft_unset(t_minishell *sh, t_cmd *cmd);

/* UNSET_C */
void	ft_unset_env(char *var, t_minishell *sh);

/* HANDLE_APPEND_C */
void	handle_append(char *var, t_minishell *sh);

/* APPENNDING_C */
int		append(char *env, char *var, char *name, t_minishell *sh);

// built_in/helpers/get_argc.c
int		get_argc(char **argv);

// built_in/helpers/ft_getenv.c
char	*ft_getenv(const char *name, const char **envp);

// built_in/helpers/handling_pipes_for_cd.c
bool	handle_pipes_for_cd(t_minishell *sh, int nb_cmds, char **argv);

#endif
