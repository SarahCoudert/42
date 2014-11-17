#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
		ft_putstr("-2147483648");
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar_fd((nb + '0'), fd);
}
