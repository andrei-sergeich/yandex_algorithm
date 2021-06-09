#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define COUNT 35
#define LN 4

void	numbers_cmp(char book[][COUNT])
{
	FILE	*out;
	int		x;

	x = 1;
	out = fopen("output.txt", "w");
	while (x < LN)
	{
		if (strcmp(book[0], book[x]) == 0)
			fprintf(out, "%s\n", "YES");
		if (strcmp(book[0], book[x]) != 0)
			fprintf(out, "%s\n", "NO");
		x++;
	}
	fclose(out);
}

char	*numbers_treatment(char *str)
{
	int		x;
	int		y;
	char	tmp[COUNT];

	x = 0;
	y = 0;
	strcpy(tmp, str);
	if (tmp[0] == '+' && tmp[1] == '7')
	{
		tmp[1] = '8';
		x++;
	}
	while (tmp[x])
	{
		if (tmp[x] == '(' || tmp[x] == ')' || tmp[x] == '-')
			x++;
		else
		{
			str[y] = tmp[x];
			x++;
			y++;
		}
	}
	str[y] = '\0';
	return (str);
}

void	numbers_without_code(char *str)
{
	int		x;
	int		y;
	char	code[4] = "8495";
	char	tmp[COUNT];

	x = 0;
	y = 4;
	if (strncmp(str, code, 4) != 0)
	{
		strcpy(tmp, code);
		while (str[x])
			tmp[y++] = str[x++];
		tmp[y] = '\0';
		strcpy(str, tmp);
	}
}

void	numbers_processing(char book[][COUNT])
{
	int	x;

	x = 0;
	while (x < LN)
	{
		numbers_treatment(book[x]);
		if (strlen(book[x]) <= 7)
			numbers_without_code(book[x]);
		x++;
	}
}

void	phone_numbers(void)
{
	FILE	*in;
	char	book[LN][COUNT];

	in = fopen("input.txt", "r");
	fscanf(in, "%s%s%s%s", book[0], book[1], book[2], book[3]);
	numbers_processing(book);
	numbers_cmp(book);
	fclose(in);
}

int	main(void)
{
	phone_numbers();
	return (0);
}
