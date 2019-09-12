#include <stdio.h>
#include <math.h>

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
	double	test;

	test = -16.88787;

	copy(&new);
	//printf("new.a = %d\nnew.b = %d\nnew.c = %d\nnew.d = %d\n", new.a, new.b, new.c, new.d);
	printf("%lf", (test > 0 ? test - (long long)test : (long long)test - test));
	return (0);
}

