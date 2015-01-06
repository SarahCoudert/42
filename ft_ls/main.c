#
#
#
#

#include "ft_ls.h"

void		print_detail(const char *file_name)
{
	struct stat		buf;

	stat(file_name, &buf);
}

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
			//num_files++;
			if (dirent->d_name[0] != '.')
			{
				ft_putendl(dirent->d_name);
				print_detail(dirent->d_name);
			}
			dirent = readdir(dir);
		}
		closedir(dir);
	}
	return (0);
}

/*
   int stat(const char *file_name, struct stat *buf);
   struct stat
   {
   dev_t         st_dev;       Périphérique
   ino_t         st_ino;       Numéro i-noeud
   mode_t        st_mode;      Protection
   nlink_t       st_nlink;     Nb liens matériels
   uid_t         st_uid;       UID propriétaire
   gid_t         st_gid;       GID propriétaire
   dev_t         st_rdev;      Type périphérique           
   off_t         st_size;      Taille totale en octets     
   unsigned long st_blksize;   Taille de bloc pour E/S     
   unsigned long st_blocks;    Nombre de blocs alloués     
   time_t        st_atime;     Heure dernier accès         
   time_t        st_mtime;     Heure dernière modification 
   time_t        st_ctime;     Heure dernier changement    
   };

*/

