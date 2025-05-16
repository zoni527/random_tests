/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_memarena.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:09:51 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:13:03 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Creates new memarena struct with MEM_ARENA_SIZE bytes of heap memory.
 * <p>
 * Return NULL if malloc can't return heap memory.
 */
void	*ft_new_memarena(void)
{
	t_memarena	*arena;

	arena = malloc(sizeof(t_memarena));
	if (!arena)
		return (NULL);
	arena->heap_memory = malloc(MEM_ARENA_SIZE);
	if (!arena->heap_memory)
	{
		free(arena);
		return (NULL);
	}
	arena->capacity = MEM_ARENA_SIZE;
	arena->bytes_used = 0;
	arena->next = NULL;
	return (arena);
}
