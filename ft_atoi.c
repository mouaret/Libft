/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:34:34 by souaret           #+#    #+#             */
/*   Updated: 2024/05/20 14:54:49 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	val;
	int	sign;

	while (*str == ' ')
		str++;
	sign = 1;
	if (*str == 0)
		return (0);
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	val = 0;
	while (*str)
		if (*str >= '0' && *str <= '9')
			val = val * 10 + *str++ - '0';
	else
		break ;
	val = val * sign;
	return (val);
}
