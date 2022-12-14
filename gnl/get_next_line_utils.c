/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okhiar <okhiar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:10:25 by okhiar            #+#    #+#             */
/*   Updated: 2022/11/03 20:43:15 by okhiar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_nl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_len_unl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *str, char *buff)
{
	char	*ret;

	if (!str)
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (0);
		str[0] = '\0';
	}
	if (!buff)
	{
		if (str)
			free(str);
		return (0);
	}
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(buff) + 1));
	if (!ret)
	{
		free(str);
		return (0);
	}
	ft_memcpy(ret, str, ft_strlen(str));
	ft_memcpy(ret + ft_strlen(str), buff, ft_strlen(buff) + 1);
	free(str);
	return (ret);
}
