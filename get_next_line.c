/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:36:59 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/14 18:17:02 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(int fd, char **line)
{
	if (fd == -1 || !line)
		return (-1);
	return (0);
}

char	*ft_readfile(int fd, char **str)
{
	int		res;
	char	rdchar[BUFFER_SIZE + 1];

	while ((res = read(fd, rdchar, BUFFER_SIZE)) > 0)
	{
		rdchar[res] = '\0';
		if (*str)
			*str = ft_strjoin(*str, rdchar);
		else
			*str = ft_strdup(rdchar);
	}
	return (*str);
}

int		get_next_line(int fd, char **line)
{
	int			i;
	static char	*str;

	i = 0;
	if (check_error(fd, line) == -1 || read(fd, str, 0) < 0)
		return (-1);
	if (!str)
		str = ft_readfile(fd, &str);
	if (!*str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	(*line) = ft_substr(str, 0, i);
	str += i + 1;
	return (1);
}

int		main(int ac, char **av)
{
	int		fd;
	(void)	ac;
	char	*line;
	int		i;

	if (ac > 1)
		fd = open(av[1], O_RDONLY);
	else
		fd = 0;
	i = 0;
	while (i < 1 && get_next_line(fd, &line) > 0)
	{
		printf("ligne : %d %s\n", i, line);
		i++;
		free(line);
	}
	return (0);
}
