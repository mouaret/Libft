/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <souaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:51:41 by souaret           #+#    #+#             */
/*   Updated: 2024/06/01 16:50:35 by souaret          ###   ########.fr       */
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

static void	*ft_vars_init(t_split_vars *v, const char *s, char c)
{
	int	n;

	v->in_word = 0;
	v->deb = 0;
	v->fin = 0;
	v->pos_seg = 0;
	v->vect = NULL;
	n = ft_count_segs((char *)s, c);
	v->vect = (char **)malloc(sizeof(char *) * (n + 1));
	if (!v->vect)
		return (NULL);
	while (n >= 0)
	{
		v->vect[n] = NULL;
		n--;
	}
	return (v->vect);
}

static char	*ft_s_cpy(char action, const char *s, t_split_vars *sv, int fin)
{
	int		n;
	int		i;
	char	*str;

	if (action == '1')
	{
		n = fin - sv->deb + 1;
		str = malloc(n + 1);
		if (!str)
			return (NULL);
		i = 0;
		while (n--)
		{
			str[i] = s[sv->deb + i];
			i++;
		}
		str[i] = '\0';
		sv->vect[sv->pos_seg++] = str;
		sv->vect[sv->pos_seg] = NULL;
		return (str);
	}
	i = sv->pos_seg - 1;
	while (i-- >= 0)
		free(sv->vect[i]);
	return (NULL);
}

static void	*ft_split_extract_n(char const *s, char c, t_split_vars *sv)
{
	while (s[sv->fin])
	{
		if (s[sv->fin] == c)
		{
			if (sv->in_word)
				if (!ft_s_cpy('1', s, sv, sv->fin - 1))
					return (ft_s_cpy('0', s, sv, sv->fin - 1));
			if (sv->in_word)
				sv->in_word = 0;
		}
		else
		{
			if (!sv->in_word)
				sv->deb = sv->fin;
			if (!sv->in_word)
				sv->in_word = 1;
		}
		sv->fin++;
	}
	if (sv->in_word)
		if (!ft_s_cpy('1', s, sv, sv->fin - 1))
			return (ft_s_cpy('0', s, sv, sv->fin - 1));
	return (sv->vect);
}

/*
	//if (!s || *s == '\0')
*/
char	**ft_split(char const *s, char c)
{
	t_split_vars	s_v;
	char			**v;

	if (!s)
	{
		v = (char **) malloc(1 * sizeof(char *));
		if (!v)
			return (NULL);
		v[0] = NULL;
		return (v);
	}
	if (!ft_vars_init(&s_v, s, c))
		return (NULL);
	if (!ft_split_extract_n(s, c, &s_v))
		return (NULL);
	return (s_v.vect);
}
