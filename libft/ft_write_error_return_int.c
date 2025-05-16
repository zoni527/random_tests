/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_error_return_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:23:40 by jvarila           #+#    #+#             */
/*   Updated: 2025/03/20 12:16:06 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_write_error_return_int(char *error_message, int return_value)
{
	ft_putendl_fd(error_message, STDERR_FILENO);
	return (return_value);
}
