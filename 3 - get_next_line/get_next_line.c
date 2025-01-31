/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adurusoy <adurusoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 06:58:22 by adurusoy          #+#    #+#             */
/*   Updated: 2023/06/14 04:39:34 by adurusoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cook(char *wholecake, char *cake)
{
	char	*temp;

	temp = ft_strjoin(wholecake, cake);
	free(wholecake);
	return (temp);
}

char	*leftover(char *cake)
{
	int		count1;
	int		count2;
	char	*newcake;

	count1 = 0;
	while (cake[count1] != '\0' && cake[count1] != '\n')
		count1++;
	if (!cake[count1])
	{
		free(cake);
		return (NULL);
	}
	newcake = ft_calloc((ft_strlen(cake) - count1 + 1), sizeof(char));
	count1++;
	count2 = 0;
	while (cake[count1] != '\0')
		newcake[count2++] = cake[count1++];
	free (cake);
	return (newcake);
}

char	*knife(char *cake)
{
	int		count1;
	char	*piece;

	count1 = 0;
	if (!cake[count1])
		return (NULL);
	while (cake[count1] && cake[count1] != '\n')
		count1++;
	piece = ft_calloc(count1 + 2, sizeof(char));
	count1 = 0;
	while (cake[count1] && cake[count1] != '\n')
	{
		piece[count1] = cake[count1];
		count1++;
	}
	if (cake[count1] && cake[count1] == '\n')
		piece[count1] = '\n';
	return (piece);
}

char	*plate(int fd, char *wholecake)
{
	char	*cake;
	int		check;

	if (!wholecake)
		wholecake = ft_calloc(1, 1);
	cake = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	check = 1;
	while (check > 0)
	{
		check = read(fd, cake, BUFFER_SIZE);
		if (check == -1)
		{
			free(cake);
			return (NULL);
		}
		cake[check] = '\0';
		wholecake = cook(wholecake, cake);
		if (ft_strchr(cake, '\n'))
			break ;
	}
	free(cake);
	return (wholecake);
}

char	*get_next_line(int fd)
{
	static char	*cake;
	char		*piece;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	cake = plate(fd, cake);
	if (!cake)
		return (NULL);
	piece = knife(cake);
	cake = leftover(cake);
	return (piece);
}
