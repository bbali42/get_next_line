/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:52:13 by bbali             #+#    #+#             */
/*   Updated: 2021/12/10 15:22:17 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *res)
{
	char	*buff;
	int		count;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	count = 1;
	while (!ft_strchr(res, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[count] = '\0';
		res = ft_strjoin(res, buff);
	}
	free(buff);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = read_file(fd, res);
	if (!res)
		return (NULL);
	line = get_line(res);
	res = skip_line(res);
	return (line);
}
