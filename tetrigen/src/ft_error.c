#include "tetrigen.h"

void	ft_error(void)
{
		printf("usage: ./tetrigen [option 1] [option 2] [number]\n");
		printf("\nMandatory arguments:\n");
		printf("\n [options 1]");
		printf("\n  -v: valid map");
		printf("\n  -i: invalid map\n");
		printf("\n [options 2]");
		printf("\n  -f: write map in a file");
		printf("\n  -s: send the map directly to the stdin\n");
		printf("\n [number]");
		printf("\n  Select between 1 and 26 tetriminos per file.\n");
}
