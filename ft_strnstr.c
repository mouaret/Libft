/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:52:44 by souaret           #+#    #+#             */
/*   Updated: 2024/05/21 18:01:50 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr2(char *big, char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] != '\0' && little[j] != '\0' && (j < len))
		{
			if (big[i + j] == little[j])
				j++;
			else
			{
				j = 0;
				i++;
			}
		}
		if (j == len)
			return (big + i);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen((char *)little);
	if (n_len == 0 || big == little)
		return ((char *)big);
	return (ft_strnstr2((char *)big, (char *)little, len));
}
