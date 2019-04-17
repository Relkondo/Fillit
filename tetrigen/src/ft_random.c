#include "tetrigen.h"

int		ft_random(int min, int max)
{
	return rand() % (max - min + 1) + min;
}
