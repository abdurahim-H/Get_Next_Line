/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:32:54 by abhudulo          #+#    #+#             */
/*   Updated: 2023/11/01 19:51:31 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

static short	handle_no_newline(char **line_part, t_buf *buffer, char **line, size_t length)
{
	short		return_code;

	if (buffer->status == NOT_FINISHED)
	{
		*line_part = strjoin_free(*line_part, buffer->rest, length, *line_part);
		free(buffer->rest);
		return_code = (*line_part != NULL) ? NOT_ENOUGH : ERROR;
	}
	else
	{
		*line = strjoin_free(*line_part, buffer->rest, length, *line_part);
		return_code = (*line != NULL) ? END : ERROR;
	}
	return (return_code);
}

static short	process_data(char **line_segment, t_buf *buffer, char **line, size_t length)
{
	short			return_code;
	unsigned long	index;

	return_code = ERROR;
	index = 0;
	while (index < length && (buffer->rest)[index] != '\n')
		index++;
	if (index < length)
	{
		*line = strjoin_free(*line_segment, buffer->rest, index, *line_segment);
		if (*line != NULL)
		{
			index++;
			buffer->rest = strjoin_free(NULL, buffer->rest + index, length - index, buffer->rest);
			if (buffer->rest != NULL)
				return_code = ENOUGH;
			else
				free(*line);
		}
	}
	else
		return_code = handle_no_newline(line_segment, buffer, line, length);
	return (return_code);
}

static short	read_segment(char **line_segment, t_buf *buffer, char **line, int file_descriptor)
{
	short		return_code;
	ssize_t		bytes_read;

	return_code = NOT_ENOUGH;
	while (return_code == NOT_ENOUGH)
	{
		return_code = ERROR;
		buffer->rest = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (buffer->rest != NULL)
		{
			bytes_read = read(file_descriptor, buffer->rest, BUFFER_SIZE);
			if (file_descriptor != 0 && bytes_read < BUFFER_SIZE)
				buffer->status = ALL_READ;
			else if (file_descriptor == 0
					&& (bytes_read == 0 || ((buffer->rest)[bytes_read - 1] != '\n'
							&& bytes_read < BUFFER_SIZE)))
				buffer->status = ALL_READ;
			if (bytes_read >= 0)
				return_code = process_data(line_segment, buffer, line, bytes_read);
		}
	}
	return (return_code);
}

static t_buf	*initialize_buffer(t_buf *buffer)
{
	buffer = (t_buf *)malloc(sizeof(t_buf));
	if (buffer != NULL)
	{
		buffer->rest = NULL;
		buffer->status = NOT_FINISHED;
	}
	return (buffer);
}

int fetch_next_line(int file_descriptor, char **line)
{
	short return_code;
	static t_buf *buffer = NULL;
	char *line_segment = NULL;

	return_code = ERROR;

	// Validate the input parameters
	if (line != NULL && file_descriptor >= 0 && BUFFER_SIZE > 0)
	{
		// If the buffer is not initialized, do it now
		if (buffer == NULL)
		{
			buffer = initialize_buffer(buffer);
			if (buffer == NULL)
				return (ERROR);
		}

		return_code = NOT_ENOUGH;

		// If there's data in the buffer, process it
		if (buffer->rest != NULL)
			return_code = process_data(&line_segment, buffer, line, ft_strlen(buffer->rest));

		// If we didn't get enough data, read more from the file
		if (return_code == NOT_ENOUGH)
			return_code = read_segment(&line_segment, buffer, line, file_descriptor);

		// If we've reached the end of the file or encountered an error, clean up the buffer
		if (return_code == END || return_code == ERROR)
		{
			free(buffer->rest);
			free(buffer);
			buffer = NULL;
			if (line_segment != NULL)
			{
				free(line_segment);
				line_segment = NULL;
			}
		}
	}

	return (return_code);
}

/*
================================================================================
******************* START OF MAIN FILE FOR TEST ******************* 
*/
int main(void)
{
    int file_descriptor;
    char *line = NULL;

    // Open the file
    file_descriptor = open("test.txt", O_RDONLY);
    if (file_descriptor < 0)
    {
        perror("Error opening file");
        return (1);
    }

    // Use fetch_next_line to read lines from the file
    while (fetch_next_line(file_descriptor, &line) > 0)
    {
        // Print each line to the console
        printf("%s\n", line);
        // Free the memory allocated for each line
        free(line);
        line = NULL;
    }

    // Check if there was an error reading the last line
    if (line != NULL)
    {
        free(line);
    }

    // Close the file
    close(file_descriptor);

	//   It is also possible to run cc -D BUFFER_SIZE=1024 get_next_line.c get_next_line_utils.c -o get_next_line and modify BUFFER_SIZE 

    return (0);
}
/*
******************* END OF MAIN FILE FOR TEST *******************
================================================================================
*/