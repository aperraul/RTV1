/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sdl_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 11:08:22 by aperraul          #+#    #+#             */
/*   Updated: 2016/08/10 14:22:16 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

t_env	*ft_sdl_init(int h, int w, char *title)
{
	t_env *env;

	if (!(env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (NULL);
	env->withd = w;
	env->height = h;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) || 
			!(env->win = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
					w, h, SDL_WINDOW_SHOWN)) ||
			!(env->img = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0)))
	{
		SDL_FreeSurface(env->img);
		SDL_FreeSurface(env->img);
		SDL_Quit();
		ft_memdel((void **)&env);
	}
	return (env);
}
