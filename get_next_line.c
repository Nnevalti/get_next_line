/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:52:10 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/18 13:26:28 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int		ft_return(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	if (*str == NULL)
		return (0);
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
	{
		tmp = ft_strdup(&(*str)[i + 1]);
		free(*str);
		*str = tmp;
		return (1);
	}
	else
	{
		*str = NULL;
		return (1);
	}
}

int		get_next_line(int fd, char **line)
{
	int				res;
	static char		*str;
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	while ((res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (!str || !*str)
		{
			tmp = ft_strdup(buff);
			free(str);
			str = tmp;
		}
		else
		{
			tmp = ft_strjoin(str, buff);
			free(str);
			str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (res < 0)
		return (-1);
	return (ft_return(&str, line));
}

int		main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		i;

	(void)ac;
	i = 1;
	fd = open(av[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("Ligne %d : %s\n", i, line);
		i++;
		free(line);
	}
	return (0);
}
