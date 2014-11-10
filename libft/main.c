#include <stdio.h>
#include "libft.h"

#define  sconst1 "bonjour je suis gentil"
#define sconst2 "hello, "

		char s1[100] = sconst1;
		char s2[] = sconst2;


void purger(void)
{
	char c;
	while((c=getchar()) != '\n' && c != EOF)
	{
	}
}

void	bleue_putstr(char *str)
{
	ft_putstr("\033[1;34m");
	ft_putstr(str);
	ft_putstr("\033[0m");
}

void	bleu()
{
	ft_putstr("\033[34;1m");
}

void	normal()
{
	ft_putstr("\033[0m");
}

void	reinitialiser()
{
	ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));
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
		bleu();
		ft_putchar('n');
		ft_putchar('\n');
		ft_putchar('5');
		normal();


		ft_putstr("\nft_isalnum avec 'a', '3' et ensuite '*' comme arguments : ");
		bleu();
		ft_putnbr(ft_isalnum('a'));
		ft_putstr(", ");
		ft_putnbr(ft_isalnum('3'));
		ft_putstr(", ");
		ft_putnbr(ft_isalnum('*'));
		normal();

		ft_putstr("\nft_isalpha avec 'b' et ensuite 6 comme arguments : ");
		bleu();
		ft_putnbr(ft_isalpha('b'));
		ft_putstr(", ");
		ft_putnbr(ft_isalpha(6));
		normal();

		ft_putstr("\nft_isascii avec '1', 'b', '#' et un caractere non ascii de valeur 200 : ");
		bleu();
		ft_putnbr(ft_isascii(1));
		ft_putstr(", ");
		ft_putnbr(ft_isascii(6));
		ft_putstr(", ");
		ft_putnbr(ft_isascii('#'));
		ft_putstr(", ");
		char non_ASCII = 200;
		ft_putnbr(ft_isascii(non_ASCII));
		ft_putchar('\n');
		normal();

		ft_putstr("ft_isdigit avec '8' et 'a' comme arguments :  ");
		bleu();
		ft_putnbr(ft_isdigit('8'));
		ft_putstr(", ");
		ft_putnbr(ft_isdigit('a'));
		normal();

		ft_putstr("\nft_isprint avec 'a' et '\\n' : ");
		bleu();
		ft_putnbr(ft_isprint('a'));
		ft_putstr(", ");
		ft_putnbr(ft_isprint('\n'));
		normal();

		ft_putstr("\nft_memcpy avec une string dest contenant \"bonjour je suis gentil\" et src \"hello, \" avec 7 comme n : ");
		ft_memcpy(s1, s2, 7);
		bleue_putstr(s1);
		ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));

		ft_putstr("\nft_memmove va maintenant mettre \"bonjour\" a la fin dans la phrase dest precedente : ");
		ft_memmove(s1 + 15,s1,7);
		bleue_putstr(s1);
		ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));

		ft_putstr("\nft_memccpy avec une string dest contenant \"Bonjour je suis gentil\", et src \"hello, \" avec 'u' comme c et 5 comme n : ");
		ft_memccpy(s1, s2, 'u', 5);
		bleue_putstr(s1);
		ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));
		ft_putchar('\n');
		
		ft_putstr("ft_memset remplace les 8 premiers caracteres de dest avec la lettre b : ");
		bleue_putstr(ft_memset(s1, 'b', 8));
		ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));
		
		ft_putstr("\nft_putnbr va maintenant afficher 4 (wahou !) : ");
		bleu();
		ft_putnbr(4);
		normal();

		ft_putstr("\nft_strcat va concatener la chaine \"bonjour je suis gentil\" avec la chaine \"hello, \" : ");
		bleue_putstr(ft_strcat(s1, s2));
		ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));

		ft_putstr("\nft_strncat va faire la meme chose que le precedent strcat mais avec seulement 5 caracteres : ");
		bleue_putstr(ft_strncat(s1, s2, 5));
		ft_memcpy(s1, sconst1, (ft_strlen(sconst1) + 1));
		
		reinitialiser();

		ft_putstr("\nft_strchr va rechercher le  premier caractere 's' dans la chaine dest 'bonjour je suis gentil' : ");
		bleue_putstr(ft_strchr(s1, 's'));


		ft_putstr("\nft_strrchr va rechercher le dernier caractere 's' dans la chaine dest 'bonjour je suis gentil' : ");
		bleue_putstr(ft_strrchr(s1, 's'));

		ft_strcpy();


		ft_putstr("\nft_strncmp entre \"bonjour\", \"bongg\" et limite de comparaison 4 : ");
		bleu();
		ft_putnbr(ft_strncmp("bonjour", "bongg", 4));
		normal();

		ft_putstr("\nft_atoi avec comme argument \"    -356gg456\": ");
		bleu();
		ft_putnbr(ft_atoi("   -356gg456"));
		printf("\n");
		normal();
	}
	return (0);
}
