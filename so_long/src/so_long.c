/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Camille <private_mail>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 15:45:41 by Camille           #+#    #+#             */
/*   Updated: 2026/01/19 18:40:43 by Camille          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "so_long.h"

static void	create_context_and_window(t_ctx *ctx, t_window *win);
static void	free_window(t_window *win);

int	main(void)
{
	t_ctx		ctx;
	t_window	system;

	create_context_and_window(&ctx,&system);
	mlx_loop(system.mlx);
	free_window(&system);
	return (0);
}

static void	create_context_and_window(t_ctx *ctx, t_window *win)
{
	win->mlx = mlx_init();
	win->info = (mlx_window_create_info){0};
	win->info.title = WINDOW_TITLE;
	win->info.width = WINDOW_WIDTH;
	win->info.height = WINDOW_HEIGHT;
	win->win = mlx_new_window(win->mlx, &win->info);
	ctx->win = win;
	ctx->render = mlx_new_image(win->mlx, 100, 100);
}

static void	free_window(t_window *win)
{
	mlx_destroy_window(win->mlx, win->win);
	mlx_destroy_context(win->mlx);
}

/*
	mlx_image				target;
	mlx_window_create_info	target_info;
	mlx_window				target_win;

	mlx = mlx_init();
	win_info = (mlx_window_create_info){0};
	win_info.title = "SO_LONG";
	win_info.width = 400;
	win_info.height = 400;
	win_info.is_fullscreen = false;
	win = mlx_new_window(mlx, &win_info);
	target = mlx_new_image(mlx, 100, 100);
	target_info = (mlx_window_create_info){0};
	target_info.render_target = target;
	target_win = mlx_new_window(mlx, &target_info);

	    {
        // All of this will be rendered in `target`
        mlx_clear_window(mlx, target_win, (mlx_color){ .rgba = 0xC16868FF });
        mlx_string_put(mlx, target_win, 10, 10, (mlx_color){ .rgba = 0xFF2066FF }, "text");
        mlx_pixel_put(mlx, target_win, 20, 40, (mlx_color){ .rgba = 0xFF0000FF });
    }

	mlx_put_image_to_window(mlx, win, target, 10, 10);

	mlx_loop(mlx);

	mlx_destroy_window(mlx, target_win);
	mlx_destroy_image(mlx, target);
	mlx_destroy_window(mlx, win);
	mlx_destroy_context(mlx);
	return (0);
}*/

//mlx_set_window_fullscreen(mlx, win, true);
