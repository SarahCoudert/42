#
#
#
#

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	if (c)
	{
		write (fd, &c, 1);
	}
}
