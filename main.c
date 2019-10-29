/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 16:05:18 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/29 16:11:51 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

__attribute__((destructor)) void	destructeur()
{
	while (1);
}

int		main(int ac, char **av)
{
	(void)ac;
	int		fd = open(av[1], O_RDONLY);
	char	*line;
	int		i;

	i = 1;
	while (get_next_line(fd, &line))
	{
		printf("Ligne %d: %s\n", i, line);
		free(line);
		i++;
	}
	printf("Ligne %d: %s\n", i, line);
	free(line);
	destructeur();
	return (0);
}
