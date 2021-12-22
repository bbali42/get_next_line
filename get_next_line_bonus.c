/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbali <bbali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 14:32:41 by bbali             #+#    #+#             */
/*   Updated: 2021/12/21 19:28:55 by bbali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char	*tmp[1024];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[fd] = read_file(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	line = get_line(tmp[fd]);
	tmp[fd] = skip_line(tmp[fd]);
	return (line);
}
