#
#
#

#include "ft_ls.h"
#include "libft/includes/libft.h"

int		*ft_recup_arg(char *arg, t_option opt)
{
	int		i;
	int		*booleen;

	booleen = malloc(10);
	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'l')
			opt.l = 1;
		if (arg[i] == 'R')
			opt.R = 1;
		if (arg[i] == 'a')
			opt.a = 1;
		if (arg[i] == 'r')
			opt.r = 1;
		if (arg[i] == 't')
			opt.t = 1;
		if (arg[i] == 's')
			opt.s = 1;
		i++;
	}
	return (booleen);
}

int main(int ac, char **argv)
{
	t_option opt;
	if (argv[1][0] == '-')
	{
		ft_recup_arg(argv[1]);
	}
	return 0;
}
