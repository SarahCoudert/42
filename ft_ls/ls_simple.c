#
#
#
#

#include "ft_ls.h"

int main(int ac, char **argv)
{
	DIR *dir;
	struct dirent *dirent;
//	int		num_files;

//	num_files = 0;
	if (ac < 3)
	{
		if (ac == 2 && argv[1][0] != '-')
		dir = opendir(argv[1]);
		else if (ac == 1)
		dir = opendir(".");
		if (dir == NULL)
		{
			perror("");
			return (-1);
		}
		dirent = readdir(dir);
		while (dirent != NULL)
		{
		//	num_files++;
			if (dirent->d_name[0] != '.')
			ft_putendl(dirent->d_name);
				dirent = readdir(dir);
		}
		closedir(dir);
	}
	return (0);
}
