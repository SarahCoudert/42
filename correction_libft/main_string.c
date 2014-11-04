/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:40:00 by scoudert          #+#    #+#             */
/*   Updated: 2014/11/04 11:42:03 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"

int		main(void)
{
	char character;
	char strings[256];

	printf("What character do you want to use for functions who uses characters ?\n");
	scanf(" %c", &character);
	printf("What sentence do you want to use for functions who uses strings ?\n");
	scanf("%s ", &strings[0]);
	printf("ft_putchar : ");
	ft_putchar(character);
	printf("\nft_putstr :");
	ft_putstr(strings);
	return (0);
}
