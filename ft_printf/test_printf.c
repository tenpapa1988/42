#include <stdio.h>
#include <stdarg.h>

// int	main(void)
// {
// 	char *p = NULL;

// 	printf("The content is %s", p);

// 	return (0);
// }

void	foo(char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	while (fmt != NULL)
	{
		printf("%s\n", fmt);
		fmt = (char *)va_arg(ap, char *);
	}
	va_end(ap);
}

int	main(void)
{
	foo("aiueo", "test", "mouse", NULL);
	return (0);
}