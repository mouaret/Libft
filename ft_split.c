/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <souaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:51:41 by souaret           #+#    #+#             */
/*   Updated: 2024/05/29 15:32:28 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*************************************
#include <stdio.h>	// to be removed
	1- Calculer le nombre de segments
	2- Allocation du vecteur
	3- Parsing des segments
*************************************/
static int	ft_count_segs(char *s, char c)
{
	size_t	count_word;
	int		in_word;

	count_word = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else
		{
			if (!in_word)
				count_word++;
			in_word = 1;
		}
		s++;
	}
	return (count_word);
}

static char	*ft_split_cpy(const char *s, int deb, int fin)
{
	int		n;
	int		i;
	char	*str;

	n = fin - deb + 1;
	str = malloc(n + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (n--)
	{
		str[i] = s[deb + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_vars_init(t_split_vars *v)
{
	v->in_word = 0;
	v->deb = 0;
	v->fin = 0;
}

static void	ft_split_extract_n(char const *s, char c, char **vect, int *pos_seg)
{
	t_split_vars	s_v;

	ft_vars_init(&s_v);
	while (s[s_v.fin])
	{
		if (s[s_v.fin] == c)
		{
			if (s_v.in_word)
				vect[pos_seg[0]++] = \
				ft_split_cpy(s, s_v.deb, s_v.fin - 1);
			if (s_v.in_word)
				s_v.in_word = 0;
		}
		else
		{
			if (!s_v.in_word)
				s_v.deb = s_v.fin;
			if (!s_v.in_word)
				s_v.in_word = 1;
		}
		s_v.fin++;
	}
	if (s_v.in_word)
		vect[pos_seg[0]++] = ft_split_cpy(s, s_v.deb, s_v.fin - 1);
	vect[pos_seg[0]] = 0;
}

char	**ft_split(char const *s, char c)
{
	size_t	n;
	char	**vect;
	int		pos_seg;

	vect = NULL;
	n = ft_count_segs((char *)s, c);
	vect = (char **)malloc(sizeof(char *) * (n + 1));
	if (!vect)
		return (NULL);
	pos_seg = 0;
	ft_split_extract_n(s, c, vect, &pos_seg);
	return (vect);
}
