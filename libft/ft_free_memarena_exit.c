/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_memarena_exit.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:16:33 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/21 12:19:44 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Prints error message and frees linked list of memory arenas.
 *
 * @param arena	Pointer to primary memarena node
 * @param msg	Error message to print before exit
 */
void	ft_free_memarena_exit(t_memarena *arena, const char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_free_memarena(arena);
	exit(ERROR_ALLOC);
}
