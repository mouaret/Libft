/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 11:47:33 by souaret           #+#    #+#             */
/*   Updated: 2024/05/23 13:22:44 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	// Check for null pointers
	if (dest == NULL || src == NULL) {
		return NULL;
	}
	if (n == 0) {
		return dest; // No change needed for empty copy
  	}

	// Handle overlapping memory regions
	if (!(dest < src && dest + n > src))
	{
		// Copy backwards to avoid overwriting source data
		char *d = (char *)dest + n - 1;
		const char *s = (const char *)src + n - 1;
		while (n-- > 0)
			*d-- = *s--;
	} 
	else 
	{
		// Simple copy for non-overlapping regions
		char *d = (char *)dest;
		const char *s = (const char *)src;
		while (n-- > 0)
			*d++ = *s++;
	}
	return dest;
}
