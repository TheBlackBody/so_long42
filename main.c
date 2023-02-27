#include "./get_next_line/get_next_line.h"

int main(int ac, char **av)
{
	int i = 0;
	char **tab = malloc(sizeof(char *) * 9);
	
	while(tab[i])
	{
		tab[i] = get_next_line(fd);
		printf("tab[%d]= %s\n",i ,tab[i]);
		i++;
	}
	return 0;
}
