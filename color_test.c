/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 20:24:53 by jvarila           #+#    #+#             */
/*   Updated: 2025/05/15 23:54:43 by jvarila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdint.h>
#include "libft.h"

typedef struct s_channels
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_channels;

typedef union	u_color
{
	uint32_t	rgba;
	t_channels	channels;
	uint8_t		ch[4];
}	t_color;

enum e_channel_type
{
	R,
	G,
	B,
	A,
};

uint32_t	endian_adjustement(uint32_t num)
{
	bool	big_endian;
	uint8_t	temp;
	uint8_t	*bytes;

	temp = 0x000000ff;
	bytes = (void *)&temp;
	big_endian = false;
	if (bytes[0] == 0)
		big_endian = true;
	if (big_endian)
		 return (num);
	temp = num;
	bytes = (void *)&num;
	temp = bytes[0];
	bytes[0] = bytes[3];
	bytes[3] = temp;
	temp = bytes[1];
	bytes[1] = bytes[2];
	bytes[2] = temp;
	return (num);
}

int	main(int argc, char *argv[])
{
	t_color	c;

	ft_bzero(&c, sizeof(t_color));
	if (argc == 2)
		c.rgba = endian_adjustement(ft_atohex(argv[1]));
	ft_printf("rgba:		%x\n", endian_adjustement(c.rgba));
	ft_printf("channels.r:	%x\n", c.channels.r);
	ft_printf("channels.g:	%x\n", c.channels.g);
	ft_printf("channels.b:	%x\n", c.channels.b);
	ft_printf("channels.a:	%x\n", c.channels.a);
	ft_printf("ch[0]:		%x\n", c.ch[R]);
	ft_printf("ch[1]:		%x\n", c.ch[G]);
	ft_printf("ch[2]:		%x\n", c.ch[B]);
	ft_printf("ch[3]:		%x\n", c.ch[A]);
	return (0);
}
