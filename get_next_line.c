/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlewis-l <lerman.maggiel@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:37:21 by mlewis-l          #+#    #+#             */
/*   Updated: 2018/06/19 09:52:52 by mlewis-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"
#include <unistd.h>

static t_list  *get_fd(t_list **start, int fd)
{
    t_list  *tmp;

    tmp = *start;
    if (tmp)
    {
        while (tmp)
        {
            if (fd == (int)tmp->content_size)
                return(tmp);
            tmp = tmp->next;
        }
    }
tmp = ft_lstnew("\0", 1);
tmp->content_size = fd;
ft_lstadd(start, tmp);
return (tmp);
}

static char   *join(char *tmp, char *buf, int ret)
{
    char    *line;

    line = tmp;
    tmp = ft_strnjoin(tmp, buf, ret);
    free(line);
    return (tmp);
}

int           get_next_line(int const fd, char **line)
{
    char            buf[BUFF_SIZE + 1];
    int             ret;
    static t_list   *list = NULL;
    t_list          *start;
    char            *line;

    if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
        return (-1);
        start = list ? list : NULL;
        list = get_fd(&start, fd);
        while (!ft_strchr(list->content, '\n') && (ret = read(fd, buf, BUFF_SIZE)))
            list->content = join(list->content, buf, ret);
        ret = 0;
        while (((char *)list->content)[ret] && ((char *)list->content)[ret] != '\n')
            ++ret;
        *line = ft_strndup(list->content, ret);
        if (((char *)list->content)[ret] == '\n')
        ++ret;
        line = list->content;
        list->content = ft_strdup(list->content + ret);
        free(line);
        list = start;
        if (ret > 0)
            return (1);
        return (0);
}