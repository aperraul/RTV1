/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperraul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 19:21:31 by aperraul          #+#    #+#             */
/*   Updated: 2016/06/15 15:54:31 by aperraul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int		result;
	int		i;
	int		negative;

	i = 0;
	negative = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\t' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result = result + str[i] - '0';
		i++;
	}
	return (result * negative);
}

double		ft_atoid(char *str)
{
	double	result;
	int		i;
	char	*a;

	i = -1;
	a = NULL;
	result = 0;
	while (str[++i] != '.')
		if (str[i] == '\0')
			return (ft_atoi(str));
	a = &str[i + 1];
	i = -1;
	while (a[++i])
	{
		if (!ft_isdigit(a[i]))
			return (ft_atoi(str));
	}
	result = ft_atoi(str);
	if (result < 0)
		result -= (double)ft_atoi(a) / (double)ft_power(10, ft_strlen(a));
	else
		result += (double)ft_atoi(a) / (double)ft_power(10, ft_strlen(a));
	return (result);
}
