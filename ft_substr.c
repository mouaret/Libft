/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:38:48 by souaret           #+#    #+#             */
/*   Updated: 2024/05/25 17:24:19 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;

	if (ft_strlen(s) < start)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		else
			return (str);
	}
	new_len = ft_strlen(s + start);
	if (!(new_len < len))
		new_len = len;
	str = (char *)malloc(new_len + 1);
	if (!str)
		return (NULL);
	str[new_len] = 0;
	while (new_len-- > 0)
		str[new_len] = s[start + new_len];
	return (str);
}
