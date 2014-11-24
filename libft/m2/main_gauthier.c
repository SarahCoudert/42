/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 15:38:51 by ggilaber          #+#    #+#             */
/*   Updated: 2014/11/18 11:42:18 by cducaffy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft.h"
#include <ctype.h>
#include <string.h>
#include <fcntl.h>
#define couleur(param) printf("\033[%sm",param)
/*
void tisspace(int n)
{
	if (ft_isspace(n) == isspace(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_isspace : %d    isspace : %d\n",n, ft_isspace(n), isspace(n));
	couleur("37");
}

void testisspace(void)
{
	printf("isspace :\n");
	tisspace(' ');
	tisspace('\t');
	tisspace('\f');
	tisspace('\n');
	tisspace('\r');
	tisspace('\v');
	tisspace('t');
	tisspace('d');
}
*/
void tatoi(char *str)
{
	if (ft_atoi(str) == atoi(str))
		couleur("32");
	else
		couleur("31");
	printf("%s    ft_atoi : %d    atoi : %d\n",str, ft_atoi(str), atoi(str));
	couleur("37");
}

void testatoi()
{
	printf("atoi\n");
	tatoi("102");
	tatoi("serg");
	tatoi("12as");
	tatoi("-12as");
	tatoi("-    12as");
	tatoi("+12as");
	tatoi("++12as");
	tatoi("+    12as");
	tatoi("-45");
//	tatoi("9999199999999999991119999999999998");
//	tatoi("-9999199999999999991119999999999998");
	tatoi("0001\n2");
	tatoi("drgdfggc402");
	tatoi("         402");
	tatoi("\t402");
	tatoi("\t \f \n \r \v402");
	tatoi("2147483647");
	tatoi("2147483648");
	tatoi("-2147483648");
	tatoi("-2147483649");
}

void testisalpha(void)
{
	printf("isalpha :\n");
	if (isalpha('/') == isalpha('/') && ft_isalpha('c') == isalpha('c') && ft_isalpha('D') == isalpha('D') && ft_isalpha(65) == isalpha(65) && ft_isalpha(0) == isalpha(0))
		couleur("32");
	else
		couleur("31");
	printf("ft_isalpha('c') : %d    isalpha('c') : %d\n", ft_isalpha('c'), isalpha('c'));
	printf("ft_isalpha('D') : %d    isalpha('D') : %d\n", ft_isalpha('D'), isalpha('D'));
	printf("ft_isalpha(65) : %d    isalpha(65) : %d\n", ft_isalpha(65), isalpha(65));
	printf("ft_isalpha(0) : %d    isalpha(0) : %d\n", ft_isalpha(0), isalpha(0));
	printf("ft_isalpha('/') : %d    isalpha('/') : %d\n", ft_isalpha('/'), isalpha('/'));
	couleur("37");
}

void tisdigit(int n)
{
	if (ft_isdigit(n) == isdigit(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_isdigit : %d    isdigit : %d\n",n, ft_isdigit(n), isdigit(n));
	couleur("37");
}

void testisdigit(void)
{
	printf("isdigit :\n");
	tisdigit('4');
	tisdigit(4);
	tisdigit(52);
}

void tisalnum(int n)
{
	if (ft_isalnum(n) == isalnum(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_isalnum : %d    isalnum : %d\n",n, ft_isalnum(n), isalnum(n));
	couleur("37");
}

void testisalnum(void)
{
	printf("isalnum :\n");
	tisalnum('c');
	tisalnum('D');
	tisalnum(65);
	tisalnum(0);
	tisalnum('/');
	tisalnum('4');
	tisalnum(4);
	tisalnum(52);
}

void tisascii(int n)
{
	if (ft_isascii(n) == isascii(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_isascii : %d    isascii : %d\n",n, ft_isascii(n), isascii(n));
	couleur("37");
}

void testisascii(void)
{
	printf("isascii :\n");
	tisascii(0);
	tisascii(127);
	tisascii(65);
	tisascii(327);
}

void tisprint(int n)
{
	if (ft_isprint(n) == isprint(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_isprint : %d    isprint : %d\n",n, ft_isprint(n), isprint(n));
	couleur("37");
}

void testisprint(void)
{
	printf("isprint :\n");
	tisprint(31);
	tisprint(' ');
	tisprint(126);
	tisprint(127);
}

void ttoupper(int n)
{
	if (ft_toupper(n) == toupper(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_toupper : %d    toupper : %d\n",n, ft_toupper(n), toupper(n));
	couleur("37");
}

void testtoupper()
{
	printf("toupper\n");
	ttoupper('a');
	ttoupper('d');
	ttoupper('z');
	ttoupper('A');
	ttoupper('}');
}

void ttolower(int n)
{
	if (ft_tolower(n) == tolower(n))
		couleur("32");
	else
		couleur("31");
	printf("%d    ft_tolower : %d    tolower : %d\n",n, ft_tolower(n), tolower(n));
	couleur("37");
}

void testtolower()
{
	printf("tolower\n");
	ttolower('A');
	ttolower('D');
	ttolower('Z');
	ttolower('a');
	ttolower('}');
}

void tstrlen(char *str)
{
	if (ft_strlen(str) == strlen(str))
		couleur("32");
	else
		couleur("31");
	printf("%s    ft_strlen : %zu    strlen : %zu\n",str, ft_strlen(str), strlen(str));
	couleur("37");
}

void teststrlen()
{
	printf("strlen\n");
	tstrlen("\0");
	tstrlen("");
	tstrlen("0123456789");
	tstrlen("012\0d565544");
	tstrlen("354");
}

void testput()
{
	printf("put\n");
	ft_putstr("putnbr : '0' '-123' '123' '-2147483648'\n");
	ft_putnbr(0);
	ft_putchar('\n');
	ft_putnbr(-123);
	ft_putchar('\n');
	ft_putnbr(123);
	ft_putchar('\n');
	ft_putnbr(-2147483648);
	ft_putchar('\n');
	ft_putstr("putchar : 'c' '}' '\\n' '126'\n");
	ft_putchar('c');
	ft_putchar('}');
	ft_putchar('\n');
	ft_putchar(126);
	ft_putstr("\nputstr : \"\"  \"123\\0 123\" \"a\" \"\\n\"\n");
	ft_putstr("");
	ft_putstr("123\0 123");
	ft_putstr("a");
	ft_putstr("\n");
	ft_putstr("\nputendl : \"\"  \"123\\0 123\" \"a\" \"\\n\"\n");
	ft_putendl("");
	ft_putendl("123\0 123");
	ft_putendl("a");
	ft_putendl("\n");
	char *test = (char*)malloc(sizeof(char) * 12);
	int i=-1;
	while (++i < 12)
		test[i] = '\0';
/*	printf("putmemchar\n");
	ft_putmemchar((const void*)test,12);
	printf("\n");
	ft_putmemchar((const void*)"i\0\0\0\0\0\0\0\0\0dtyt\0\0\0",12);
	printf("\n");
	ft_putmemchar((const void*)"\0\0\0\0\0\0\0\0\0\0",8);
	printf("\n");
	ft_putmemchar((const void*)"aAzZaAzZasefasesaefsaf",12);
	printf("\n");
	ft_putmemchar((const void*)"aAzZaAzZasefasesaefsaf",0);
	printf("\n");
*/}

void testput_fd()
{
	int fd;

	fd = open("./testputfd", O_CREAT|O_WRONLY, 0777);
	printf("put_fd ecrit dqns testputfd\n");
	ft_putstr_fd("putnbr : '0' '-123' '123' '-2147483648'", fd);
	ft_putchar_fd('\n',fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n',fd);
	ft_putnbr_fd(-123, fd);
	ft_putchar_fd('\n',fd);
	ft_putnbr_fd(123, fd);
	ft_putchar_fd('\n',fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd('\n',fd);
	ft_putstr_fd("putchar : 'c' '}' '\\n' '126'\n",fd);
	ft_putchar_fd('c',fd);
	ft_putchar_fd('}',fd);
	ft_putchar_fd('\n',fd);
	ft_putchar_fd(126,fd);
	ft_putstr_fd("\nputstr : \"\"  \"123\\0 123\" \"a\" \"\\n\"\n",fd);
	ft_putstr_fd("",fd);
	ft_putstr_fd("123\0 123",fd);
	ft_putstr_fd("a",fd);
	ft_putstr_fd("\n",fd);
	ft_putstr_fd("\nputendl : \"\"  \"123\\0 123\" \"a\" \"\\n\"\n",fd);
	ft_putendl_fd("",fd);
	ft_putendl_fd("123\0 123",fd);
	ft_putendl_fd("a",fd);
	ft_putendl_fd("\n",fd);
	close(fd);
}

void tstrcmp(const char *s1, const char *s2)
{
	if (ft_strcmp(s1, s2) == strcmp(s1, s2))
		couleur("32");
	else
		couleur("31");
	printf("%s  %s  ft_strcmp : %d    strcmp : %d\n",s1, s2, ft_strcmp(s1,s2), strcmp(s1,s2));
	couleur("37");
	if (ft_strcmp(s2, s1) == strcmp(s2, s1))
		couleur("32");
	else
		couleur("31");
	printf("%s  %s  ft_strcmp : %d    strcmp : %d\n",s2, s1, ft_strcmp(s2,s1), strcmp(s2,s1));
	couleur("37");
}

void teststrcmp()
{
	printf("strcmp\n");
	tstrcmp("", " ");
	tstrcmp("", "");
	tstrcmp("123", "1234");
	tstrcmp("a123","aa");
	tstrcmp("123\0 123","123\0 123");
	tstrcmp("aaaaaa", "aaaaaaaaaaaaa");
	tstrcmp("axdrgxdhxfthftghfxghxfgjhxfgjg64j51v3j51v35v35n35j1.5jcg16gj","axdrgxdhxfthftghfxghxfgjhxfgjg64j51v3j51v35v35n35j1.5jcg16gjf");
}


void tstrncmp(const char *s1, const char *s2, int n)
{
	if (ft_strncmp(s1, s2,n) == strncmp(s1, s2, n))
		couleur("32");
	else
		couleur("31");
	printf("%s  %s  %d   ft_strncmp : %d    strncmp : %d\n",s1, s2, n, ft_strncmp(s1,s2, n), strncmp(s1,s2, n));
	couleur("37");
}

void teststrncmp()
{
	printf("strncmp\n");
	tstrncmp("", " ",1);
	tstrncmp("", "",1);
	tstrncmp("123", "1234",0);
	tstrncmp("123", "1234",2);
	tstrncmp("123", "1234",3);
	tstrncmp("123", "1234",4);
	tstrncmp("a123","aa",1);
	tstrncmp("a123","aa",2);
	tstrncmp("a123","aa",3);
	tstrncmp("aaaaaa", "aaaaaaaaaaaaa", 6);
	tstrncmp("aaaaaa", "aaaaaaaaaaaaa", 7);
//	tstrncmp("aaa\0\taaaaaaaaaaa", "aaa\0 bbbbbbbbbbbbb", 12);
}

void tstrdup(const char *src)
{
	if (!ft_strcmp(ft_strdup(src),strdup(src)))
		couleur("32");
	else
		couleur("31");
	printf("%s  ft_strdup : %s    strdup : %s\n",src, ft_strdup(src), strdup(src));
	couleur("37");
}

void teststrdup()
{
	printf("strdup\n");
	tstrdup("");
	tstrdup("    \0     ");
	tstrdup("1234560\n\v\tzdfsdf");
	tstrdup("\0");
	tstrdup("sefsfasefwefsaegsdgdfsgasagdrty.drty351316gggggweeGGSGSDFDFGwegwergasrgargdhsthstsgjsthstehseth");
	tstrdup("\n");
	tstrdup("awef");
	tstrdup("areg");
	tstrdup("\0\0\0\0\0\0\0\0\0\0\0\0\0");
	tstrdup("xdrgxdhxfthftghfxghxfgjhxfgjg64j51v3j51v35v35n35j1.5jcg16gj");
}

void tstrcpy(const char *src)
{
	char dst[100];
	char *dst2 = strdup(dst);
	char *dst3 = strdup(dst);
	char *dst4 = strdup(dst);

	if (!ft_strcmp(ft_strcpy(dst, src),strcpy(dst2, src)))
		couleur("32");
	else
		couleur("31");
	printf("%s  ft_strcpy : %s    strcpy : %s\n",src, ft_strcpy(dst3,src), strcpy(dst4,src));
	couleur("37");
}

void teststrcpy()
{
	printf("strcpy\n");
	tstrcpy("1234");
	tstrcpy("");
	tstrcpy("1\0 234");
	tstrcpy("xdrgxdhxfthftghfxghxfgjhxfgjg64j51v3j51v35v35n35j1.5jcg16gj");
	tstrcpy("\n\f\v\tdzg    \nzsdf\v");
}

void tstrncpy(const char *src, int n)
{
	int len = ft_strlen(src);
	char *dst;
	dst = (char*)malloc(sizeof(char)*27);
	dst[26] ='\0';
	int i = -1;
	while (++i < 26)
		dst[i] = 'a' + i;
	char *dst2 = strdup(dst);
	char *dst3 = strdup(dst);
	char *dst4 = strdup(dst);

	if (!ft_strcmp(ft_strncpy(dst, src, n),strncpy(dst2, src, n)))
		couleur("32");
	else
		couleur("31");
	printf("%s  ft_strncpy : %s    strncpy : %s",src, ft_strncpy(dst3,src, n), strncpy(dst4,src, n));
	couleur("37");
	if (n > len)
		printf("   remainder ft : %s    good : %s", dst3 + n + 1, dst4 + n + 1);
	printf("\n");
}

void teststrncpy()
{
	printf("strncpy\n");
	tstrncpy("123456789", 0);
	tstrncpy("123456789", 7);
	tstrncpy("123456789", 8);
	tstrncpy("123456789", 9);
	tstrncpy("123456789", 10);
	tstrncpy("123456789", 11);
}

void tstrcat(const char *src)
{
//	int n = ft_strlen(src) + 13;
	char *dst = (char*)malloc(sizeof(char)*27);
	dst[13] ='\0';
	int i = -1;
	while (++i < 13)
		dst[i] = 'a' + i;

	char *dst2 = strdup(dst);
	if (!(ft_strcmp(ft_strcat(dst,src),strcat(dst2,src))))
	{
		couleur("32");
		printf("D'AC\n");
	}
	else
	{
		couleur("31");
		printf("PAS D'AC\n");
	}
		couleur("37");
	free(dst);
	free(dst2);
//	printf("   remainder ft : %s    good : %s\n", dst3 + n, dst4 + n);
}

void teststrcat()
{
	printf("strcat\n");
	tstrcat("");
	tstrcat("123");
	tstrcat("123456\0 123");
}

void tstrstr(const char *s1, const char *s2)
{
	if (!ft_strcmp(ft_strstr(s1, s2),strstr(s1, s2)))
		couleur("32");
	else
		couleur("31");
	printf("s1 : %s, s2 : %s,   ft_strstr : %s    strstr : %s\n",s1, s2, ft_strstr(s1, s2), strstr(s1, s2));
	couleur("37");
}

void teststrstr()
{
	printf("strstr (pour les lignes blanches, ft_strstr doit etre (null))\n");
	tstrstr("","");
	tstrstr("wear","");
	tstrstr("","");
//	tstrstr("", "wear");
//	tstrstr("","a");
	printf("s1 : %s, s2 : %s,   ft_strstr : %s\n","", "wear", ft_strstr("","wear"));
	printf("s1 : %s, s2 : %s,   ft_strstr : %s\n","", "a", ft_strstr("","a"));
	tstrstr("a","");
	tstrstr("abcabcabc","abc");
//	tstrstr("aabbcc","abc");
	printf("s1 : %s, s2 : %s,   ft_strstr : %s\n","aabbcc", "abc", ft_strstr("aabbcc","abc"));
	tstrstr("abc","abc");
	tstrstr("dfgabc","abc");
	tstrstr("c","c");
//	tstrstr("c","cccccccccc");
	printf("s1 : %s, s2 : %s,   ft_strstr : %s\n","c", "ccccccccc", ft_strstr("c","ccccccc"));
	tstrstr("ccccccccccccccc","c");
}

void	ftest(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c += 'A' - 'a';
}

void tstriter(char *s1, char *s2)
{
	char *s3;

	s3 = ft_strdup(s1);
	ft_striter(s1, &ftest);
	if (!ft_strcmp(s1,s2))
		couleur("32");
	else
		couleur("31");
	printf("s1 : %s,   ft_striter : %s    attendu : %s\n",s3, s1, s2);
	couleur("37");
}

void teststriter()
{
	printf("striter\n");
	char *s =(char*)malloc(sizeof(char) * 9);
	s[8] = '\0';
	int i = -1;
	while (++i < 8)
		s[i] = 'A';
	tstriter(s ,"AAAAAAAA");
	s[1] = 'a';
	tstriter(s ,"AAAAAAAA");
	i = -1;
	while (++i < 8)
		s[i] = 'w' + i;
	tstriter(s ,"WXYZ{|}~");
	s[1] = '\0';
	tstriter(s ,"W");
	s[0] = 'w';
	tstriter(s ,"W");
}

void	ftesti(unsigned int i, char *c)
{
	if ((c[0] >= 'a' && c[0] <= 'z') && i % 2)
		c[0] += 'A' - 'a';
}

void tstriteri(char *s1, char *s2)
{
	char *s3;

	s3 = ft_strdup(s1);
	ft_striteri(s1, &ftesti);
	if (!ft_strcmp(s1,s2))
		couleur("32");
	else
		couleur("31");
	printf("s1 : %s,   ft_striteri : %s    attendu : %s\n",s3, s1, s2);
	couleur("37");
}

void teststriteri()
{
	printf("striter\n");
	char *s =(char*)malloc(sizeof(char) * 8);
	s[9] = '\0';
	int i = -1;
	while (++i < 8)
		s[i] = 'a';
	tstriteri(s ,"aAaAaAaA");
	s[1] = 'a';
	tstriteri(s ,"aAaAaAaA");
	i = -1;
	while (++i < 8)
		s[i] = 'w' + i;
	tstriteri(s ,"wXyZ{|}~");
	s[1] = '\0';
	tstriteri(s ,"w");
	s[0] = 'w';
	tstriteri(s ,"w");
}

void tstrequ(const char *s1, const char *s2)
{
	if ((ft_strcmp(s1, s2) && (!ft_strequ(s1, s2))) || ((!ft_strcmp(s1, s2)) && ft_strequ(s1, s2)))
		couleur("32");
	else
		couleur("31");
	printf("%s  %s  ft_strequ : %d    strcmp : %d\n",s1, s2, ft_strequ(s1,s2), strcmp(s1,s2));
	couleur("37");
}

void teststrequ()
{
	printf("strequ\n");
	tstrequ("", " ");
	tstrequ("", "");
	tstrequ("123", "1234");
	tstrequ("a123","aa");
	tstrequ("123\0 123","123\0 123");
	tstrequ("aaaaaa", "aaaaaaaaaaaaa");
	tstrequ("axdrgxdhxfthftghfxghxfgjhxfgjg64j51v3j51v35v35n35j1.5jcg16gj","axdrgxdhxfthftghfxghxfgjhxfgjg64j51v3j51v35v35n35j1.5jcg16gjf");
}


void tstrnequ(const char *s1, const char *s2, int n)
{
	if ((ft_strncmp(s1, s2,n) && (!ft_strnequ(s1, s2,n))) || ((!ft_strncmp(s1, s2,n)) && ft_strnequ(s1, s2,n)))
		couleur("32");
	else
		couleur("31");
	printf("%s  %s  %d   ft_strncmp : %d    strncmp : %d\n",s1, s2, n, ft_strnequ(s1,s2, n), strncmp(s1,s2, n));
	couleur("37");
}

void teststrnequ()
{
	printf("strnequ\n");
	tstrnequ("", " ",1);
	tstrnequ("", "",1);
	tstrnequ("123", "1234",0);
	tstrnequ("123", "1234",2);
	tstrnequ("123", "1234",3);
	tstrnequ("123", "1234",4);
	tstrnequ("a123","aa",1);
	tstrnequ("a123","aa",2);
	tstrnequ("a123","aa",3);
	tstrnequ("aaaaaa", "aaaaaaaaaaaaa", 6);
	tstrnequ("aaaaaa", "aaaaaaaaaaaaa", 7);
	tstrnequ("aaa\0\taaaaaaaaaaa", "aaa\0 bbbbbbbbbbbbb", 12);
}

void printmem(char *str, char *att)
{
	if (ft_strequ(str,att))
		couleur("32");
	else
		couleur("31");
	printf("ft_memset : %s    attendu : %s\n", str, att);
	couleur("37");
}

void testmemset()
{
	printf("memset\n");
	char *test;
	size_t i;
	test = (char*)malloc(sizeof(char)*10);
	test[9] = '\0';
	i = -1;
	while (++i < 9)
		test[i] = 'z';
	ft_memset((void *)test, 100, 5);
	printmem((char*)test, "dddddzzzz");
	ft_memset((void *)test, 97, 3);
	printmem((char*)test, "aaaddzzzz");
	test[6] = '\0';
	ft_memset((void *)test, 98, 0);
	printmem((char*)test,"aaaddz");
	ft_memset((void *)test, 98, 8);
	printmem((char*)test, "bbbbbbbbz");
}

void teststrnew()
{
	printf("strnew\n");
	char *str = ft_strnew(10);
	int i = -1;
	while (++i < 10)
		str[i] += '0' + i;
	if (ft_strequ(str,"0123456789"))
		couleur("32");
	else
		couleur("31");
	printf("str : %s    attendu : 0123456789\n", str);
	couleur("37");
}

char ftestc(char c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	return (c);
}

void tstrmap(const char *s1, const char *s2)
{
	char *s3;
	char *s4;

	s3 = ft_strdup(s1);
	s4 = ft_strmap(s1, &ftestc);
	if (ft_strequ(s1,s3) && ft_strequ(s2, s4))
		couleur("32");
	else
		couleur("31");
	printf("s1 : %s,   ft_strmap : %s    attendu : %s\n",s1, s4, s2);
	couleur("37");
}

void teststrmap()
{
	printf("strmap\n");
	tstrmap("aAaAaAaA", "AAAAAAAA");
	tstrmap("A", "A");
	tstrmap("a","A");
	tstrmap("azazazaz","AZAZAZAZ");
	tstrmap("AZAZAZAZ","AZAZAZAZ");
}

char ftestci(unsigned int n, char c)
{
	if (c >= 'a' && c <= 'z')
		c += 'A' - 'a';
	n = n + 4;
	return (c);
}

void tstrmapi(const char *s1, const char *s2)
{
	char *s3;
	char *s4;

	s3 = ft_strdup(s1);
	s4 = ft_strmapi(s1, &ftestci);
	if (ft_strequ(s1,s3) && ft_strequ(s2, s4))
		couleur("32");
	else
		couleur("31");
	printf("s1 : %s,   ft_strmapi : %s    attendu : %s\n",s1, s4, s2);
	couleur("37");
}

void teststrmapi()
{
	printf("strmapi\n");
	tstrmap("aAaAaAaA", "AAAAAAAA");
	tstrmap("A", "A");
	tstrmap("a","A");
	tstrmap("azazazaz","AZAZAZAZ");
	tstrmap("AZAZAZAZ","AZAZAZAZ");
}

void tstrsub(char const *s, unsigned int start, size_t len, const char *satt)
{
	char *str;
	
	if (!(str = ft_strsub(s, start, len)))
	{
		if (ft_strequ(satt,"NULL"))
			couleur("32");
		else
			couleur("31");
		printf("NULL\n");
	}
	else
	{
		if (ft_strequ(satt,str))
			couleur("32");
		else
			couleur("31");
		printf("s1 : %s,   ft_strmapi : %s    attendu : %s\n",s, str, satt);
	}
		couleur("37");
}

void teststrsub()
{
	printf("strsub\n");
	tstrsub("012345\t6789", 0, 1, "0");
	tstrsub("012345\t6789", 0, 15, "012345\t6789");
	tstrsub("012345\t6789", 6, 2, "\t6");
	tstrsub("012345\t6789", 0, 0, "");
	tstrsub("012345\t6789", 8, 2, "78");
//	tstrsub("012345\t6789\0 123456", 13, 1, "NULL");
	tstrsub("012345\t6789", 1, 9, "12345\t678");
}

void tstrjoin(char const *s1, char const *s2, const char *satt)
{
	char *str;
	
	if (!(str = ft_strjoin(s1, s2)))
	{
		if (ft_strequ(satt,"NULL"))
			couleur("32");
		else
			couleur("31");
		printf("NULL\n");
	}
	else
	{
		if (ft_strequ(satt,str))
			couleur("32");
		else
			couleur("31");
		printf("s1 : %s,  s2 ; %s   ft_strjoin : %s    attendu : %s\n",s1, s2, str, satt);
	}
		couleur("37");
}

void teststrjoin()
{
	printf("strjoin\n");
	tstrjoin(NULL,"", "NULL");
	tstrjoin("","", "");
	tstrjoin("a","", "a");
	tstrjoin("","a", "a");
	tstrjoin("a","a", "aa");
	tstrjoin("abcdef","ghijkl", "abcdefghijkl");
	tstrjoin("","abcd", "abcd");
	tstrjoin("abcd", "", "abcd");
}

void tstrtrim(const char *s, const char *satt)
{
	char *str;
	
	ft_putchar('a');
	if (!ft_strtrim(s) && !(s))
	{
		ft_putchar('p');
		if (ft_strequ(satt,"NULL"))
			couleur("32");
		else
			couleur("31");
		printf("NULL\n");
	}
	else
	{
		str = ft_strtrim(s);
		if (ft_strequ(satt,str))
			couleur("32");
		else
			couleur("31");
		printf("s1 : |%s|   ft_strtrim :|%s|    attendu : |%s|\n",s, str, satt);
	}
		couleur("37");
}

void teststrtrim()
{
	printf("tstrtrim\n");
	tstrtrim(NULL, "NULL");
	tstrtrim("      srg   srgrs          ", "srg   srgrs");
	tstrtrim("sef sda", "sef sda");
	tstrtrim("    \t   \t \n   awerfaew \t sdrg  \t ", "awerfaew \t sdrg");
	tstrtrim(" sdf ", "sdf");
	tstrtrim("  saef  f", "saef  f");
	tstrtrim(" f f ", "f f");
	tstrtrim("      ", "");
	tstrtrim("  c  ", "c");
	tstrtrim("ssf", "ssf");
	tstrtrim("ewf ", "ewf");
}

void titoa(int n, char *s)
{
	if (ft_strequ(ft_itoa(n),s))
		couleur("32");
	else
		couleur("31");
	printf("n : %d,   ft_itoa : %s    attendu : %s\n",n, ft_itoa(n), s);
	couleur("37");

}

void testitoa()
{
	printf("itoa\n");
	titoa(0,"0");
	titoa(-1,"-1");
	titoa(1,"1");
	titoa(169,"169");
	titoa(-169,"-169");
	titoa(100,"100");
	titoa(-100,"-100");
	titoa(2147483647,"2147483647");
	titoa(-2147483648,"-2147483648");
}

void printbzero(char *str, char *att,int n)
{
	int i = -1;
	while (++i < 9)
	{
		if (str[i] == '_')
			str[i] = '-';
		else if (!str[i])
			str[i] = '_';
	}
	if (ft_strequ(str,att))
		couleur("32");
	else
		couleur("31");
	printf("str : 123456789   n : %d    ft_memset : %s    attendu : %s\n",n,str, att);
	couleur("37");
}

void testbzero()
{
	printf("bzero\n");
	char *test;
	char *test2;
	char *test3;
	char *test4;
	size_t i;
	test = (char*)malloc(sizeof(char)*10);
	test[9] = '\0';
	i = -1;
	while (++i < 9)
		test[i] = '1' + i;
	test2 = ft_strdup(test);
	test3 = ft_strdup(test);
	test4 = ft_strdup(test);
	ft_bzero((void *)test, 3);
	printbzero((char*)test, "___456789", 3);
	ft_bzero((void *)test2, 5);
	printbzero((char*)test2, "_____6789", 5);
	test[6] = '\0';
	ft_bzero((void *)test3, 8);
	printbzero((char*)test3, "________9", 8);
	ft_bzero((void *)test4, 0);
	printbzero((char*)test4, "123456789", 0);
}

/*void tmemcpy(char *dst, const char *src, int n)
{
	char *dst2 = strdup(dst);

	if (!ft_memcmp(ft_memcpy((void*)dst, (void*)src, n),memcpy((void*)dst2, (void*)src, n), n))
		couleur("32");
	else
		couleur("31");
	printf("BON    ");
	ft_putmemchar((void*)dst, n);
	ft_putmemchar((void*)dst2, n);
	couleur("37");
}

void testmemcpy()
{
	printf("memcpy\n");
	size_t i;
	char *test;
	test = (char*)malloc(sizeof(char)*20);
	i = -1;
	while (++i < 20)
		test[i] = 'a' + i;
	tmemcpy(test,"", 0);
	tmemcpy(test, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 1);
	tmemcpy(test, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 2);
	tmemcpy(test, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 30);
	tmemcpy(test, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 30);
	tmemcpy(test, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 20);
	tmemcpy(test, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 15);
	i = 10;
	while (--i > 3)
		tmemcpy(test, "\0\0fils0\0de\0pull\0\0\0\0\0\0", i);
	printf("\n");
}*/

void tmemcmp(const void *s1, const void *s2, size_t n)
{
	if (ft_memcmp(s1, s2, n) == memcmp(s1, s2, n))
		couleur("32");
	else
		couleur("31");
	printf("ft_memcmp : %d    memcmp : %d\n", ft_memcmp(s1,s2,n), memcmp(s1,s2,n));
	couleur("37");
	
}

void testmemcmp()
{
	printf("memcmp\n");
	tmemcmp((const void*)"012345678910", (const void*)"012345678910", 5);
	tmemcmp((const void*)"ssss\0aaaaa", (const void*)"ssss\0saaaaaa",4 );
	tmemcmp((const void*)"ssss\0aaaaa", (const void*)"ssss\0saaaaaa",5 );
	tmemcmp((const void*)"ssss\0aaaaa", (const void*)"ssss\0saaaaaa",6 );
	tmemcmp((const void*)"ssss\0aaaaa", (const void*)"ssss\0saaaaaa",7 );
	tmemcmp((const void*)"111", (const void*)"22222",0 );
	tmemcmp((const void*)"\0\0\0\0\0\0", (const void*)"\0\0\0\0\0", 1);
	tmemcmp((const void*)"\0\0\0\0\0\0", (const void*)"\0\0\0\0\0", 2);
	tmemcmp((const void*)"123456", (const void*)"123457", 5);
	tmemcmp((const void*)"123456", (const void*)"123457", 6);
	tmemcmp((const void*)"aaabbb", (const void*)"aaaabb",2 );
	tmemcmp((const void*)"aaabbb", (const void*)"aaaabb",3 );
	tmemcmp((const void*)"aaabbb", (const void*)"aaaabb",4 );
}

int main(void)
{
//	testisspace();
	testatoi();
	testisalpha();
	testisdigit();
	testisalnum();
	testisascii();
	testisprint();
	testtoupper();
	testtolower();
	teststrlen();
	testput();
	testput_fd();
	teststrcmp();
	teststrncmp();
	teststrdup();
	teststrcpy();
	teststrncpy();
	teststrcat();
	teststrstr();
	teststriter();
	teststriteri();
	teststrequ();
	teststrnequ();
	testmemset();
	teststrnew();
	teststrmap();
	teststrmapi();
	teststrsub();
	teststrjoin();
	teststrtrim();
	testitoa();
	testbzero();
	testmemcmp();
//	testmemcpy();
	return 0;
}
