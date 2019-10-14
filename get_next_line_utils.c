/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:14:53 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/14 17:50:34 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(char const *str)
{
	size_t	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int		i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2)
	{
		s1[i] = *s2;
		i++;
		s2++;
	}
	s1[i] = '\0';
	return ((char *)s1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*mem;

	i = 0;
	if (!(mem = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		mem[i] = s1[i];
		i++;
	}
	mem[i] = '\0';
	mem = ft_strcat(mem, s2);
	return (mem);
}

char	*ft_strdup(char *s1)
{
	size_t	len;
	char	*s2;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	s2 = malloc(len * sizeof(char));
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*mem;
	unsigned int	i;

	if (!(mem = malloc((len + 1) * sizeof(char))))
		return ("NULL");
	i = 0;
	while (len--)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
