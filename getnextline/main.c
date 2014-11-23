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
	int		file = open("Nouveau document.txt", O_RDONLY);
	get_next_line(file, &s);
	ft_putendl(s);
	return (0);
}
