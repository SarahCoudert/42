#
#
#
#

#include "ft_ls.h"

void		R_option(struct dirent *dirent)
{
	if (dirent == NULL) // condition de sortie->fin des dossiers du '.'
		return ;
	R_option();
}
