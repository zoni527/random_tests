/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_whitespace_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:10:50 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/02 11:15:48 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_is_whitespace_string(const char *str)
{
	size_t	i;

	if (!str)
		return (false);
	i = 0;
	while (ft_isspace(str[i]))
		++i;
	if (!str[i])
		return (true);
	return (false);
}
