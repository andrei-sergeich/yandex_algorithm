#include <stdio.h>

char	*ft_triangle(int a, int b, int c)
{
	char *y = "YES";
	char *n = "NO";

	if ((a < b + c) && (b < a + c) && (c < b + a))
		return (y);
	return (n);
}

int main(void)
{
	FILE	*in;
	FILE	*out;
	int		a;
	int		b;
	int		c;

	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	fscanf(in, "%d%d%d", &a, &b, &c);
	fprintf(out, "%s", ft_triangle(a, b, c));
	fclose(in);
	fclose(out);
	return (0);
}
