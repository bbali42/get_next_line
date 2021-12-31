/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:52:13 by bbali             #+#    #+#             */
/*   Updated: 2021/12/21 19:50:23 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *tmp)
{
	char	*buff;
	int		count;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	count = 1;
	while (!ft_strchr(tmp, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		tmp = ft_strjoin(tmp, buff);
	}
	free(buff);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE == INT_MAX)
		return (NULL);
	tmp = read_file(fd, tmp);
	if (!tmp)
		return (NULL);
	line = get_line(tmp);
	tmp = skip_line(tmp);
	return (line);
}
