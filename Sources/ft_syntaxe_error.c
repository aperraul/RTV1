/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syntaxe_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/17 12:12:47 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/17 14:15:23 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Header/header.h"

int		ft_syntaxe_error(int line_nb)
{
	ft_putstr("\33[31m error: synthaxe line\033[0m ");
	ft_putnbr(line_nb);
	ft_putchar('\n');
	return (1);
}
