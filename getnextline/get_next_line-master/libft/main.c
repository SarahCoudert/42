#
#
#
#
/*
#include <fcntl.h>
#include "libft/includes/libft.h"
#include "get_next_line.h"
#include <stdlib.h>

int		main()
{
	char	*s;
	int i;

	i = 42;
	int		file = open("texte.txt", O_RDONLY);
	while (i > 0)
	{
		s = NULL;
		i = get_next_line(file, &s);
		if (i > 0)
			ft_putendl(s);
	}
	close(file);
	return (i);
}*/