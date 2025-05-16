/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ma_strjoin.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:27:28 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:29:27 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ma_strjoin(t_memarena *arena, char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	combined_len;

	combined_len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = ft_ma_malloc(arena, (combined_len + 1) * sizeof(char));
	if (!joined_str)
		return (NULL);
	joined_str[0] = '\0';
	ft_strlcat(joined_str, s1, combined_len + 1);
	ft_strlcat(joined_str, s2, combined_len + 1);
	return (joined_str);
}
