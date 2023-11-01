/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:37:00 by abhudulo          #+#    #+#             */
/*   Updated: 2023/11/01 19:55:30 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str != NULL)
	{
		while (str[len] != '\0')
			len++;
	}
	return (len);
}

char	*join_and_free(char *line_segment, char *buffer, size_t buffer_length, char *to_free)
{
	char			*new_segment;
	size_t			line_length;
	unsigned long	index;
	unsigned long	buffer_index;

	line_length = ft_strlen(line_segment);
	new_segment = (char *)malloc(sizeof(char) * (line_length + buffer_length + 1));
	if (new_segment != NULL)
	{
		index = 0;
		// Copy characters from line_segment to new_segment
		while (index < line_length)
		{
			new_segment[index] = line_segment[index];
			index++;
		}
		buffer_index = 0;
		// Copy characters from buffer to new_segment
		while (buffer_index < buffer_length)
			new_segment[index++] = buffer[buffer_index++];
		new_segment[index] = 0;
	}
	// Free the memory pointed to by to_free
	free(to_free);
	return (new_segment);
}

