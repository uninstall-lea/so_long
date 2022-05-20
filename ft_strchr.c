#include "so_long.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == c % 256)
			return ((char *)str);
		str++;
	}
	if (*str == '\0' && c == '\0')
		return ((char *)str);
	return (NULL);
}
