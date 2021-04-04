#include "get_next_line.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*copy_s;
	size_t		i;
	size_t		j;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	copy_s = (char *)malloc(sizeof(char) * len + 1);
	if (!copy_s)
		return (NULL);
	while (j < len && s[i] != '\0')
	{
		copy_s[j] = s[i];
		j++;
		i++;
	}
	copy_s[j] = '\0';
	return (copy_s);
}

size_t			ft_strlen(const char *str)
{
	size_t		i;

	i = 0;
	while (*str++ != '\0')
		i++;
	return (i);
}

char			*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char			*ft_strdup(const char *str)
{
	char			*duplicate;
	size_t			size;
	unsigned char	*copy_d;
	unsigned char	*copy_s;

	size = ft_strlen(str) + 1;
	duplicate = (char *)malloc(sizeof(char) * size);
	if (duplicate == NULL)
		return (NULL);
	if (duplicate != str)
	{
		copy_d = (unsigned char *)duplicate;
		copy_s = (unsigned char *)str;
		while (size--)
			*copy_d++ = *copy_s++;
	}
	return (duplicate);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int			len_s1;
	int			len_s2;
	char		*sum_str;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	sum_str = (char *)malloc(sizeof(char) * (len_s1 + len_s2) + 1);
	if (sum_str == NULL)
		return (NULL);
	while (i < len_s1)
	{
		sum_str[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		sum_str[i++] = s2[j++];
	sum_str[i] = '\0';
	return (sum_str);
}
