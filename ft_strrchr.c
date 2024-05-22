/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 21:05:28 by souaret           #+#    #+#             */
/*   Updated: 2024/05/22 21:17:51 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	const char *src;

	src = s;
	while (*src != 0)
		src++;
	while (s != src && *src != c)
		src--;
	if (*src == c)
		return ((char *)src);
//	if (c == '\0')
//		return ((char *)s);
	else
		return (0);
}
