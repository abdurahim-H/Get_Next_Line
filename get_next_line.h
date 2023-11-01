/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhudulo <abhudulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 11:33:17 by abhudulo          #+#    #+#             */
/*   Updated: 2023/11/01 18:46:27 by abhudulo         ###   ########.fr       */
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

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *str);
char			*strjoin_free(char *line_part, char *buf,
		size_t len_buf, char *to_free);

#endif

