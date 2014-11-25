#
#
#
#

#include <fcntl.h>
#include "libft/libft.h"
#include "get_next_line.h"

int		main()
{
	char	*s;
	int i;

	i = 42;
	int		file = open("ocean2.txt", O_RDONLY);
	while (i > 0)
	{
		i = get_next_line(file, &s);
		if (i != 0)
			ft_putendl(s);
	}
	return (i);
}
