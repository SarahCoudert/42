#include <stdio.h>
#include "libft.h"

void purger(void)
{
	char c;
	while((c=getchar()) != '\n' && c != EOF)
	{
	}
}

int		main(void)
{
	int choix_utilisateur;
	char test_char;

	choix_utilisateur = -42;
	printf("\n\n\n\n#####################################################\n\n\tBienvenue dans le main de test de scoudert\n\n\tQue voulez-vous tester ?\n");
	printf("\n\n\t1. Tout\n\t2. Les fonctions utilisant des char\n\t3. Les fonctions utilisant des strings\n\nVeuillez taper votre choix et appuyer sur la touche [Entree]\n\n\n\n");
	scanf("%d", &choix_utilisateur);
	if (!ft_isdigit(choix_utilisateur))
	{
		printf("\n\n\tVeuillez rentrer un choix valide : \n");
		scanf("%d", &choix_utilisateur);
	}
	if (choix_utilisateur == 1)
	{
		printf("\n\n\tVeuillez entrer le char avec lequel vous desirez tester ces fonctions : \n\n");
		purger();
		scanf("%c", &test_char);
		purger();
		ft_putstr("\nft_putchar : ");
		ft_putchar(test_char);
		ft_putstr("\nft_strncmp entre \"bonjour\", \"bongg\" et 4 en n : ");
		ft_putnbr(ft_strncmp("bonjour", "bongg", 4));
		ft_putstr("\nft_atoi : ");
		ft_atoi("   	pou-12efsf3");
	}
	return (0);
}
