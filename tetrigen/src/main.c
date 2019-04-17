#include "tetrigen.h"

int		main(int ac, char **av)
{
	srand(time(NULL));

	if (ac != 4)
		ft_error();
	else
	{
		int		fd;
		int		index;
		char	tetris[12][21] = {
			"....\n.##.\n.#..\n.#..\n",
			"##..\n.#..\n.#..\n....\n",
			"....\n.##.\n.##.\n....\n",
			".#..\n.#..\n.#..\n.#..\n",
			"....\n.##.\n..##\n....\n",
			".##.\n##..\n....\n....\n",
			"..#.\n.###\n....\n....\n",
			"....\n....\n##.#\n..#.\n",
			"#.#.\n.#.#\n....\n..#.\n",
			"....\n.#.#\n#.#.\n....\n",
			"#...\n####\n....\n....\n",
			"....\n....\n....\n....\n",
		};
		if (ft_atoi(av[3]) > 0 && ft_atoi(av[3]) < 27)
		{
			index = ft_atoi(av[3]);
			if (av[2][0] == '-' && av[2][1] == 's')
				fd = 0;
			if (av[2][0] == '-' && av[2][1] == 'f')
				fd = open("test.fillit", O_CREAT | O_RDWR, 0666);
			while (--index >= 0)
			{
				if (av[1][0] == '-' && av[1][1] == 'v')
				{
					write(fd, ft_block_rot(tetris[ft_random(0, 6)], ft_random(0, 3)), 20);
					if (index > 0)
						write(fd, "\n", 1);
				}
				if (av[1][0] == '-' && av[1][1] == 'i')
				{
					write(fd, ft_block_rot(tetris[ft_random(7, 11)], ft_random(0, 3)), 20);
					if (ft_random(0, 1) == 1)
						write(fd, "\n", 1);
				}
			}
			close(fd);
		}
		else
			ft_error();
	}
	return (0);
}
