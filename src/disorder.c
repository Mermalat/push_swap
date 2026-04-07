#include "push_swap.h"

static int	*copy_to_array(t_stack *a)
{
	int		*arr;
	t_node	*cur;
	int		i;

	arr = malloc(sizeof(int) * a->size);
	if (!arr)
		return (NULL);
	cur = a->top;
	i = 0;
	while (cur)
	{
		arr[i++] = cur->index;
		cur = cur->next;
	}
	return (arr);
}

static long	count_inversions(int *arr, int n)
{
	long	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

float	calc_disorder(t_stack *a)
{
	int		*arr;
	long	inversions;
	long	total_pairs;
	float	disorder;

	if (a->size <= 1)
		return (0.0f);
	arr = copy_to_array(a);
	if (!arr)
		return (0.5f);
	inversions = count_inversions(arr, a->size);
	total_pairs = (long)a->size * (a->size - 1) / 2;
	disorder = (float)inversions / (float)total_pairs;
	free(arr);
	return (disorder);
}
