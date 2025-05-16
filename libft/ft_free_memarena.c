/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memarena.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:20:17 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:22:12 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Goes through the linked list of arenas, freeing each node.
 * <p>
 * Important to call with the root node when trying to feel all used memory.
 *
 * @param arena	Pointer to primary memarena node
 */
void	*ft_free_memarena(t_memarena *arena)
{
	t_memarena	*current;
	t_memarena	*next;

	current = arena;
	while (current)
	{
		next = current->next;
		free(current->heap_memory);
		free(current);
		current = next;
	}
	return (NULL);
}
