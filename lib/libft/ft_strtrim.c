/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 22:40:05 by mterkhoy          #+#    #+#             */
/*   Updated: 2021/07/05 16:02:59 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static int	ft_getlen(const char *s1, const char *set)
{
	int	i;
	int	j;

	i = 0;
	while (ft_isinset(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j > 0 && ft_isinset(s1[j], set))
		j--;
	return (j - i + 1);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	int		len;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_getlen(s1, set);
	if (len <= 0)
		len = 0;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (ft_isinset(*s1, set))
		s1++;
	i = 0;
	while (len-- > 0)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
