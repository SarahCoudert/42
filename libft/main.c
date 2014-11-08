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

	choix_utilisateur = -42;
	printf("\n\n\n\n########################################################\n\n\tBienvenue dans le main de test de scoudert\n\n\tQue voulez-vous tester ?\n");
	printf("\n\n\t1. Tout\n\t2. En testant des pieges\n\t3. En rentrant vos propres valeurs\n\nVeuillez taper votre choix et appuyer sur la touche [Entree]\n\n");
	printf("########################################################\n\n\n");
	scanf("%d", &choix_utilisateur);
	if (choix_utilisateur < 0 || choix_utilisateur > 9)
	{
		printf("\n\tVeuillez rentrer un choix valide : \n\n");
		purger();
		scanf("%d", &choix_utilisateur);
	}
	if (choix_utilisateur == 1)
	{
		purger();
		ft_putchar('\n');
		ft_putstr("ft_putstr affiche a l'instant meme cette phrase et toutes celles qui vont suivre !");
		ft_putstr("\nft_putchar affiche n, '\\n' et '5': ");
		ft_putchar('n');
		ft_putchar('\n');
		ft_putchar('5');
		ft_putstr("\nft_isalnum avec 'a', '3' et ensuite '*' comme arguments : ");
		ft_putnbr(ft_isalnum('a'));
		ft_putstr(", ");
		ft_putnbr(ft_isalnum('3'));
		ft_putstr(", ");
		ft_putnbr(ft_isalnum('*'));
		ft_putstr("\nft_isalpha avec 'b' et ensuite 6 comme arguments : ");
		ft_putnbr(ft_isalpha('b'));
		ft_putstr(", ");
		ft_putnbr(ft_isalpha(6));
		ft_putstr("\nft_isascii avec '1', 'b', '#' et un caractere non ascii de valeur 200 : ");
		ft_putnbr(ft_isascii(1));
		ft_putstr(", ");
		ft_putnbr(ft_isascii(6));
		ft_putstr(", ");
		ft_putnbr(ft_isascii('#'));
		ft_putstr(", ");
		char non_ASCII = 200;
		ft_putnbr(ft_isascii(non_ASCII));
		ft_putchar('\n');
		ft_putstr("ft_isdigit avec '8' et 'a' comme arguments :  ");
		ft_putnbr(ft_isdigit('8'));
		ft_putstr(", ");
		ft_putnbr(ft_isdigit('a'));
		ft_putstr("\nft_isprint avec 'a' et '\\n' : ");
		ft_putnbr(ft_isprint('a'));
		ft_putstr(", ");
		ft_putnbr(ft_isprint('\n'));

		char s1[] = "bonjour je suis gentil";
		char s2[] = "hello, ";
		ft_putstr("\nft_memcpy avec une string dest contenant \"bonjour je suis gentil\" et src \"hello, \" avec 7 comme n : ");
		ft_memcpy(s1, s2, 7);
		ft_putstr(s1);


		ft_putstr("\nft_strncmp entre \"bonjour\", \"bongg\" et limite de comparaison 4 : ");
		ft_putnbr(ft_strncmp("bonjour", "bongg", 4));
		ft_putstr("\nft_atoi avec comme argument \"    -356gg456\": ");
		ft_putnbr(ft_atoi("   -356gg456"));
		printf("\n");
	}
	
	return (0);
}
