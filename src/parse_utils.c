#include "push_swap.h"

int	is_flag(const char *str)
{
	if (!str)
		return (0);
	return (str[0] == '-' && str[1] == '-');
}

int	is_valid_int(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_within_int(long value)
{
	return (value >= INT_MIN && value <= INT_MAX);
}
