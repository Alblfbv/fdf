#include <stdio.h>

typedef struct test
{
	int	a;
	int	b;
	int c;
	int d;
}				test;



void	copy(test *new)
{
	test ref;
	
	ref.a = 2;
	ref.b = 4;
	ref.c = 6;
	ref.d = 8;
	*new = ref;
}

int		main(void)
{
	test new;

	copy(&new);
	printf("new.a = %d\nnew.b = %d\nnew.c = %d\nnew.d = %d\n", new.a, new.b, new.c, new.d);
	return (0);
}

