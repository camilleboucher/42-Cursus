/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:19:41 by Camille           #+#    #+#             */
/*   Updated: 2026/02/08 09:53:53 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include <SDL2/SDL_scancode.h>

void	window_hook(int event, void *param);
void	key_hook(int key, void *param);

#endif
