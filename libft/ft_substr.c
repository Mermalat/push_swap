#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*sub;
	int		slen;
	int		i;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if ((int)start >= slen)
		return (ft_strdup(""));
	if (len > slen - (int)start)
		len = slen - (int)start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
