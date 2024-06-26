/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:22:58 by souaret           #+#    #+#             */
/*   Updated: 2024/05/25 17:34:07 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	cc;

	cc = c;
	while (*s && *s != cc)
		s++;
	if (*s)
		return ((char *)s);
	if (cc == '\0')
		return ((char *)s);
	else
		return (0);
}
