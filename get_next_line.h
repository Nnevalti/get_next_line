/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:41:42 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/14 17:31:36 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stddef.h>
# include <unistd.h>

size_t	ft_strlen(char const *str);
int		get_next_line(int fd, char **line);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
