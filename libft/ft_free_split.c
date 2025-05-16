/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:49:57 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/20 12:18:00 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char ***words_ptr)
{
	char	**words;

	words = *words_ptr;
	if (!words)
		return ;
	while (*words)
		free(*(words++));
	free(*words_ptr);
	*words_ptr = NULL;
}
