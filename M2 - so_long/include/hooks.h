/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:19:41 by Camille           #+#    #+#             */
/*   Updated: 2026/02/03 14:46:38 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# define KEY_ESCAPE 41

void	window_hook(int event, void *param);
void	key_hook(int key, void *param);

#endif
