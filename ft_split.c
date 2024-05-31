/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaret <souaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:51:41 by souaret           #+#    #+#             */
/*   Updated: 2024/05/31 23:28:38 by souaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>	// to be removed
/*************************************
#include <stdio.h>	// to be removed
	1- Calculer le nombre de segments
	2- Allocation du vecteur
	3- Parsing des segments
*************************************/
static int	ft_split_cpy(const char *s, char c, t_split_vars *s_v)
{
	int		n;
	char	*str;

	n = s_v->end - s_v->start + 1;
	str = malloc(n + 1);
	if (!str)
		return (0);
	else
	{
		str[n] = '\0';
		while (--n >= 0)
			str[n] = s[s_v->start + n];
		s_v->vect[s_v->pos_seg++] = str;
	}
	s_v->start = s_v->end + 1;
	while (s[s_v->start] && s[s_v->start] == c)
		s_v->start++;
	s_v->end = s_v->start - 1;
	return (1);
}

static int	ft_count_segs(char *s, char c)
{
	size_t	count_words;
	int		in_word;

	count_words = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else
		{
			if (!in_word)
				count_words++;
			in_word = 1;
		}
		s++;
	}
printf("nb=%zu,  ", count_words); fflush(stdout);
	return (count_words);
}
static void	ft_find_segs(const char *s, char c, t_split_vars *s_v)
{
	int		i;
	char	cc;

	i = 0;
	while (s[s_v->start + i])
	{
		cc = s[s_v->start + i];
		if (s[s_v->start + i] == c)
		{
			if (s_v->in_word == 1)
			{
				s_v->end = s_v->start + i - 1;
				s_v->in_word = 0;
				return ;
			}
		}
		else
		{
			if (!s_v->in_word)
				s_v->start += i;
			s_v->in_word = 1;
		}
		i++;
	}
	if (s_v->in_word == 1)
		s_v->end = s_v->start + i - 1;
printf("start=%d, end=%d\n", s_v->start, s_v->end); fflush(stdout);
	return ;
}

static void	ft_vars_init(t_split_vars *v)
{
	v->in_word = 0;
	v->start = 0;
	v->end = 0;
	v->pos_seg = 0;
	v->nb_seg = 0;
	v->vect = NULL;
}

char	**ft_split(char const *s, char c)
{
	t_split_vars	s_v;

	ft_vars_init(&s_v);
	s_v.nb_seg = ft_count_segs((char *)s, c);
	s_v.vect = (char **)malloc(sizeof(char *) * (s_v.nb_seg + 1));
	if (!s_v.vect)
		return (NULL);
	while (s[s_v.start])
	{
		ft_find_segs(s, c, &s_v);
			printf("start=%d, end=%d, p;os_seg=%d", s_v.start, s_v.end, s_v.pos_seg);
		if (!ft_split_cpy(s, c, &s_v))
		{
			while (--s_v.pos_seg)
				free(s_v.vect[s_v.pos_seg]);
			free(s_v.vect);
			return (NULL);
		}
	}
	return (s_v.vect);
}
/*
static void	ft_split_extract_n(char const *s, char c, char **vect, int *pos_seg)
{
	t_split_vars	s_v;

	ft_vars_init(&s_v);
	while (s[s_v.end])
	{
		if (s[s_v.end] == c)
		{
			if (s_v.in_word)
				vect[pos_seg[0]++] = ft_split_cpy(s, &s_v);
			if (s_v.in_word)
				s_v.in_word = 0;
		}
		else
		{
			if (!s_v.in_word)
				s_v.start = s_v.end;
			if (!s_v.in_word)
				s_v.in_word = 1;
		}
		s_v.end++;
	}
	if (s_v.in_word)
		vect[pos_seg[0]++] = ft_split_cpy(s, &s_v);
	vect[pos_seg[0]] = 0;
}
*/

/*
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
	pos_seg = 0;
	while (vect[pos_seg])
	{
		if (vect[pos_seg] == (char *)1)
		{
			pos_seg = 0;
			while (vect[pos_seg] && vect[pos_seg] != (char *)1)
				free(vect[pos_seg++]);
		}
		return (NULL);
	}
	return (vect);
}
*/
