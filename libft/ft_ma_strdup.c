/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ma_strdup.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:36:41 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:38:05 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ma_strdup(t_memarena *arena, const char *s)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = ft_ma_malloc(arena, (len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, s, (len + 1) * sizeof (char));
	return (str);
}
