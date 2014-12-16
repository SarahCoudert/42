/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrimald <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:33:23 by mgrimald          #+#    #+#             */
/*   Updated: 2014/11/14 19:37:44 by mgrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	int				dif;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	dif = 0;
	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		dif = str1[i] - str2[i];
		if (dif != 0)
			return (dif);
		i++;
	}
	return (str1[i] - str2[i]);
}
