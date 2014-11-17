#
#
#
#

#include <unistd.h>

void	ft_putchar(char c, int fd)
{
	if (c)
	{
		write (fd, &c, 1);
	}
}
