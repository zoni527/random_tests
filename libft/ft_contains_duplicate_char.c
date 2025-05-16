/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_duplicate_char.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:13:30 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/20 12:18:56 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_contains_duplicate_char(const char *str)
{
	if (!str)
		return (false);
	while (*str)
	{
		if (ft_strchr(str + 1, *str))
			return (true);
		str++;
	}
	return (false);
}
