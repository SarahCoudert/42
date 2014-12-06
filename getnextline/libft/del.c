#
#
#

#include "libft.h"
#include <stdlib.h>

void		del(void *content, size_t content_size)
{
	free(content);
	(void)content_size;
}
