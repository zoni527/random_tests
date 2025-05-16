/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 10:42:36 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/20 12:21:20 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(const char *str)
{
	int	wc;

	if (!*str)
		return (0);
	wc = 0;
	while (*str)
	{
		if (*str == ' ' || (*str >= 9 && *str <= 13))
		{
			str++;
			continue ;
		}
		wc++;
		while (*str && !(*str == ' ' || (*str >= 9 && *str <= 13)))
			str++;
	}
	return (wc);
}
