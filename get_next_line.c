#include "get_next_line.h"

char				*ft_clean(char *box, char **line, int rd)

{
	unsigned int	i;
	char			*tmp;

	i = 0;
	while (box[i])
	{
		if (box[i] == '\n')
			break ;
		i++;
	}
	if (i < ft_strlen(box))
	{
		*line = ft_substr(box, 0, i);
		tmp = ft_substr(box, i + 1, ft_strlen(box));
		free(box);
		box = ft_strdup(tmp);
		free(tmp);
	}
	else if (rd == 0)
	{
		*line = box;
		box = NULL;
	}
	return (box);
}

char				*ft_box(char *buf, char *box)
{
	char			*tmp;

	if (box)
	{
		tmp = ft_strjoin(box, buf);
		free(box);
		box = ft_strdup(tmp);
		free(tmp);
	}
	else
		box = ft_strdup(buf);
	return (box);
}

int					get_next_line(int fd, char **line)
{
	static char		*box[1024];
	char			buf[BUFFER_SIZE + 1];
	int				rd;

	if (fd < 0 || !line || BUFFER_SIZE <= 0) 
		return (-1);
	while ((rd = read(fd, buf, BUFFER_SIZE)))
	{
		if (rd == -1)
			return (-1);
		buf[rd] = '\0';
		box[fd] = ft_box(buf, box[fd]);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!(box[fd] = ft_clean(box[fd], line, rd)))
		return (0);
	if (rd == 0 && !box[fd])
	{
		*line = ft_strdup("\0");
		return (0);
	}
	return (1);
}
