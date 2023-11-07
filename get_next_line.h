/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:33:17 by abhudulo          #+#    #+#             */
/*   Updated: 2023/11/07 13:01:50 by abhudulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE		0

# define ERROR			-1
# define END			0
# define ENOUGH			1
# define NOT_ENOUGH		2
# define NOT_FINISHED	3
# define ALL_READ		4

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct	s_list
{
	short			status;
	char			*rest;
}				t_buf;

int				fetch_next_line(int file_descriptor, char **line);
static t_buf	*initialize_buffer(t_buf *buffer);
static short	read_segment(char **line_segment, t_buf *buffer, char **line, int file_descriptor);
static short	process_data(char **line_segment, t_buf *buffer, char **line, size_t length);
static short	handle_no_newline(char **line_part, t_buf *buffer, char **line, size_t length);
char			*join_and_free(char *line_segment, char *buffer, size_t buffer_length, char *to_free);
size_t			ft_strlen(const char *str);

#endif