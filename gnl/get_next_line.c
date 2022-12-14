/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 12:59:37 by okhiar            #+#    #+#             */
/*   Updated: 2022/11/03 20:29:48 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_unl(char *str, int fd)
{
	char	*buff;
	int		sys_ret;

	sys_ret = 1;
	buff = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	while (!ft_find_nl(str) && sys_ret)
	{
		if (buff)
			sys_ret = read(fd, buff, BUFFER_SIZE);
		if (!buff || sys_ret == -1)
		{
			if (buff)
				free(buff);
			if (str)
				free(str);
			return (0);
		}
		buff[sys_ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

static char	*ft_read_line(char *str)
{
	char	*line;
	int		len;
	int		i;

	if (!str[0])
		return (0);
	len = ft_len_unl(str);
	if (str[len] == '\n')
		len++;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (0);
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_update_static(char *readed)
{
	char	*str;
	int		len;
	int		i;

	len = ft_len_unl(readed);
	if (!readed[len])
	{
		free(readed);
		return (0);
	}
	len++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(readed) - len + 1));
	if (!str)
	{
		free(readed);
		return (0);
	}
	i = 0;
	while (readed[len])
		str[i++] = readed[len++];
	str[i] = '\0';
	free(readed);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read_unl(str, fd);
	if (!str)
		return (0);
	line = ft_read_line(str);
	str = ft_update_static(str);
	return (line);
}
