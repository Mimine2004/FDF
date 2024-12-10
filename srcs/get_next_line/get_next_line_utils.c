/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhecquet <hhecquet@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:30:42 by hhecquet          #+#    #+#             */
/*   Updated: 2024/11/20 09:04:22 by hhecquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (start >= ft_strlen(s) || !s)
	{
		str = malloc(sizeof(char) * 1);
		if (!str || !s)
			return (NULL);
		str[j] = '\0';
		return (str);
	}
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (i != start)
		i++;
	while (j < len)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			tot;
	void			*ran;
	unsigned char	*str;

	tot = size * nmemb;
	ran = malloc(tot);
	if (!ran)
		return (NULL);
	str = ran;
	while (tot != 0)
	{
		*str = 0;
		str++;
		tot--;
	}
	return (ran);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	while (len1--)
		str[len1] = s1[len1];
	len1 = ft_strlen(s1);
	while (len2--)
		str[len1 + len2] = s2[len2];
	str[len1 + ft_strlen(s2)] = '\0';
	return (str);
}
