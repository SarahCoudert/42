#
#
#

#include <unistd.h>

void	putn()
{
	char		c;
	c = '\n';
	write (1, &c, 1);
}
