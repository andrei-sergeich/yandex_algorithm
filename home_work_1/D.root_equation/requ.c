#include <stdio.h>

void	equation_processing(int a, int b, int c)
{
	FILE	*out;

	out = fopen("output.txt", "w");
	if (c < 0 || (a == 0 && b != c * c))
		fprintf(out, "%s", "NO SOLUTION");
	else if (a == 0 && b == c * c)
		fprintf(out, "%s", "MANY SOLUTIONS");
	else if ((c * c - b) % a == 0)
		fprintf(out, "%d", ((c * c - b) / a));
	else
		fprintf(out, "%s", "NO SOLUTION");
	fclose(out);
}

void	root_equation(void)
{
	FILE	*in;
	int		a;
	int		b;
	int		c;

	in = fopen("input.txt", "r");
	fscanf(in, "%d%d%d", &a, &b, &c);
	equation_processing(a, b, c);
	fclose(in);
}

int	main(void)
{
	root_equation();
	return (0);
}
