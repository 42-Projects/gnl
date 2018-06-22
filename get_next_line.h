/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <lerman.maggiel@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:42:53 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/06/16 16:48:31 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

int		get_next_line(int const fd, char **line);

#endif