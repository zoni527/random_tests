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

#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include "libft.h"
#include <stdio.h>

#if 1

typedef struct s_channels
{
	uint8_t	a;
	uint8_t	b;
	uint8_t	g;
	uint8_t	r;
}	t_channels;

enum e_channel_type
{
	A,
	B,
	G,
	R,
};

#else

typedef struct s_channels
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	uint8_t	a;
}	t_channels;

enum e_channel_type
{
	R,
	G,
	B,
	A,
};

#endif

typedef union u_8bit_color
{
	uint32_t	rgba;
	t_channels	channel;
	uint8_t		ch[4];
}	t_8bit_color;

typedef struct s_float_color
{
	float	r;
	float	g;
	float	b;
	float	a;
}	t_float_color;

t_float_color	color_8bit_to_float(t_8bit_color c)
{
	t_float_color	f;

	f.r = c.channel.r / 255.0f;
	f.g = c.channel.g / 255.0f;
	f.b = c.channel.b / 255.0f;
	f.a = c.channel.a / 255.0f;
	return (f);
}

float	clamp(float	f, float min, float max)
{
	if (min > max)
		return (0);
	if (f < min)
		return (min);
	if (f > max)
		return (max);
	return (f);
}

t_8bit_color	color_float_to_8bit(t_float_color f)
{
	t_8bit_color	c;

	c.channel.r = roundf(clamp(f.r, 0, 1) * 255.0f);
	c.channel.g = roundf(clamp(f.g, 0, 1) * 255.0f);
	c.channel.g = roundf(clamp(f.b, 0, 1) * 255.0f);
	c.channel.g = roundf(clamp(f.a, 0, 1) * 255.0f);
	return (c);
}

// uint32_t	endian_adjustement(uint32_t num)
// {
// 	bool	big_endian;
// 	uint8_t	temp;
// 	uint8_t	*bytes;
// 
// 	temp = 0x000000ff;
// 	bytes = (void *)&temp;
// 	big_endian = false;
// 	if (bytes[0] == 0)
// 		big_endian = true;
// 	if (big_endian)
// 		 return (num);
// 	temp = num;
// 	bytes = (void *)&num;
// 	temp = bytes[0];
// 	bytes[0] = bytes[3];
// 	bytes[3] = temp;
// 	temp = bytes[1];
// 	bytes[1] = bytes[2];
// 	bytes[2] = temp;
// 	return (num);
// }

int	main(int argc, char *argv[])
{
	t_8bit_color	c;
	t_float_color	f;

	ft_bzero(&c, sizeof(t_8bit_color));
	if (argc == 2)
	{
		c.rgba = ft_atohex(argv[1]);
		if (c.rgba <= 0xffffff)
			c.rgba = (c.rgba << 8) | 0x000000ff;
	}
	f = color_8bit_to_float(c);
	ft_printf("\nrgba in hex:		0x%x\n\n", c.rgba);
	ft_printf("channel.r:		%u\n", c.channel.r);
	ft_printf("channel.g:		%u\n", c.channel.g);
	ft_printf("channel.b:		%u\n", c.channel.b);
	ft_printf("channel.a:		%u\n\n", c.channel.a);
	ft_printf("ch[R]:			%x\n", c.ch[R]);
	ft_printf("ch[G]:			%x\n", c.ch[G]);
	ft_printf("ch[B]:			%x\n", c.ch[B]);
	ft_printf("ch[A]:			%x\n\n", c.ch[A]);
	ft_printf ("red bitshifted:		%x\n", (c.rgba >> 24) & 0x000000ff);
	ft_printf ("blue bitshifted:	%x\n", (c.rgba >> 16) & 0x000000ff);
	ft_printf ("green bitshifted:	%x\n", (c.rgba >> 8) & 0x000000ff);
	ft_printf ("alpha bitshifted:	%x\n\n", (c.rgba >> 0) & 0x000000ff);
	printf("float color red:	%f\n", f.r);
	printf("float color green:	%f\n", f.g);
	printf("float color blue:	%f\n", f.b);
	printf("float color alpha:	%f\n\n", f.a);
	return (0);
}
