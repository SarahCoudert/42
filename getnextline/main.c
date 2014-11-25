#
#
#
#

#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"
#include <stdlib.h>

int		main()
{
	char	*s;
	int i;

	i = 42;
	int		file = open("ocean1.txt", O_RDONLY);
	s = NULL;
	i = get_next_line(file, &s);
	if (i != 0 && s != NULL)
		ft_putendl(s);
	free (s);
	return (i);
}
