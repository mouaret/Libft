/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:01:14 by souaret           #+#    #+#             */
/*   Updated: 2024/05/23 21:48:39 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	total_size;

	if (nmemb <= 0 || size <= 0)
		return (NULL);
	total_size = nmemb * size;
	if ((total_size / size) != nmemb)
		return (NULL);
	mem = malloc(total_size);
	if (mem == NULL)
		return (NULL);
	ft_memset(mem, 0, total_size);
	return (mem);
}
