#include "libft.h"

void		ft_put_error(char *s, int fd, int ret)
{
	ft_putendl_fd(s, fd);
	exit(ret);
}