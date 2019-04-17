#ifndef TETRIGEN_H
# define TETRIGEN_H

# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# define BUFFER 1024

char	*ft_block_rot(char *block, int rot);
int		ft_random(int min, int max);
int		ft_atoi(const char *str);
void	ft_error(void);

#endif
