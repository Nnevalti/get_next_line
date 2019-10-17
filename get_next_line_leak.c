/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:58:42 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/17 17:46:46 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

int		check_error(int fd, char **line)
{
	if (fd == -1 || !line || BUFFER_SIZE < 1)
		return (-1);
	return (1);
}

void	ft_readline(int fd, char **str)
{
	int		res;
	char	rdchar[BUFFER_SIZE + 1];

	while ((res = read(fd, rdchar, BUFFER_SIZE)) > 0)
	{
		rdchar[res] = '\0';
		if (*str)
		{
			*str = ft_strjoin(*str, rdchar);
		}
		else
		{
			*str = ft_strdup(rdchar);
		}
		if(ft_strchr(*str, '\n'))
			break ;
	}
}

int		get_next_line(int fd, char **line)
{
	int				i;
	static char		*str;

	i = 0;
	if (check_error(fd, line) == -1 || read(fd, str, 0) < 0)
		return (-1);
	ft_readline(fd, &str);
	if (!str || !*str)
		return (0);
	while (str[i] != '\n' && str[i])
		i++;
	if (i == 0 && !str[i])
		return (0);
	else
	{
		*line = ft_substr(str, 0, i);
		if (str[i] == '\n')
		{
			str = &str[i + 1];
		}
		else if (str[i] == '\0')
			str = &str[i];
	}
	return (1);
}

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	(void)ac;
	i = 1;
	fd = open(av[1], O_RDONLY);
	while((get_next_line(fd, &line)) > 0)
	{
		printf("Ligne %d : %s\n", i, line);
		i++;
		free(line);
	}
	return (0);
}
