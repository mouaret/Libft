/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:23:03 by souaret           #+#    #+#             */
/*   Updated: 2024/05/29 17:07:16 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*str;

	if (fd == 0)
		return ;
	str = ft_itoa(n);
	if (str == NULL)
		return ;
	n = ft_strlen(str);
	write(fd, str, n);
	free(str);
}
