/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darresti <darresti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:30:29 by darresti          #+#    #+#             */
/*   Updated: 2014/11/18 17:54:49 by scoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define RESET	"\033[0m"
#define BOLD	"\033[1m"
//#define	UNBOLD	"\033[21m" /* UNBOLD not supported by zsh */
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define UNCOLOR	"\033[39m"
#define ULINE	"\033[4m"
#define UNULINE	"\033[24m"

/* Comment out to remove the NULL tests */
//#define SEGFAULT_ME
/* If the test segfaults, try skipping the NULL tests */
/* to see if they are the ones giving you a hard time */

static void	set(char *color_code)
{
	printf(color_code);
}

static void print_test_name(char *str)
{
	set(BLUE);
	set(BOLD);
	printf(str);
	set(RESET);
	if (strlen(str) > 6)
		printf(":\t");
	else
		printf(":\t\t");
	fflush(stdout);
}

static void	print_test_results(int	return_value[], int control_value[], int n, int warning[])
{
	int		i, j;

	if (n)
	{
		i = 0;
		while (i < n)
		{
			printf("test %d", i);
			if (return_value[i] == control_value[i])
			{
				set(GREEN);
				printf(" OK");
				set(UNCOLOR);
				if (i != n - 1)
					printf(", ");
			}
			else
			{
				j = -1;
				if (warning)
				{
					j = 0;
					while (warning[j] != -1 && warning[j] != i)
						++j;
					if (warning[j] != i)
						j = -1;
				}
				if (j == -1)
				{
					set(RED);
					printf(" failed");
					set(UNCOLOR);
					printf(" [ctrl=%d, test=%d]", control_value[i], return_value[i]);
					if (i != n - 1)
						printf(", ");
				}
				else
				{
					set(YELLOW);
					printf(" disagreed");
					set(UNCOLOR);
					printf(" [ctrl=%d, test=%d]", control_value[i], return_value[i]);
					if (i != n - 1)
						printf(", ");
				}
			}
			++i;
		}
		printf("\n");
	}
	else
	{
		set(YELLOW);
		printf("no test was performed\n");
		set(UNCOLOR);
	}
}

static void	print_test_results_summary(int	return_value[], int control_value[], int n)
{
	int		i;

	if (n)
	{
		if (n == 1)
			printf("1 test ");
		else
			printf("%d tests ", n);
		i = 0;
		while (i < n && return_value[i] == control_value[i])
			++i;
		if (i == n && return_value[i - 1] == control_value[i - 1])
		{
			set(GREEN);
			printf("OK");
			set(UNCOLOR);
		}
		else
		{
			if (i == n)
				--i;
			set(RED);
			printf("failed");
			set(UNCOLOR);
			printf(" @ [i=%d, ctrl=%d, test=%d]", i, control_value[i], return_value[i]);
		}
		printf("\n");
	}
	else
	{
		set(YELLOW);
		printf("no test was performed\n");
		set(UNCOLOR);
	}
}

static void	f_iter(char *pc)
{
	++(*pc);
}

static void	f_iteri(unsigned int i, char *pc)
{
	*pc += i;
}

static char	f_map(char c)
{
	return (++c);
}

static char	f_mapi(unsigned int i, char c)
{
	return (c + i);
}
/*
static void	f_liter(t_list *lst)
{
	char	*str;

	str = (char *)lst->content;
	while (*str)
		++(*str++);
}

static t_list	*f_lmap(t_list *lst)
{
	t_list		*dst;

	dst = ft_lstnew(lst->content, lst->content_size);
	f_liter(dst);
	return (dst);
}

static void	f_del(void *ptr, size_t size)
{
	memset(ptr, 'a', size - 1);
}
*/
static void	init(int tab[], int n, int c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		tab[i] = c;
		++i;
	}
}

static int	cmp(char *str1, char *str2)
{
	if (str1 && str2)
		return (strcmp(str1, str2));
	return (-42);
}

static int	ft_cmp(char *str1, char *str2)
{
	if (str1 && str2)
		return (ft_strcmp(str1, str2));
	return (-42);
}

static int	ncmp(char *str1, char *str2, size_t n)
{
	if (str1 && str2)
		return (strncmp(str1, str2, n));
	return (-42);
}

static int	ft_ncmp(char *str1, char *str2, size_t n)
{
	if (str1 && str2)
		return (ft_strncmp(str1, str2, n));
	return (-42);
}

static int	tabcmp(char **tab1, char **tab2)
{
	if (tab1 && tab2)
	{
		while(*tab1 && *tab2)
		{
			if ((cmp(*(tab1++), *(tab2++))))
				return (1);
		}
		if (*tab1 != *tab2)
			return (-12);
		return (0);
	}
	return (-24);
}

static void	test_sign(int test[], int ctrl[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (test[i] * ctrl[i] > 0)
			test[i] = ctrl[i];
		++i;
	}
}

static void	test_negate(int ctrl[], int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		ctrl[i] = !ctrl[i];
		++i;
	}
}

static void	free_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

static void	free_ctrl_tab(char **tab)
{
	int		i;

	if (tab)
	{
		i = 0;
		while (tab[i])
			free(tab[i++]);
	}
}

/*******************************************************************************/
/*                                                                             */
/*                            TEST FUNCTIONS                                   */
/*                                                                             */
/*******************************************************************************/

static void	test_atoi(void)
{
	int		test[32], ctrl[32];

	print_test_name("atoi");
	ctrl[0] = atoi("1230978");
	ctrl[1] = atoi("test");
	ctrl[2] = atoi("1230978");
	ctrl[3] = atoi("a1230978");
	ctrl[4] = atoi("1230978ébpo");
	ctrl[5] = atoi("1230978bépo");
	ctrl[6] = atoi("    + 001230978");
	ctrl[7] = atoi("    - 001230978");
	ctrl[8] = atoi("    -+0001230978");
	ctrl[9] = atoi("    +-0001230978");
	ctrl[10] = atoi("    --0001230978");
	ctrl[11] = atoi("    ++0001230978");
	ctrl[12] = atoi("    -1230978");
	ctrl[13] = atoi("    +1230978");
	ctrl[14] = atoi("0009990");
	ctrl[15] = atoi("00000");
	ctrl[16] = atoi("00001");
	ctrl[17] = atoi("00100");
	ctrl[18] = atoi("\t123");
	ctrl[19] = atoi("\n123");
	ctrl[20] = atoi("");
	ctrl[21] = atoi(" 01+1");
	ctrl[22] = atoi(" 01-1");
	ctrl[23] = atoi("3.14");
	ctrl[24] = atoi("3,14");
	ctrl[25] = atoi("9999999999");
	ctrl[26] = atoi("2147483647");
	ctrl[27] = atoi("-2147483648");
	ctrl[28] = atoi("\v123");
	ctrl[29] = atoi("\f123");
	ctrl[30] = atoi("\r123");
	ctrl[31] = atoi("\033123");
	test[0] = ft_atoi("1230978");
	test[1] = ft_atoi("test");
	test[2] = ft_atoi("1230978");
	test[3] = ft_atoi("a1230978");
	test[4] = ft_atoi("1230978ébpo");
	test[5] = ft_atoi("1230978bépo");
	test[6] = ft_atoi("    + 001230978");
	test[7] = ft_atoi("    - 001230978");
	test[8] = ft_atoi("    -+0001230978");
	test[9] = ft_atoi("    +-0001230978");
	test[10] = ft_atoi("    --0001230978");
	test[11] = ft_atoi("    ++0001230978");
	test[12] = ft_atoi("    -1230978");
	test[13] = ft_atoi("    +1230978");
	test[14] = ft_atoi("0009990");
	test[15] = ft_atoi("00000");
	test[16] = ft_atoi("00001");
	test[17] = ft_atoi("00100");
	test[18] = ft_atoi("\n123");
	test[19] = ft_atoi("\t123");
	test[20] = ft_atoi("");
	test[21] = ft_atoi(" 01+1");
	test[22] = ft_atoi(" 01-1");
	test[23] = ft_atoi("3.14");
	test[24] = ft_atoi("3,14");
	test[25] = ft_atoi("9999999999");
	test[26] = ft_atoi("2147483647");
	test[27] = ft_atoi("-2147483648");
	test[28] = ft_atoi("\v123");
	test[29] = ft_atoi("\f123");
	test[30] = ft_atoi("\r123");
	test[31] = ft_atoi("\033123");
	print_test_results_summary(test, ctrl, 32);
}

static void	test_bzero(void)
{
	int		test[2], ctrl[2];
	char	str1[]="test string",
			str2[]="test string",
			str3[]="one test string",
			str4[]="two test string";

	print_test_name("bzero");
	init(ctrl, 2, 0);
	init(test, 2, 0);
	bzero(str1, 0);
	ft_bzero(str2, 0);
	test[0] = cmp(str1, str2);
	bzero(str3, 10);
	ft_bzero(str4, 10);
	while (!(str3[ctrl[1]]))
		++(ctrl[1]);
	while (!(str4[test[1]]))
		++(test[1]);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_isalnum(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isalnum");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isalnum(i);
		test[i] = ft_isalnum(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isalpha(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isalpha");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isalpha(i);
		test[i] = ft_isalpha(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isascii(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isascii");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isascii(i);
		test[i] = ft_isascii(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isdigit(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isdigit");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isdigit(i);
		test[i] = ft_isdigit(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_isprint(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isprint");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isprint(i);
		test[i] = ft_isprint(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}
/*
static void	test_isspace(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("isspace");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = isspace(i);
		test[i] = ft_isspace(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}
*/
/*
static void	test_itoa(void)
{
	int		test[7], ctrl[7];
	char	str1[21], *str2;

	print_test_name("itoa");
	init(ctrl, 7, 0);
	init(test, 7, 1);
	snprintf(str1, 21, "%d", 0);
	str2 = ft_itoa(0);
	test[0] = cmp(str1, str2);
	free(str2);
	snprintf(str1, 21, "%d", 123);
	str2 = ft_itoa(123);
	test[1] = cmp(str1, str2);
	free(str2);
	snprintf(str1, 21, "%d", -123);
	str2 = ft_itoa(-123);
	test[2] = cmp(str1, str2);
	free(str2);
	snprintf(str1, 21, "%d", -9810);
	str2 = ft_itoa(-9810);
	test[3] = cmp(str1, str2);
	free(str2);
	snprintf(str1, 21, "%d", 189);
	str2 = ft_itoa(189);
	test[4] = cmp(str1, str2);
	free(str2);
	snprintf(str1, 21, "%d", INT_MAX);
	str2 = ft_itoa(INT_MAX);
	test[5] = cmp(str1, str2);
	free(str2);
	snprintf(str1, 21, "%d", INT_MIN);
	str2 = ft_itoa(INT_MIN);
	test[6] = cmp(str1, str2);
	print_test_results(test, ctrl, 7, NULL);
}
*/
/*
static void	test_lstadd(void)
{
	int		test[2], ctrl[2];
	t_list	*lst;

	print_test_name("lstadd");
	init(ctrl, 2, 0);
	init(test, 2, 1);
#ifdef SEGFAULT_ME
	lst = ft_lstnew("test string", sizeof(char) * 12);
	ft_lstadd(NULL, NULL);
	ft_lstadd(NULL, lst);
	free(lst->content);
	free(lst);
	ft_lstadd(&lst, NULL);
#endif
	lst = NULL;
	ft_lstadd(&lst, ft_lstnew("test2", sizeof(char) * 6));
	ft_lstadd(&lst, ft_lstnew("test1", sizeof(char) * 6));
	if (!cmp("test1", lst->content))
		test[0] = 0;
	if (!cmp("test2", lst->next->content))
		test[1] = 0;
	free(lst->next->content);
	free(lst->next);
	free(lst->content);
	free(lst);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_lstdel(void)
{
	int		test[2], ctrl[2];
	char	str[]="test string", *ptr1, *ptr2, *ptr3;
	size_t	n;
	t_list	*lst1, *lst2, *lst3;

	print_test_name("lstdel");
	init(ctrl, 2, 0);
	init(test, 2, 1);
	n = sizeof(*str) * (strlen(str) + 1);
#ifdef SEGFAULT_ME
	ft_lstdel(NULL, &f_del);
	lst1 = ft_lstnew(str, n);
	ptr1 = lst1->content;
	ft_lstdel(&lst1, NULL);
	free(ptr1);
	lst1 = NULL;
	ft_lstdel(&lst1, &f_del);
#endif
	lst1 = ft_lstnew(str, n);
	lst2 = ft_lstnew(str, n);
	lst3 = ft_lstnew(str, n);
	lst1->next = lst2;
	lst2->next = lst3;
	ptr1 = lst1->content;
	ptr2 = lst2->content;
	ptr3 = lst3->content;
	ft_lstdel(&lst1, &f_del);
	if (!lst1)
		test[0] = 0;
	if (!cmp("aaaaaaaaaaa", ptr1) && !cmp("aaaaaaaaaaa", ptr2) && !cmp("aaaaaaaaaaa", ptr2))
		test[1] = 0;
	free(ptr1);
	free(ptr2);
	free(ptr3);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_lstdelone(void)
{
	int		test[4], ctrl[4];
	char	str[]="test string", *ptr1, *ptr2;
	size_t	n;
	t_list	*lst1, *lst2;

	print_test_name("lstdelone");
	init(ctrl, 4, 0);
	init(test, 4, 1);
	n = sizeof(*str) * (strlen(str) + 1);
#ifdef SEGFAULT_ME
	ft_lstdelone(NULL, &f_del);
	lst1 = ft_lstnew(str, n);
	ptr1 = lst1->content;
	ft_lstdelone(&lst1, NULL);
	free(ptr1);
	lst1 = NULL;
	ft_lstdelone(&lst1, &f_del);
#endif
	lst1 = ft_lstnew(str, n);
	lst2 = ft_lstnew(str, n);
	lst1->next = lst2;
	ptr1 = lst1->content;
	ptr2 = lst2->content;
	ft_lstdelone(&lst1, &f_del);
	if (!lst1)
		test[0] = 0;
	if (lst2->content == ptr2 && lst2->content_size == n && !lst2->next)
		test[1] = 0;
	if (!cmp("aaaaaaaaaaa", ptr1))
		test[2] = 0;
	if (!cmp(str, lst2->content))
		test[3] = 0;
	free(ptr1);
	free(ptr2);
	free(lst2);
	print_test_results(test, ctrl, 4, NULL);
}

static void	test_lstiter(void)
{
	int		test[1], ctrl[1];
	t_list	*lst;

	print_test_name("lstiter");
	init(ctrl, 1, 0);
	init(test, 1, 1);
#ifdef SEGFAULT_ME
	ft_lstiter(NULL, &f_liter);
	lst = ft_lstnew("test string", sizeof(char) * 12);
	ft_lstiter(lst, NULL);
	free(lst->content);
	free(lst);
	ft_lstiter(NULL, NULL);
#endif
	lst = NULL;
	ft_lstadd(&lst, ft_lstnew("test3", 5));
	ft_lstadd(&lst, ft_lstnew("test2", 5));
	ft_lstadd(&lst, ft_lstnew("test1", 5));
	ft_lstiter(lst, &f_liter);
	ft_lstiter(lst, &f_liter);
	if (!cmp((char *)lst->content, "vguv3")
		&& !cmp((char *)lst->next->content, "vguv4")
		&& !cmp((char *)lst->next->next->content, "vguv5"))
		test[0] = 0;
	print_test_results(test, ctrl, 1, NULL);
}

static void	test_lstmap(void)
{
	int		test[3], ctrl[3];
	t_list	*lst1, *lst2;

	print_test_name("lstmap");
	init(ctrl, 3, 0);
	init(test, 3, 1);
#ifdef SEGFAULT_ME
	ft_lstmap(NULL, &f_lmap);
	lst1 = ft_lstnew("test string", sizeof(char) * 12);
	ft_lstmap(lst1, NULL);
	free(lst1->content);
	free(lst1);
	ft_lstmap(NULL, NULL);
#endif
	lst1 = NULL;
	ft_lstadd(&lst1, ft_lstnew("test3", 5));
	ft_lstadd(&lst1, ft_lstnew("test2", 5));
	ft_lstadd(&lst1, ft_lstnew("test1", 5));
	lst2 = ft_lstmap(lst1, &f_lmap);
	if (!cmp((char *)lst2->content, "uftu2")
		&& !cmp((char *)lst2->next->content, "uftu3")
		&& !cmp((char *)lst2->next->next->content, "uftu4"))
		test[0] = 0;
	if (lst2->content_size == 5
		&& lst2->next->content_size == 5
		&& lst2->next->next->content_size == 5)
		test[1] = 0;
	if (!lst2->next->next->next)
		test[2] = 0;
	print_test_results(test, ctrl, 3, NULL);
}
*/
static void	test_lstnew(void)
{
	int		test[11], ctrl[11], warning[]={8, -1};
	char	str[]="test string";
	t_list	*lst;

	print_test_name("lstnew");
	init(ctrl, 11, 0);
	init(test, 11, 1);
	lst = ft_lstnew(str, sizeof(*str) * (strlen(str) + 1));
	if (lst)
	{
		test[0] = cmp(str, lst->content);
		if (str != lst->content)
			test[1] = 0;
		if (lst->content_size == sizeof(*str) * (strlen(str) + 1))
			test[2] = 0;
		if (!lst->next)
			test[3] = 0;
		free(lst->content);
		free(lst);
	}
	lst = ft_lstnew(NULL, 10);
	if (lst)
	{
		if (!lst->content)
			test[4] = 0;
		if (lst->content_size == 0)
			test[5] = 0;
		if (!lst->next)
			test[6] = 0;
		free(lst->content);
		free(lst);
	}
	lst = ft_lstnew(str, SIZE_MAX);
	if (!lst)
		test[7] = 0;
	else
	{
		free(lst->content);
		free(lst);
	}
	lst = ft_lstnew(str, 0);
	if (lst)
	{
		if (!lst->content)
			test[8] = 0;
		if (lst->content_size == 0)
			test[9] = 0;
		if (!lst->next)
			test[10] = 0;
		free(lst->content);
		free(lst);
	}
	print_test_results(test, ctrl, 11, warning);
}

static void	test_memalloc(void)
{
	int		test[2], ctrl[2];
	void	*ptr;

	print_test_name("memalloc");
	ctrl[0] = 512;
	if (!(ptr = ft_memalloc(ctrl[0])))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	test[0] = 0;
	while (test[0] < ctrl[0] && !(*((unsigned char*)ptr)))
		++(test[0]);
	free(ptr);
	ctrl[1] = 0;
	test[1] = 1;
	if (!(ptr = ft_memalloc(SIZE_MAX)))
		test[1] = 0;
	free(ptr);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_memccpy(void)
{
	int		test[6], ctrl[6];
	char	dst1[]="abcdefghijklmnopqrstuvwxyz", src1[]="test",
			dst2[]="abcdefghijklmnopqrstuvwxyz", src2[]="test",
			dst3[]="abcdefghijklmnopqrstuvwxyz", src3[]="test\200string",
			dst4[]="abcdefghijklmnopqrstuvwxyz", src4[]="test\200string";
	void	*ptr1, *ptr2;

	print_test_name("memccpy");
	init(ctrl, 6, 0);
	init(test, 6, 1);
	src1[0] = '\0';
	src2[0] = '\0';
	ptr1 = memccpy(dst1, src1, '0', 4);
	ptr2 = ft_memccpy(dst2, src2, '0', 4);
	test[0] = memcmp(dst1, dst2, 27);
	if (ptr1 == ptr2)
		test[1] = 0;
	memccpy(dst1, src1, '0', 5);
	ft_memccpy(dst2, src2, '0', 5);
	test[2] = memcmp(dst1, dst2, 27);
	memccpy(dst3, src3, '\200', 12);
	ft_memccpy(dst4, src4, '\200', 12);
	test[3] = memcmp(dst3, dst4, 27);
	memccpy(dst3, src3, 'r', 12);
	ft_memccpy(dst4, src4, 'r', 12);
	test[4] = memcmp(dst3, dst4, 27);
	ptr1 = memccpy(dst3, src3, 'g', 12);
	ptr2 = ft_memccpy(dst3, src3, 'g', 12);
	if (ptr1 == ptr2)
		test[5] = 0;
	else
		test[5] = 1;
	print_test_results(test, ctrl, 6, NULL);
}

static void	test_memchr(void)
{
	int		test[5], ctrl[5];
	char	str1[]="test\200string", *str2;

	print_test_name("memchr");
	init(ctrl, 5, 0);
	init(test, 5, 1);
	if (memchr(str1, 'a', 12) == ft_memchr(str1, 'a', 12))
		test[0] = 0;
	if (memchr(str1, '\200', 12) == ft_memchr(str1, '\200', 12))
		test[1] = 0;
	if (memchr(str1, 'g', 10) == ft_memchr(str1, 'g', 10))
		test[2] = 0;
	if (memchr(str1, 'g', 11) == ft_memchr(str1, 'g', 11))
		test[3] = 0;
	if (!(str2 = (char *)malloc(sizeof(*str2) * 2)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	str2[0] = '\0';
	str2[1] = 'a';
	if (memchr(str2, 'a', 2) == ft_memchr(str2, 'a', 2))
		test[4] = 0;
	free(str2);
	print_test_results(test, ctrl, 5, NULL);
}

static void	test_memcmp(void)
{
	int		test[4], ctrl[4];
	char	str1[]="test string", str2[]="test spring";

	print_test_name("memcmp");
	test[0] = memcmp(str1, str2, 12);
	ctrl[0] = ft_memcmp(str1, str2, 12);
	test[1] = memcmp(str1, str2, 6);
	ctrl[1] = ft_memcmp(str1, str2, 6);
	test[2] = memcmp("a", "b", 0);
	ctrl[2] = ft_memcmp("a", "b", 0);
	str1[1] = '\0';
	str2[1] = '\0';
	str1[2] = 'a';
	str2[2] = 'b';
	test[3] = memcmp(str1, str2, 3);
	ctrl[3] = ft_memcmp(str1, str2, 3);
	print_test_results(test, ctrl, 4, NULL);
}

static void	test_memcpy(void)
{
	int		test[5], ctrl[5], n;
	char	str1[]="test string", *str2, *str3;

	print_test_name("memcpy");
	init(ctrl, 5, 0);
	init(test, 5, 1);
	if (!(str2 = malloc(sizeof(*str2) * 20)) || !(str3 = malloc(sizeof(*str3) * 20)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	memset(str2, 'a', 20);
	memset(str3, 'a', 20);
	n = strlen(str1);
	test[0] = memcmp(memcpy(str2, str1, 0), ft_memcpy(str3, str1, 0), 20);
	test[1] = memcmp(memcpy(str2, str1, 1), ft_memcpy(str3, str1, 1), 20);
	test[2] = memcmp(memcpy(str2, str1, n), ft_memcpy(str3, str1, n), 20);
	test[3] = memcmp(memcpy(str2, str1, n + 1), ft_memcpy(str3, str1, n + 1), 20);
	str1[n - 1] = '\0';
	str1[n] = 'z';
	test[4] = memcmp(memcpy(str2, str1, n + 1), ft_memcpy(str3, str1, n + 1), 20);
	free(str2);
	free(str3);
	print_test_results(test, ctrl, 5, NULL);
}

static void	test_memdel(void)
{
	int		test[1], ctrl[1];
	void	*ptr;

	print_test_name("memdel");
#ifdef SEGFAULT_ME
	ptr = NULL;
	ft_memdel(NULL);
	ft_memdel(&ptr);
#endif
	if (!(ptr = malloc(1)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	ctrl[0] = 0;
	test[0] = 1;
	ft_memdel(&ptr);
	if (!ptr)
		test[0] = 0;
	free(ptr);
	print_test_results(test, ctrl, 1, NULL);
}

static void	test_memmove(void)
{
	int		test[5], ctrl[5];
	char	str1[]="abcdefghijklmnopqrstuvwxyz", str2[]="abcdefghijklmnopqrstuvwxyz",
			str3[]="abcdefghijklmnopqrstuvwxyz", str4[]="abcdefghijklmnopqrstuvwxyz",
			str5[]="abcdefghijklmnopqrstuvwxyz", str6[]="abcdefghijklmnopqrstuvwxyz";

	print_test_name("memmove");
	init(ctrl, 5, 0);
	init(test, 5, 1);
	memmove(str1 + 3, str1, 0);
	ft_memmove(str2 + 3, str2, 0);
	test[0] = memcmp(str1, str2, 27);
	memmove(str1 + 3, str1, 8);
	ft_memmove(str2 + 3, str2, 8);
	test[1] = memcmp(str1, str2, 27);
	str1[2] = '\0';
	str2[2] = '\0';
	memmove(str1 + 3, str1, 8);
	ft_memmove(str2 + 3, str2, 8);
	test[2] = memcmp(str1, str2, 27);
	test[3] = memcmp(memmove(str3, str3 + 5, 8), ft_memmove(str4, str4 + 5, 8), 27);
	test[4] = memcmp(memmove(str5, str5, 10), ft_memmove(str6, str6, 10), 27);
	print_test_results(test, ctrl, 5, NULL);
}

static void	test_memset(void)
{
	int		test[4], ctrl[4];
	char	str1[]="don't kill me\n",
			str2[]="don't kill me\n";

	print_test_name("memset");
	init(ctrl, 4, 0);
	init(test, 4, 1);
	str1[3] = '\0';
	str2[3] = '\0';
	test[0] = memcmp(memset(str1, '-', 0), ft_memset(str2, '-', 0), 15);
	test[1] = memcmp(memset(str1, '-', 1), ft_memset(str2, '-', 1), 15);
	test[2] = memcmp(memset(str1, '-', 5), ft_memset(str2, '-', 5), 15);
	test[3] = memcmp(memset(str1, 0, 5), ft_memset(str2, 0, 5), 15);
	print_test_results(test, ctrl, 4, NULL);
}

static void	test_strcat(void)
{
	int		test[1], ctrl[1];
	char	*dst1, *dst2, src[]="test";

	print_test_name("strcat");
	if (!(dst1 = malloc(sizeof(*dst1) * (strlen(src) + 1) * 3)) || !(dst2 = malloc(sizeof(*dst2) * (strlen(src) + 1) * 3)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	ctrl[0] = 0;
	test[0] = cmp(strcat(dst1, src), ft_strcat(dst2, src));
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 1, NULL);
}

static void	test_strchr(void)
{
	int		test[3], ctrl[3];
	char	str[]="test string test string test string";

	print_test_name("strchr");
	init(ctrl, 3, 0);
	init(test, 3, 1);
	if (strchr(str, ' ') == ft_strchr(str, ' '))
		test[0] = 0;
	if (strchr(str, '\0') == ft_strchr(str, '\0'))
		test[1] = 0;
	if (strchr(str, '@') == ft_strchr(str, '@'))
		test[2] = 0;
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_strclr(void)
{
	int		test[2], ctrl[2], i, n;
	char	str1[]="\0abc", str2[]="\377abc\200\377";

	print_test_name("strclr");
#ifdef SEGFAULT_ME
	ft_strclr(NULL);
#endif
	init(ctrl, 2, 0);
	init(test, 2, 1);
	ft_strclr(str1);
	if (!(*str1) && str1[1] && str1[3] && !str1[4])
		test[0] = 0;
	i = 0;
	n = strlen(str2) + 1;
	ft_strclr(str2);
	while (!str2[i] && i < n)
		++i;
	if (i == n)
		test[1] = 0;
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strcmp(void)
{
	int		test[9], ctrl[9];

	/*                  /!\ strcmp and strncmp                               */
	/* ********************************************************************* */
	/* Only the sign of the values returned by strcmp and strncmp matters !! */
	/* ********************************************************************* */
	/* If you make your own tests or use them in your programs, depending on */
	/* the code written, gcc will sometimes make optimizations resulting in  */
	/* strcmp and strncmp returning -1, 0, or 1, instead of the exact        */
	/* difference between the values of the unsigned chars, as you've been   */
	/* led to expect. Your own ft_ versions won't do such a thing though and */
	/* you will get a false fail if you're not cautious.                     */
	
	/* This test takes only the sign into account. */
	print_test_name("strcmp");
	ctrl[0] = cmp("test string", "test string");
	ctrl[1] = cmp("test string", "test spring");
	ctrl[2] = cmp("test string", "test string ");
	ctrl[3] = cmp("test string ", "test string");
	ctrl[4] = cmp("", "test");
	ctrl[5] = cmp("test", "");
	ctrl[6] = cmp("", "");
	ctrl[7] = cmp("\200\230\100\255", "\200\230\100\255");
	ctrl[8] = cmp("\200\230\100\255", "\0\230\100\255");
	test[0] = ft_cmp("test string", "test string");
	test[1] = ft_cmp("test string", "test spring");
	test[2] = ft_cmp("test string", "test string ");
	test[3] = ft_cmp("test string ", "test string");
	test[4] = ft_cmp("", "test");
	test[5] = ft_cmp("test", "");
	test[6] = ft_cmp("", "");
	test[7] = ft_cmp("\200\230\100\255", "\200\230\100\255");
	test[8] = ft_cmp("\200\230\100\255", "\0\230\100\255");
	test_sign(test, ctrl, 9);
	print_test_results(test, ctrl, 9, NULL);
}

static void	test_strcpy(void)
{
	int		test[2], ctrl[2];
	char	*dst1, *dst2, src1[]="\001test string\200", src2[]="test";

	print_test_name("strcpy");
	init(ctrl, 2, 0);
	init(test, 2, 1);
	if (!(dst1 = malloc(strlen(src1) + 1)) || !(dst2 = malloc(strlen(src1) + 1)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	test[0] = cmp(strcpy(dst1, src1), ft_strcpy(dst2, src1));
	ft_strcpy(dst1, src2);
	if (!dst1[strlen(src2)])
		test[1] = 0;
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strdel(void)
{
	int		test[1], ctrl[1];
	char	*str;

	print_test_name("strdel");
#ifdef SEGFAULT_ME
	str = NULL;
	ft_strdel(NULL);
	ft_strdel(&str);
#endif
	if (!(str = (char *)malloc(sizeof(*str) * 5)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	ctrl[0] = 0;
	test[0] = 1;
	ft_strdel(&str);
	if (!str)
		test[0] = 0;
	free(str);
	print_test_results(test, ctrl, 1, NULL);
}

static void	test_strdup(void)
{
	int		test[3], ctrl[3];
	char	*dst, src[]="test string";

	print_test_name("strdup");
	init(ctrl, 3, 0);
	init(test, 3, 1);
	dst = ft_strdup(src);
	test[0] = cmp(src, dst);
	if (!dst[strlen(src)])
		test[1] = 0;
	free(dst);
	dst = ft_strdup("");
	if (dst && !(*dst))
		test[2] = 0;
	free(dst);
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_strequ(void)
{
	int		test[12], ctrl[12], warning[]={9, -1};
	
	print_test_name("strequ");
#ifdef SEGFAULT_ME
	ctrl[9] = 0;
	ctrl[10] = 0;
	ctrl[11] = 0;
	test[9] = ft_strequ(NULL, NULL);
	test[10] = ft_strequ("test", NULL);
	test[11] = ft_strequ(NULL, "test");
#endif
	ctrl[0] = cmp("test string", "test string");
	ctrl[1] = cmp("test string", "test spring");
	ctrl[2] = cmp("test string", "test string ");
	ctrl[3] = cmp("test string ", "test string");
	ctrl[4] = cmp("", "test");
	ctrl[5] = cmp("test", "");
	ctrl[6] = cmp("", "");
	ctrl[7] = cmp("\200\230\100\255", "\200\230\100\255");
	ctrl[8] = cmp("\200\230\100\255", "\0\230\100\255");
	test[0] = ft_strequ("test string", "test string");
	test[1] = ft_strequ("test string", "test spring");
	test[2] = ft_strequ("test string", "test string ");
	test[3] = ft_strequ("test string ", "test string");
	test[4] = ft_strequ("", "test");
	test[5] = ft_strequ("test", "");
	test[6] = ft_strequ("", "");
	test[7] = ft_strequ("\200\230\100\255", "\200\230\100\255");
	test[8] = ft_strequ("\200\230\100\255", "\0\230\100\255");
	test_negate(ctrl, 9);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 12, warning);
#else
	print_test_results(test, ctrl, 9, warning);
#endif
}

static void	test_striter(void)
{
	int		test[2], ctrl[2];
	char	str1[]="", str2[]="abcdefg";

	print_test_name("striter");
#ifdef SEGFAULT_ME
	ft_striter(NULL, NULL);
	ft_striter("test", NULL);
	ft_striter("", NULL);
	ft_striter(NULL, f_iter);
#endif
	init(ctrl, 2, 0);
	ft_striter(str1, &f_iter);
	test[0] = cmp(str1, "");
	ft_striter(str2, &f_iter);
	test[1] = cmp(str2, "bcdefgh");
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_striteri(void)
{
	int		test[2], ctrl[2];
	char	str1[]="", str2[]="abcdefg";

	print_test_name("striteri");
#ifdef SEGFAULT_ME
	ft_striteri(NULL, NULL);
	ft_striteri("test", NULL);
	ft_striteri("", NULL);
	ft_striteri(NULL, f_iteri);
#endif
	init(ctrl, 2, 0);
	ft_striteri(str1, &f_iteri);
	test[0] = cmp(str1, "");
	ft_striteri(str2, &f_iteri);
	test[1] = cmp(str2, "acegikm");
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strjoin(void)
{
	int		test[8], ctrl[8], warning[]={4, 5, 6, 7, -1};
	char	*str;

	print_test_name("strjoin");
	init(ctrl, 8, 0);
	init(test, 8, 1);
#ifdef SEGFAULT_ME
	str = ft_strjoin(NULL, NULL);
	if (!str)
		test[5] = 0;
	free(str);
	/* Tests 6 and 7 are a personnal opinion          */
	/* on what the behavior of strjoin should be when */
	/* one of the pointers is NULL. Some will argue   */
	/* that we should return NULL in such a case.     */
	/* I chose to return a copy of the non NUL string */
	/* ( => behave like a strdup)                     */
	str = ft_strjoin(NULL, "test");
	test[6] = cmp("test", str);
	free(str);
	str = ft_strjoin("test", NULL);
	test[7] = cmp("test", str);
	free(str);
#endif
	str = ft_strjoin("test", "string");
	test[0] = cmp("teststring", str);
	free(str);
	str = ft_strjoin("O", "K");
	test[1] = cmp("OK", str);
	free(str);
	str = ft_strjoin("test", "");
	test[2] = cmp("test", str);
	free(str);
	str = ft_strjoin("", "test");
	test[3] = cmp("test", str);
	free(str);
	str = ft_strjoin("", "");
	test[4] = cmp("", str);
	free(str);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 8, warning);
#else
	print_test_results(test, ctrl, 5, warning);
#endif	
}

static void	test_strlcat(void)
{
	size_t	n;
	int		test[4], ctrl[4];
	char	*dst1, *dst2, src[]="test string";

	print_test_name("strlcat");
	init(ctrl, 4, 0);
	n = (strlen(src) + 1);
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	test[0] = strlcat(dst1, src, n / 2) - ft_strlcat(dst2, src, n / 2);
	strlcat(dst1, src, n);
	ft_strlcat(dst2, src, n);
	test[1] = cmp(dst1, dst2);
	free(dst1);
	free(dst2);
	n = n * 2 + n / 2;
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	strlcat(dst1, src, n);
	ft_strlcat(dst2, src, n);
	test[2] = cmp(dst1, dst2);
	strlcat(dst1, src, n);
	ft_strlcat(dst2, src, n);
	test[3] = cmp(dst1, dst2);
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 4, NULL);
}
/*
static void	test_strlcpy(void)
{
	int		test[6], ctrl[6];
	char	*dst1, *dst2, src[]="test string";

	print_test_name("strlcpy");
	init(ctrl, 6, 0);
	if (!(dst1 = (char *)malloc(sizeof(*dst1) * 20)) || !(dst2 = (char *)malloc(sizeof(*dst2) * 20)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	strlcpy(dst1, src, 20);
	ft_strlcpy(dst2, src, 20);
	test[0] = cmp(dst1, dst2);
	strlcpy(dst1, src, 0);
	ft_strlcpy(dst2, src, 0);
	test[1] = cmp(dst1, dst2);
	strlcpy(dst1, src, 5);
	ft_strlcpy(dst2, src, 5);
	test[2] = cmp(dst1, dst2);
	strlcpy(dst1, src, 2);
	ft_strlcpy(dst2, src, 2);
	test[3] = cmp(dst1, dst2);
	ctrl[5] = strlcpy(dst1, src, 1);
	test[5] = ft_strlcpy(dst2, src, 1);
	test[4] = cmp(dst1, dst2);
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 6, NULL);
}
*/
static void	test_strlen(void)
{
	int		test[2], ctrl[2];

	print_test_name("strlen");
	test[0] = strlen("");
	ctrl[0] = ft_strlen("");
	test[1] = strlen("\001\002\003\004\005\200");
	ctrl[1] = ft_strlen("\001\002\003\004\005\200");
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strmap(void)
{
	int		test[8], ctrl[8];
	char	str1[]="", str2[]="abcdefg", *ptr1, *ptr2;

	print_test_name("strmap");
	init(ctrl, 8, 0);
	init(test, 8, 1);
#ifdef SEGFAULT_ME
	if (!ft_strmap(NULL, NULL))
		test[4] = 0;
	if (!ft_strmap("test", NULL))
		test[5] = 0;
	if (!ft_strmap("", NULL))
		test[6] = 0;
	if (!ft_strmap(NULL, f_map))
		test[7] = 0;
#endif
	ptr1 = ft_strmap(str1, &f_map);
	test[0] = cmp(str1, "");
	test[1] = cmp(ptr1, "");
	ptr2 = ft_strmap(str2, &f_map);
	test[2] = cmp(str2, "abcdefg");
	test[3] = cmp(ptr2, "bcdefgh");
	free(ptr1);
	free(ptr2);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 8, NULL);
#else	
	print_test_results(test, ctrl, 4, NULL);
#endif
}

static void	test_strmapi(void)
{
	int		test[8], ctrl[8];
	char	str1[]="", str2[]="abcdefg", *ptr1, *ptr2;

	print_test_name("strmapi");
	init(ctrl, 8, 0);
	init(test, 8, 1);
#ifdef SEGFAULT_ME
	if (!ft_strmapi(NULL, NULL))
		test[4] = 0;
	if (!ft_strmapi("test", NULL))
		test[5] = 0;
	if (!ft_strmapi("", NULL))
		test[6] = 0;
	if (!ft_strmapi(NULL, f_mapi))
		test[7] = 0;
#endif
	ptr1 = ft_strmapi(str1, &f_mapi);
	test[0] = cmp(str1, "");
	test[1] = cmp(ptr1, "");
	ptr2 = ft_strmapi(str2, &f_mapi);
	test[2] = cmp(str2, "abcdefg");
	test[3] = cmp(ptr2, "acegikm");
	free(ptr1);
	free(ptr2);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 8, NULL);
#else	
	print_test_results(test, ctrl, 4, NULL);
#endif
}

static void	test_strncat(void)
{
	int		test[3], ctrl[3];
	char	*dst1, *dst2, src[]="test string";

	print_test_name("strncat");
	init(ctrl, 3, 0);
	if (!(dst1 = malloc(sizeof(*dst1) * 100)) || !(dst2 = malloc(sizeof(*dst2) * 100)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	strcpy(dst1, src);
	strcpy(dst2, src);
	test[0] = cmp(strncat(dst1, src, 0), ft_strncat(dst2, src, 0));
	test[1] = cmp(strncat(dst1, src, 6), ft_strncat(dst2, src, 6));
	test[2] = cmp(strncat(dst1, src, 50), ft_strncat(dst2, src, 50));
	free(dst1);
	free(dst2);
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_strncmp(void)
{
	int		test[14], ctrl[14];

	/*                  /!\ strcmp and strncmp                               */
	/* ********************************************************************* */
	/* Only the sign of the values returned by strcmp and strncmp matters !! */
	/* ********************************************************************* */
	/* If you make your own tests or use them in your programs, depending on */
	/* the code written, gcc will sometimes make optimizations resulting in  */
	/* strcmp and strncmp returning -1, 0, or 1, instead of the exact        */
	/* difference between the values of the unsigned chars, as you've been   */
	/* led to expect. Your own ft_ versions won't do such a thing though and */
	/* you will get a false fail if you're not cautious.                     */
	
	/* This test takes only the sign into account. */
	print_test_name("strncmp");
	ctrl[0] = ncmp("test string", "test string", 0);
	ctrl[1] = ncmp("test string", "test string", 30);
	ctrl[2] = ncmp("test string", "test spring", 6);
	ctrl[3] = ncmp("test string", "test spring", 7);
	ctrl[4] = ncmp("test string", "test spring", 8);
	ctrl[5] = ncmp("test string", "test string    ", 12);
	ctrl[6] = ncmp("test string", "test string    ", 30);
	ctrl[7] = ncmp("", "test", 0);
	ctrl[8] = ncmp("", "", 0);
	ctrl[9] = ncmp("", "", 1);
	ctrl[10] = ncmp("", "", 2);
	ctrl[11] = ncmp("\200\230\100\255", "\200\230\100\255", 5);
	ctrl[12] = ncmp("\200\230\100\255", "\200\0\100\255", 5);
	ctrl[13] = ncmp("", "a", 1);
	test[0] = ft_ncmp("test string", "test string", 0);
	test[1] = ft_ncmp("test string", "test string", 30);
	test[2] = ft_ncmp("test string", "test spring", 6);
	test[3] = ft_ncmp("test string", "test spring", 7);
	test[4] = ft_ncmp("test string", "test spring", 8);
	test[5] = ft_ncmp("test string", "test string    ", 12);
	test[6] = ft_ncmp("test string", "test string    ", 30);
	test[7] = ft_ncmp("", "test", 0);
	test[8] = ft_ncmp("", "", 0);
	test[9] = ft_ncmp("", "", 1);
	test[10] = ft_ncmp("", "", 2);
	test[11] = ft_ncmp("\200\230\100\255", "\200\230\100\255", 5);
	test[12] = ft_ncmp("\200\230\100\255", "\200\0\100\255", 5);
	test[13] = ft_ncmp("", "a", 1);
	test_sign(test, ctrl, 14);
	print_test_results_summary(test, ctrl, 14);
}

static void	test_strncpy(void)
{
	int		test[2], ctrl[2];
	size_t	n;
	char	*dst1, *dst2, src[]="test string";

	print_test_name("strncpy");
	init(ctrl, 2, 0);
	n = strlen(src) + 4;
	if (!(dst1 = malloc(sizeof(*dst1) * n)) || !(dst2 = malloc(sizeof(*dst2) * n)))
	{
		perror("malloc() failed");
		exit(EXIT_FAILURE);
	}
	memset(dst1, 'a', sizeof(*dst1) * n);
	memset(dst2, 'a', sizeof(*dst2) * n);
	dst1[n - 1] = '\0';
	dst2[n - 1] = '\0';
	test[0] = memcmp(strncpy(dst1, src, 3), ft_strncpy(dst2, src, n), 3);
	memset(dst1, 'a', sizeof(*dst1) * n);
	memset(dst2, 'a', sizeof(*dst2) * n);
	test[1] = memcmp(strncpy(dst1, src, n), ft_strncpy(dst2, src, n), n);
	
	print_test_results(test, ctrl, 2, NULL);
}

static void	test_strnequ(void)
{
	int		test[16], ctrl[16];

	print_test_name("strnequ");
#ifdef SEGFAULT_ME
	ctrl[13] = 0;
	ctrl[14] = 0;
	ctrl[15] = 0;
	test[13] = ft_strnequ(NULL, NULL, 5);
	test[14] = ft_strnequ("test", NULL, 5);
	test[15] = ft_strnequ(NULL, "test", 5);
#endif
	ctrl[0] = ncmp("test string", "test string", 0);
	ctrl[1] = ncmp("test string", "test string", 30);
	ctrl[2] = ncmp("test string", "test spring", 6);
	ctrl[3] = ncmp("test string", "test spring", 7);
	ctrl[4] = ncmp("test string", "test spring", 8);
	ctrl[5] = ncmp("test string", "test string    ", 12);
	ctrl[6] = ncmp("test string", "test string    ", 30);
	ctrl[7] = ncmp("", "test", 0);
	ctrl[8] = ncmp("", "", 0);
	ctrl[9] = ncmp("", "", 1);
	ctrl[10] = ncmp("", "", 2);
	ctrl[11] = ncmp("\200\230\100\255", "\200\230\100\255", 5);
	ctrl[12] = ncmp("\200\230\100\255", "\200\0\100\255", 5);
	test[0] = ft_strnequ("test string", "test string", 0);
	test[1] = ft_strnequ("test string", "test string", 30);
	test[2] = ft_strnequ("test string", "test spring", 6);
	test[3] = ft_strnequ("test string", "test spring", 7);
	test[4] = ft_strnequ("test string", "test spring", 8);
	test[5] = ft_strnequ("test string", "test string    ", 12);
	test[6] = ft_strnequ("test string", "test string    ", 30);
	test[7] = ft_strnequ("", "test", 0);
	test[8] = ft_strnequ("", "", 0);
	test[9] = ft_strnequ("", "", 1);
	test[10] = ft_strnequ("", "", 2);
	test[11] = ft_strnequ("\200\230\100\255", "\200\230\100\255", 5);
	test[12] = ft_strnequ("\200\230\100\255", "\200\0\100\255", 5);
	test_negate(ctrl, 13);
#ifdef SEGFAULT_ME
	print_test_results_summary(test, ctrl, 16);
#else
	print_test_results_summary(test, ctrl, 13);
#endif
}

static void	test_strnew(void)
{
	int		test[3], ctrl[3], warning[]={2, -1};
	char	*str;

	print_test_name("strnew");
	init(ctrl, 3, 0);
	init(test, 3, 1);
#ifdef SEGFAULT_ME
	if (!(str = ft_strnew(SIZE_MAX)))
		test[2] = 0;
	free(str);
#endif
	ctrl[0] = 512;
	str = ft_strnew(ctrl[0]);
	test[0] = 0;
	while (test[0] < ctrl[0] && !(*str))
		++(test[0]);
	free(str);
	if (!(str = ft_strnew(SIZE_MAX - 1)))
		test[1] = 0;
	free(str);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 3, warning);
#else
	print_test_results(test, ctrl, 2, warning);
#endif
}

static void	test_strnstr(void)
{
	int		test[14], ctrl[14];
	char	str[]="test\200string test\200string";

	print_test_name("strnstr");
	init(ctrl, 14, 0);
	init(test, 14, 1);
	if (strnstr(str, "test", 6) == ft_strnstr(str, "test", 6))
		test[0] = 0;
	if (strnstr(str, "test", 5) == ft_strnstr(str, "test", 5))
		test[1] = 0;
	if (strnstr(str, "test", 4) == ft_strnstr(str, "test", 4))
		test[2] = 0;
	if (strnstr(str, "test", 3) == ft_strnstr(str, "test", 3))
		test[3] = 0;
	if (strnstr(str, "string", 10) == ft_strnstr(str, "string", 10))
		test[4] = 0;
	if (strnstr(str, "string", 11) == ft_strnstr(str, "string", 11))
		test[5] = 0;
	if (strnstr(str, "string", 12) == ft_strnstr(str, "string", 12))
		test[6] = 0;
	if (strnstr(str, "string", 30) == ft_strnstr(str, "string", 30))
		test[7] = 0;
	if (strnstr(str, "\200", 15) == ft_strnstr(str, "\200", 15))
		test[8] = 0;
	if (strnstr(str, "@", 30) == ft_strnstr(str, "@", 30))
		test[9] = 0;
	if (strnstr(str, str, strlen(str)) == ft_strnstr(str, str, strlen(str)))
		test[10] = 0;
	if (strnstr(str, str, strlen(str) + 1) == ft_strnstr(str, str, strlen(str) + 1))
		test[11] = 0;
	if (strnstr(str, str, strlen(str) - 1) == ft_strnstr(str, str, strlen(str) - 1))
		test[12] = 0;
	if (strnstr(str, "ingr", strlen(str)) == ft_strnstr(str, "ingr", strlen(str)))
		test[13] = 0;
	print_test_results_summary(test, ctrl, 14);
}

static void	test_strrchr(void)
{
	int		test[3], ctrl[3];
	char	str[]="test string test string test string";

	print_test_name("strrchr");
	init(ctrl, 3, 0);
	init(test, 3, 1);
	if (strrchr(str, ' ') == ft_strrchr(str, ' '))
		test[0] = 0;
	if (strrchr(str, '\0') == ft_strrchr(str, '\0'))
		test[1] = 0;
	if (strrchr(str, '@') == ft_strrchr(str, '@'))
		test[2] = 0;
	print_test_results(test, ctrl, 3, NULL);
}

static void	test_strsplit(void)
{
	int		test[11], ctrl[11];
	char	**tab, **ctrl_tab;

	print_test_name("strsplit");
	init(ctrl, 11, 0);
	init(test, 11, 1);
	if (!(ctrl_tab = (char **)malloc(sizeof(*ctrl_tab) * 10)))
	{
		perror("malloc() failed here");
		exit(EXIT_FAILURE);
	}
#ifdef SEGFAULT_ME
	tab = ft_strsplit(NULL, ' ');
	if (!tab)
		test[10] = 0;
#endif
	ctrl_tab[0] = strdup("test");
	ctrl_tab[1] = strdup("my");
	ctrl_tab[2] = strdup("function");
	ctrl_tab[3] = NULL;
	tab = ft_strsplit("       test my  function   ", ' ');
	test[0] = tabcmp(tab, ctrl_tab);
	if (!tab[3])
		test[1] = 0;
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = strdup("t");
	ctrl_tab[1] = NULL;
	tab = ft_strsplit("t", ' ');
	test[2] = tabcmp(tab, ctrl_tab);
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = strdup("test");
	ctrl_tab[1] = strdup("my");
	ctrl_tab[2] = strdup("function");
	ctrl_tab[3] = NULL;
	tab = ft_strsplit("test my function", ' ');
	test[3] = tabcmp(tab, ctrl_tab);
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = strdup("test");
	ctrl_tab[1] = strdup("my");
	ctrl_tab[2] = strdup("function");
	ctrl_tab[3] = NULL;
	tab = ft_strsplit(" test my  function ", ' ');
	test[4] = tabcmp(tab, ctrl_tab);
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = strdup("*test");
	ctrl_tab[1] = strdup("my");
	ctrl_tab[2] = strdup("function   ");
	ctrl_tab[3] = NULL;
	tab = ft_strsplit("*test\377my\377function   ", '\377');
	test[5] = tabcmp(tab, ctrl_tab);
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = NULL;
	tab = ft_strsplit("          ", ' ');
	test[6] = tabcmp(tab, ctrl_tab);
	if (test[6] == -24)
		test[6] = 0;
	if (test[6] == -12 && !(*(tab[0])) && !(tab[1]))
		test[6] = 0;
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = NULL;
	tab = ft_strsplit("", ' ');
	test[7] = tabcmp(tab, ctrl_tab);
	if (test[7] == -24)
		test[7] = 0;
	if (test[7] == -12 && !(*(tab[0])) && !(tab[1]))
		test[7] = 0;
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = strdup("test");
	ctrl_tab[1] = NULL;
	tab = ft_strsplit("test", ' ');
	test[8] = tabcmp(tab, ctrl_tab);
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	ctrl_tab[0] = strdup("b");
	ctrl_tab[1] = strdup("b");
	ctrl_tab[2] = strdup("b");
	ctrl_tab[3] = strdup("b");
	ctrl_tab[4] = NULL;
	tab = ft_strsplit("babababa", 'a');
	test[9] = tabcmp(tab, ctrl_tab);
	free_tab(tab);
	free_ctrl_tab(ctrl_tab);
	free(ctrl_tab);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 11, NULL);
#else
	print_test_results(test, ctrl, 10, NULL);
#endif
}

static void	test_strstr(void)
{
	int		test[6], ctrl[6];
	char	str[]="test\200string test\200string";

	print_test_name("strstr");
	init(ctrl, 6, 0);
	init(test, 6, 1);
	if (strstr(str, "test") == ft_strstr(str, "test"))
		test[0] = 0;
	if (strstr(str, "string") == ft_strstr(str, "string"))
		test[1] = 0;
	if (strstr(str, "\200") == ft_strstr(str, "\200"))
		test[2] = 0;
	if (strstr(str, "@") == ft_strstr(str, "@"))
		test[3] = 0;
	if (strstr(str, str) == ft_strstr(str, str))
		test[4] = 0;
	if (strstr(str, "ingr") == ft_strstr(str, "ingr"))
		test[5] = 0;
	print_test_results(test, ctrl, 6, NULL);
}

static void	test_strsub(void)
{
	int		test[9], ctrl[9], warning[]={5, 6, 7, 8, -1};
	char	src[]="test", *dst;

	print_test_name("strsub");
	init(ctrl, 9, 0);
	init(test, 9, 1);
#ifdef SEGFAULT_ME
	ft_strsub(NULL, 0, 5);
	ft_strsub(NULL, 5, 5);
	free(ft_strsub("test", 0, 0));
	free(ft_strsub("test", 0, 10000000));
#endif
	dst = ft_strsub(src, 0, strlen(src));
	if (dst < src || dst > src + strlen(src))
		test[0] = 0;
	test[1] = cmp(src, dst);
	free(dst);
	test[2] = cmp("t s", ft_strsub("test string", 3, 3));
	test[3] = cmp("g", ft_strsub("test string", 10, 1));
	test[4] = cmp("g", ft_strsub("g", 0, 1));
	/* You're encourage to test this one more thouroughly but  */
	/* since behaviour is undefined when start and size do not */
	/* point to a valid string, I can't force one on you.      */
	/* For example, I could suggest something in the likes of: */
	/* return (NULL) if (size == 0 OR src[start] == '\0')      */
	/* The following test are for this sort of implementation  */
	/* Just ignore them if you would have your ft_strsub       */
	/* behave differently (for example return "\0")            */
	dst = ft_strsub("test string", 10, 2);
	test[5] = cmp("g", dst);
	free(dst);
	dst = ft_strsub("g", 0, 2);
	test[6] = cmp("g", dst);
	free(dst);
	dst = ft_strsub("", 0, 1);
	if (!dst)
		test[7] = 0;
	free(dst);
	dst = ft_strsub("g", 0, 0);
	if (!dst)
		test[8] = 0;
	free(dst);
	print_test_results(test, ctrl, 9, warning);
}

static void	test_strtrim(void)
{
	int		test[17], ctrl[17], warning[]={14, 15, -1};
	char	*dst, src[]="test";

	print_test_name("strtrim");
	init(ctrl, 17, 0);
#ifdef SEGFAULT_ME
	test[16] = 1;
	dst = ft_strtrim(NULL);
	if (!dst)
		test[16] = 0;
#endif
	dst = ft_strtrim("test");
	test[0] = cmp("test", dst);
	test[1] = 1;
	if (dst != src)
		test[1] = 0;
	free(dst);
	dst = ft_strtrim(" test");
	test[2] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("test ");
	test[3] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("\ntest");
	test[4] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("test\n");
	test[5] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("\ttest");
	test[6] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("test\t");
	test[7] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("    test        ");
	test[8] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("    test\n");
	test[9] = cmp("test", dst);
	free(dst);
	dst = ft_strtrim("   \n  \t \nt\n");
	test[10] = cmp("t", dst);
	free(dst);
	dst = ft_strtrim("             t\n  \t \n  t\n ");
	test[11] = cmp("t\n  \t \n  t", dst);
	free(dst);
	dst = ft_strtrim("t t");
	test[12] = cmp("t t", dst);
	free(dst);
	dst = ft_strtrim("               \nt\n");
	test[13] = cmp("t", dst);
	free(dst);
	dst = ft_strtrim("");
	test[14] = cmp("", dst);
	free(dst);
	dst = ft_strtrim("          \n        \n \t");
	test[15] = cmp("", dst);
	free(dst);
#ifdef SEGFAULT_ME
	print_test_results(test, ctrl, 17, warning);
#else
	print_test_results(test, ctrl, 16, warning);
#endif
}

static void	test_tolower(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("tolower");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = tolower(i);
		test[i] = ft_tolower(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

static void	test_toupper(void)
{
	int		i, test[1024], ctrl[1024];

	print_test_name("toupper");
	i = 0;
	while (i < 1024)
	{
		ctrl[i] = toupper(i);
		test[i] = ft_toupper(i);
		++i;
	}
	print_test_results_summary(test, ctrl, 1024);
}

int			main(void)
{
#ifdef SEGFAULT_ME
	printf(ULINE"segfault tests:"UNULINE" "MAGENTA"enabled"UNCOLOR" (comment out #define SEGFAULT_ME to disable)\n");
#else
	printf(ULINE"segfault tests:"UNULINE" "CYAN"disabled"UNCOLOR" (if you're still segfaulting, it's on you)\n");
#endif
	test_atoi();
	test_bzero();
	test_isalnum();
	test_isalpha();
	test_isascii();
	test_isdigit();
	test_isprint();
//	test_isspace(); /* not required */
//	test_itoa();
//	test_lstadd();
//	test_lstdel();
///	test_lstdelone();
//	test_lstiter();
//	test_lstmap();
	test_lstnew();
	test_memalloc();
	test_memccpy();
	test_memchr();
	test_memcmp();
	test_memcpy();
	test_memdel();
	test_memmove();
	test_memset();
	test_strcat();
	test_strchr();
	test_strclr();
	test_strcmp();
	test_strcpy();
	test_strdel();
	test_strdup();
	test_strequ();
	test_striter();
	test_striteri();
	test_strjoin();
	test_strlcat();
//	test_strlcpy(); /* not required */
	test_strlen();
	test_strmap();
	test_strmapi();
	test_strncat();
	test_strncmp();
	test_strncpy();
	test_strnequ();
	test_strnew();
	test_strnstr();
	test_strrchr();
	test_strsplit();
	test_strstr();
	test_strsub();
	test_strtrim();
	test_tolower();
	test_toupper();
	printf("If all you see is green, bear in mind this doesn't mean your functions are correct. It means I was not able to figure out what was wrong.\n");
	printf("You are therefore strongly advised to try out the other tests available out there.\n");
	printf(MAGENTA"Love and kisses, Zaphod."UNCOLOR"\n");
	printf(YELLOW"disagreed"UNCOLOR" results mean the function did not behave like expected but it is not necessarily a fail (I leave that judgement up to you). See comments in the code for more details.\n");
	printf(YELLOW"disagreed"UNCOLOR" signifie que la fonction ne s'est pas comportée comme prévu, mais que cela n'est pas forcément un fail (c'est à vous de décider). Référez vous aux commentaires dans le code pour plus de détails.\n");
	printf(RED"WARNING:"UNCOLOR" If you're using this test for correction/gradation purposes, __please__ check out the code for the tests that failed before sacking another student, and try to understand why they failed. It could be my mistake, or her/his functions could behave unlike mine, yet still be in accordance with the instructions (this is mostly true for the additional functions). This program is not here to correct in your stead.\n");
	printf(RED"ATTENTION:"UNCOLOR" Si vous utilisez ce test pour corriger un autre élève, __s'il_vous_plait__ vérifiez le code des tests qui ont échoué avant de la/le saquer, et essayerz de comprendre d'où vient le problème. J'ai pu faire une erreur, ou ses fonctions pourraient avoir un comportement différent des miennes, tout en restant en accord avec les instructions (ceci est valable principalement pour les fonctions supplémentaires). Ce programme n'est pas là pour faire la correction à votre place.\n");
	return (0);
}
