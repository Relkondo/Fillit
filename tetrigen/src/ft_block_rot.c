#include "tetrigen.h"

char	*ft_block_rot(char *block, int rot)
{
	char	*ret;
	int		ret_i;
	int		block_i;
	int		eof;
	int		block_init;

	ret_i = -1;
	eof = 1;
	ret = (char *)malloc(sizeof(char) * 20);
	if (rot == 0)
		return (block);
	else
	{
		if (rot == 1)
			block_init = 15;
		if (rot == 2)
			block_init = 18;
		if (rot == 3)
			block_init = 3;
		block_i = block_init;
		while (++ret_i < 20)
		{
			if (ret_i == 4 || ret_i == 9 || ret_i == 14 || ret_i == 19)
			{
				ret[ret_i] = '\n';
				if (rot == 1)
					block_i = block_init + eof;
				if (rot == 2)
					block_i--;
				if (rot == 3)
					block_i = block_init - eof;
				eof++;
			}
			else
			{
				ret[ret_i] = block[block_i];
				if (rot == 1)
					block_i -= 5;
				if (rot == 2)
					block_i--;
				if (rot == 3)
					block_i +=5;
			}
		}
		return (ret);
	}
}
