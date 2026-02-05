/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 14:19:02 by Camille           #+#    #+#             */
/*   Updated: 2026/02/03 14:46:44 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "hooks.h"

void	window_hook(int event, void *param)
{
    if(event == 0)
        mlx_loop_end((mlx_context)param);
}

void	key_hook(int key, void *param)
{
    if(key == KEY_ESCAPE)
        mlx_loop_end((mlx_context)param);
}
