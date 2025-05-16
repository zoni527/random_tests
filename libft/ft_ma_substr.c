/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ma_substr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:38:47 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:40:35 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ma_substr(t_memarena *arena, char const *s,
			unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	substr_len;

	s_len = ft_strlen(s);
	if (start >= s_len)
		return ((char *)ft_ma_calloc(arena, 1, sizeof(char)));
	else
		substr_len = ft_strlen(s + start);
	if (substr_len > len)
		substr_len = len;
	substr = ft_ma_malloc(arena, (substr_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, substr_len + 1);
	return (substr);
}
