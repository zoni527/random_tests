/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_memarena.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:24:26 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:26:42 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Frees all but the primary arena node, sets heap memory to 0 and resets
 * struct member variables.
 *
 * @param arena	Pointer to primary memarena node
 */
void	ft_reset_memarena(t_memarena *arena)
{
	if (arena->next)
		ft_free_memarena(arena->next);
	ft_bzero(arena->heap_memory, MEM_ARENA_SIZE);
	arena->capacity = MEM_ARENA_SIZE;
	arena->bytes_used = 0;
	arena->next = NULL;
}
