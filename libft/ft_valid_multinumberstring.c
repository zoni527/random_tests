/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_multinumberstring.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 08:58:28 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/20 12:19:53 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_valid_multinumberstring(const char *str)
{
	int	sign;

	if (*str == '\0')
		return (false);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (!*str)
		return (false);
	while (*str)
	{
		sign = 1;
		if ((*str == '-' || *str == '+') && *(str + 1))
			if (*(str++) == '-')
				sign = -1;
		if (!ft_isdigit(*str))
			return (false);
		if ((sign > 0 && ft_atol(str) > INT_MAX)
			|| (sign < 0 && ft_atol(str) > -(long)INT_MIN))
			return (false);
		while (ft_isdigit(*str))
			str++;
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
	}
	return (true);
}
