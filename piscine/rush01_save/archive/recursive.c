#include <stdio.h>

int	add_to_100(int i)
{
	if (i == 100)
		return (i);
	else
		add_to_100(i + 1);
	return (i);
}

int	main(void)
{
	int	i;
	int	ans;

	i = 0;
	ans = add_to_100(i);
	printf("%d", ans);
	return (0);
}
