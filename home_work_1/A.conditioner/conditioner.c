#include <string.h>
#include <stdio.h>

int	ft_cond(int troom, int tcond, char *mode)
{
	char	*fr = "freeze";
	char	*ht = "heat";
	char	*au = "auto";

	if (strcmp(mode, fr) == 0 && tcond <= troom)
		troom = tcond;
	if (strcmp(mode, ht) == 0 && tcond >= troom)
		troom = tcond;
	if (strcmp(mode, au) == 0)
		troom = tcond;
	return (troom);
}

int main(void)
{
	FILE	*in;
	FILE	*out;
	int		troom;
	int		tcond;
	char	mode[7];

	in = fopen("input.txt", "r");
	out = fopen("output.txt", "w");
	fscanf(in, "%d%d%s", &troom, &tcond, mode);
	fprintf(out, "%d", ft_cond(troom, tcond, mode));
	fclose(in);
	fclose(out);
	return (0);
}
