/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfil <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:08:14 by vfil              #+#    #+#             */
/*   Updated: 2017/11/06 12:55:01 by vfil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#define KYEL   "\x1B[33m"
#define KGRN  "\x1B[32m"
#define KCYN   "\x1B[36m"
#define RESET "\x1B[0m"

void	ft_putchar_ptr(char *c)
{
	write(1, c, 1);
}

void	ft_putchar_i_ptr(unsigned int i, char *c)
{
	while (i--)
		write(1, c, 1);
	write(1, "\n", 1);
}

char	ft_toupper2(char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
char	ft_toupper2_i(unsigned int i, char c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	while (i--)
		printf("%c", c);
	return (c);
}

void		test_arriter(void *t)
{
	printf("ft_arriter: %s\n", (char*)t);
}

int	main(int argc, char **argv)
{
	char	*test;

	test = NULL;
	if (argc > 1)
		test = argv[1];
/*
	//ft_memset
	int		str_mset[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int		str_ft_mset[20] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	printf("memset: %i, res: %s\n", str_mset[0], memset(str_mset, '$', 5));
	printf("ft_memset: %i, res: %s\n\n", str_ft_mset[0], ft_memset(str_ft_mset, '$', 5));

	//ft_bzero
	char	str_bz[20] = "0123456789**********";
	char	str_ft_bz[20] = "0123456789**********";
	char	*ptr_mid;
	char	*ptr_ft_mid;
	char	*ptr_bz;
	char	*ptr_ft_bz;
	size_t	i_bz;

	i_bz = 10;
	ptr_mid = &str_bz[10];
	ptr_ft_mid = &str_ft_bz[10];
	ptr_bz = &str_bz[15];
	ptr_ft_bz = &str_ft_bz[15];

	printf("bzero: src: %s, mid: %s, quarter: %s, n = %zu\n", str_bz, ptr_mid, ptr_bz, i_bz);
	bzero(ptr_mid, i_bz);
	printf("///bzero res: src: %s, mid: %s, quarter: %s, n = %zu\n\n", str_bz, ptr_mid, ptr_bz, i_bz);
	printf("ft_bzero: src: %s, mid: %s, quarter: %s\n, n = %zu\n", str_ft_bz, ptr_ft_mid, ptr_ft_bz, i_bz);
	ft_bzero(ptr_ft_mid, i_bz);
	printf("///ft_bzero res: src: %s, mid: %s, quarter: %s, n = %zu\n\n", str_ft_bz, ptr_ft_mid, ptr_ft_bz, i_bz);

	//ft_memcpy
	const char	src_memcpy[30] = "Hello from memcpy!!!";
	char		dest_mcpy[30];
	char		dest_ft_mcpy[30];
	size_t		i_mcpy;

	i_mcpy = 5;
	printf("memcpy: before: src = %s, dst = %s\n", src_memcpy, dest_mcpy);
	printf("memcpy: after: src = %s, n = %zu, dst = %s\n\n", src_memcpy, i_mcpy, memcpy(dest_mcpy, src_memcpy, i_mcpy));
	printf("ft_memcpy: before: src = %s, dst = %s\n", src_memcpy, dest_ft_mcpy);
	printf("ft_memcpy: after: src = %s, n = %zu, dst = %s\n\n", src_memcpy, i_mcpy, ft_memcpy(dest_ft_mcpy, src_memcpy, i_mcpy));

	//ft_memccpy
	const char	src_memccpy[30] = "Hello from memcpy!!!";
	char		dest_mccpy[30];
	char		dest_ft_mccpy[30];
	size_t		i_mccpy;

	i_mccpy = 5;
	printf("memccpy: before: src = %s, dst = %s\n", src_memccpy, dest_mccpy);
	memccpy(dest_mccpy, src_memccpy, test[0], i_mccpy);
	printf("memccpy: after: src = %s, c = %c, n = %zu, dst = %s\nres = %s\n\n", src_memccpy, test[0], i_mccpy, dest_mccpy, memccpy(dest_mccpy, src_memccpy, test[0], i_mccpy));

	printf("ft_memccpy: before: src = %s, dst = %s\n", src_memccpy, dest_ft_mccpy);
	ft_memccpy(dest_ft_mccpy, src_memccpy, test[0], i_mccpy);
	printf("ft_memccpy: after: src = %s, c = %c, n = %zu, dst = %s\nres = %s\n\n", src_memccpy, test[0], i_mccpy, dest_ft_mccpy, ft_memccpy(dest_ft_mccpy, src_memccpy, test[0], i_mccpy));

	//ft_memmove
	char	src_memmv[30] = "Hello from memcpy!!!";
	char	src_memmv2[30] = "Hello from memcpy!!!";
	size_t		i_mmv;

	i_mmv = 12;
	printf("memmove: before: dst = %s\n", src_memmv);
	memmove(src_memmv + 10, src_memmv + 6, i_mmv);
	printf("memmove: after: src = %s, n = %zu, dst = %s\n\n", src_memmv + 6, i_mmv, src_memmv);
	printf("ft_memmove: before: dst = %s\n", src_memmv2);
	ft_memmove(src_memmv2 + 10, src_memmv2 + 6, i_mmv);
	printf("ft_memmove: after: src = %s, n = %zu, dst = %s\n\n", src_memmv2 + 6, i_mmv, src_memmv2);

	//ft_memchr
	char	test2[] = "abcde";
	char	c_mchr;

	c_mchr = 'a';
	if (argv[2])
		c_mchr = argv[2][0];
	printf("memchar: s = %s, c = %c, found = %s\n", test2, c_mchr, memchr(test2, c_mchr, sizeof(test)));
	printf("ft_memchar: s = %s, c = %c, found = %s\n\n", test2, c_mchr, ft_memchr(test2, c_mchr, sizeof(test)));

	//ft_memcmp
	char	*test3 = NULL;
	size_t	n_memcmp;

	n_memcmp = 5;
	if (argv[2])
		test3 = argv[2];
	printf("memcmp: s1 = %s, s2 = %s, n = %zu, res = %i\nn", test, test3, n_memcmp, memcmp(test, test3, n_memcmp));
	printf("ft_memcmp: s1 = %s, s2 = %s, n = %zu, res = %i\n\n", test, test3, n_memcmp, ft_memcmp(test, test3, n_memcmp));

	//ft_strlen
	printf("strlen: %s , length: %lu\n", test, strlen(test));
	printf("ft_strlen: %s , length: %zu\n\n", test, ft_strlen(test));

	//ft_strdup
	char	*dest_dup;
	char	*ft_dest_dup;
	
	dest_dup = strdup(test);
	ft_dest_dup = ft_strdup(test);
	printf("strdup: %s\n", dest_dup);
	printf("ft_strdup: %s\n\n", ft_dest_dup);

	//ft_strcpy
	char	dst_cpy[11];
	char	ft_dst_cpy[11];

	printf("strcpy: %s\n", strcpy(dst_cpy, test));
	printf("ft_strcpy: %s\n\n", ft_strcpy(ft_dst_cpy, test));

	//ft_strncpy
	char	dst_ncpy[6];
	char	ft_dst_ncpy[6];

	printf("strncpy: %s\n", strncpy(dst_ncpy, test, 6));
	printf("ft_strncpy: %s\n\n", ft_strncpy(ft_dst_ncpy, test, 6));

	//ft_strcat
	char	s1_cat[15] = "00";
	char	s1_ft_cat[15] = "00";

	printf("strcat: %s\n", strcat(s1_cat, test));
	printf("ft_strcat: %s\n\n", ft_strcat(s1_ft_cat, test));

	//ft_strncat
	char	s1_ncat[11] = "aaaaa";
	char	s1_ft_ncat[11] = "aaaaa";

	printf("strncat: %s\n", strncat(s1_ncat, test, 5));
	printf("ft_strncat: %s\n\n", ft_strncat(s1_ft_ncat, test, 5));

	//ft_strlcat
	char	dest_lcat[50] = {0};
	char	dest_ft_lcat[50] = {0};
	size_t	i_lcat;

	printf("strlcat: %lu,  %s\n", strlcat(dest_lcat, "Hello ", 4), dest_lcat);
	printf("ft_strlcat: %zu,  %s\n\n", ft_strlcat(dest_ft_lcat, "Hello ", 4), dest_ft_lcat);

	ft_memset(dest_lcat, 0, sizeof(dest_lcat));
	ft_memset(dest_ft_lcat, 0, sizeof(dest_lcat));
	
	printf("strlcat: %lu,  %s\n", strlcat(dest_lcat, "Hello ", 4), dest_lcat);
	printf("ft_strlcat: %zu,  %s\n\n", ft_strlcat(dest_ft_lcat, "Hello ", 4), dest_ft_lcat);

	printf("strlcat: %lu,  %s\n", strlcat(dest_lcat, "Hello ", 1), dest_lcat);
	printf("ft_strlcat: %zu,  %s\n\n", ft_strlcat(dest_ft_lcat, "Hello ", 1), dest_ft_lcat);
	i_lcat = 0;
	while (i_lcat < 6)
	{
		dest_lcat[4 + i_lcat] = 'z';
		dest_ft_lcat[4 + i_lcat] = 'z';
		++i_lcat;
	}
	printf("strlcat: %lu,  %s\n", strlcat(dest_lcat, "abc", 6), dest_lcat);
	printf("ft_strlcat: %zu,  %s\n\n", ft_strlcat(dest_ft_lcat, "abc", 6), dest_ft_lcat);

	//ft_strchr
	char	s_ft_chr[] = "unitfactory_cool";

	printf("strchr: %s, res: %s\n", s_ft_chr, strchr(s_ft_chr, 'c'));
	printf("ft_strchr: %s, res: %s\n\n", s_ft_chr, ft_strchr(s_ft_chr, 'c'));


	//ft_strrchr
	printf("strrchr: %s, res: %s\n", s_ft_chr, strrchr(s_ft_chr, 'c'));
	printf("ft_strrchr: %s, res: %s\n\n", s_ft_chr, ft_strrchr(s_ft_chr, 'c'));

	printf("strrchr: %s, res: %s\n", s_ft_chr, strrchr(s_ft_chr, 'u'));
	printf("ft_strrchr: %s, res: %s\n\n", s_ft_chr, ft_strrchr(s_ft_chr, 'u'));

	//ft_strstr
	char	*haystack = "unitfactory";
	char	*needle = "unip";
	char s1[] = "MZIRIBMZIRIBMZP";
	char s2[] = "MZIRIBMZP";

	printf("strstr: %s, res: %s\n", s1, strstr(s1, s2));
	printf("ft_strstr: %s, res: %s\n\n", s1, ft_strstr(s1, s2));

	//ft_strnstr
	size_t	i;

	i = 5;
	printf("strnstr n = %lu: %s, res: %s\n", i, haystack, strnstr(haystack, test, i));
	printf("ft_strnstr n = %zu: %s, res: %s\n\n", i, haystack, ft_strnstr(haystack, test, i));

	//ft_strcmp
	char	s1_cmp[] = "abcdefg";

	printf("strcmp s1: %s, s2: %s, res: %i\n", s1_cmp, test, strcmp(s1_cmp, test));
	printf("ft_strcmp s1: %s, s2: %s, res: %i\n\n", s1_cmp, test, ft_strcmp(s1_cmp, test));

	//ft_strncmp
	int	ncmp;

	ncmp = 3;
	printf("strncmp n = %i, s1: %s, s2: %s, res: %i\n", ncmp, s1_cmp, test, strncmp(s1_cmp, test, ncmp));
	printf("ft_strncmp n = %i, s1: %s, s2: %s, res: %i\n\n", ncmp, s1_cmp, test, ft_strncmp(s1_cmp, test, ncmp));

	printf("strncmp n = 0, s1: q, s2: a, res: %i\n",strncmp("q", "a", 0));
	printf("ft_strncmp n = 0, s1: q, s2: a, res: %i\n\n", ft_strncmp("q", "a", 0));

	printf("strncmp n = 2, s1: abc, s2: abd, res: %i\n", strncmp("abc", "abd", 2));
	printf("ft_strncmp n = 2, s1: abc, s2: abd, res: %i\n\n", ft_strncmp("abc", "abd", 2));

	//ft_atoi
	printf("ft_atoi\n\n");
	int i_ati;
	char *str_ati;
	char *array_ati[100] = {
	  "",
	  "-1",
	  "0",
	  "-0",
	  "+0",
	  "-2147483648",
	  "2147483647",
	  "-2147483649",
	  "2147483648",
	  "-2147483650",
	  "2147483649",
	  "-2147483648000",
	  "2147483647000",
	  "-2147483648123",
	  "2147483647123",
	  "-9223372036854775808",
	  "9223372036854775807",
	  "-9223372036854775809",
	  "9223372036854775809",
	  "-9223372036854775900",
	  "9223372036854775900",
	  "-9223372036854775808123",
	  "9223372036854775807132",
	  "999999999999999999999999999999999999",
	  "-999999999999999999999999999999999999",
	  "99999999999999999999999999999999999912345678901234567890123456789012345678901234567890123456789012345678901234567890",
	  "-99999999999999999999999999999999999912345678901234567890123456789012345678901234567890123456789012345678901234567890",
	};

	i_ati = 0;
	while(array_ati[i_ati] != NULL)
	{
	  str_ati = array_ati[i_ati];

	  puts("========================================");
	  printf(KGRN "STR: \"%s\"\n" RESET, str_ati);
	  puts("----------------------------------------");
	  printf(KCYN "atoi: %d\n" RESET, atoi(str_ati));
	  printf(KYEL "ft_atoi: %d\n" RESET, ft_atoi(str_ati));
	  i_ati++;
	}

	//ft_isalpha
	printf("isalpha: %c, res: %i\n", test[0], isalpha(test[0]));
	printf("ft_isalpha: %c, res: %i\n\n", test[0], ft_isalpha(test[0]));

	//ft_isdigit
	printf("isdigit: %c, res: %i\n", test[0], isdigit(test[0]));
	printf("ft_isdigit: %c, res: %i\n\n", test[0], ft_isdigit(test[0]));

	//ft_isalnum
	printf("isalnum: %c, res: %i\n", test[0], isalnum(test[0]));
	printf("ft_isalnum: %c, res: %i\n\n", test[0], ft_isalnum(test[0]));

	//ft_isascii
	int i_ascii;

	i_ascii = 0;
	while (i_ascii < 130)
	{
		printf("isascii: %i = %c, res: %i	", i_ascii, i_ascii, isascii(i_ascii));
		printf("ft_isascii: %i = %c, res: %i\n", i_ascii, i_ascii, ft_isascii(i_ascii));
	i_ascii++;
	}

	//ft_isprint
	int i_print;

	i_print = 31;
	while (i_print < 128)
	{
		printf("isprint: %i = %c, res: %i	", i_print, i_print, isprint(i_print));
		printf("ft_isprint: %i = %c, res: %i\n", i_print, i_print, ft_isprint(i_print));
	i_print++;
	}

	//ft_toupper
	printf("toupper: %c, res: %c\n", test[0], toupper(test[0]));
	printf("ft_toupper: %c, res: %c\n\n", test[0], ft_toupper(test[0]));

	//ft_tolower
	printf("tolower: %c, res: %c\n", test[0], tolower(test[0]));
	printf("ft_tolower: %c, res: %c\n\n", test[0], ft_tolower(test[0]));


	//ft_memalloc
	char	*memalloc = NULL;
	size_t i_malloc;

	i_malloc = 0;
	memalloc = (char*)ft_memalloc(10);
	while (i_malloc < 10)
	{
		memalloc[i_malloc] = argv[1][i_malloc];
		i_malloc++;
	}
	printf("ft_memalloc: %s\n\n", memalloc);	
	
	//ft_memdel
	ft_memdel((void*)&memalloc);
	printf("ft_memdel: %s\n\n", memalloc);

	//ft_strnew
	char	*strnew = NULL;
	size_t i_strnew;

	i_strnew = 0;
	strnew = ft_strnew(10);
	while (i_strnew < 10)
	{
		strnew[i_strnew] = argv[1][i_strnew];
		i_strnew++;
	}
	printf("ft_memalloc: %s\n\n", strnew);	

	//ft_memdel
	ft_strdel(&strnew);
	printf("ft_strdel: %s\n\n", strnew);

	//ft_strclr
	char	str_clr[] = "0123456789";
	printf("ft_strclr: before: str = %s, str + 5 = %s\n", str_clr, str_clr + 5);
	ft_strclr(str_clr);
	printf("ft_strclr: after: str = %s, str + 5 = %s\n\n", str_clr, str_clr + 5);
*/
	//ft_striter

	printf("\n\nft_striter: s = %s, NULL\n", test);
	ft_striter(test, NULL);

	printf("ft_striter: s = %s, &ft_putchar_ptr\n", test);
	ft_striter(test, &ft_putchar_ptr);
	//ft_striteri
	printf("\n\nft_striteri:\n");
	ft_striteri(test, &ft_putchar_i_ptr);
	printf("\n\n");
/*
	//ft_strmap
	printf("ft_strmap: %s, ft_toupper: %s\n\n", test, ft_strmap(test, &ft_toupper2));

	//ft_strmapi
	printf("ft_strmapi: %s\n", test);
	char *t = ft_strmapi(test, &ft_toupper2_i);
	printf("\nres: %s\n\n", t);

	//ft_strequ
	printf("ft_strequ: s1 = %s, s2 = %s, res: %i\n\n", argv[1], argv[2], ft_strequ(argv[1], argv[2]));

	//ft_strnequ
	printf("ft_strnequ: s1 = %s, s2 = %s, n = 5, res = %i\n\n", argv[1], argv[2], ft_strnequ(argv[1], argv[2], 5));

	//ft_strsub
	printf("ft_strsub: s = %s, start = 5, len = 7, new = %s\n\n", test, ft_strsub(test, 5, 7));

	//ft_strjoin
	printf("ft_strjoin: s1 =%s, s2 = %s, new = %s\n\n", argv[1], argv[2], ft_strjoin(argv[1], argv[2]));

	//ft_strtrim
	printf("ft_strtrim: s = %s, new = %s\n\n", argv[1], ft_strtrim(argv[1]));
	
	//ft_strsplit
	char	**new_split;
	int		i_split;
	char *s = "     hello  ololo";

	i_split = 0;
//	new_split = ft_strsplit(argv[1], argv[2][0]);
	new_split = ft_strsplit(s, ' ');
	while (*new_split)
	{
		printf("ft_strsplit = %s\n", *new_split);
		new_split++;
		i_split++;
	}
	printf("\n");

	//ft_arriter
	ft_arriter(new_split - i_split, &test_arriter);

	//ft_itoa
	int i_itoa = -2147483648;
	printf("int = %i, ft_itoa = %s\n\n", i_itoa, ft_itoa(i_itoa));

	//ft_putchar
	ft_putchar(argv[2][0]);

	//ft_putstr
	ft_putstr("\nft_putstr: Hello, World!!!\n\n");

	//ft_putendl
	ft_putendl("ft_putendl: Hello, World!!!\n");

	//ft_pitnbr
	ft_putstr("ft_putnbr: ");
	ft_putnbr(ft_atoi(argv[1]));
	ft_putstr("\n\n");

	//ft_putchar_fd
	ft_putstr("ft_putchar_fd: ");
	ft_putchar_fd('c', 1);
	ft_putstr("\n\n");

	//ft_putstr_fd
	ft_putstr_fd("ft_putstr_fd: ", 1);
	ft_putstr_fd(argv[1], 1);
	ft_putstr_fd("\n\n", 1);

	//ft_putendl_fd
	ft_putendl_fd("ft_putendl_fd:", 1);
	ft_putendl_fd(argv[1], 1);

	//ft_putnbr_fd
	ft_putstr_fd("\n\nft_putnbr_fd: ", 1);
	ft_putnbr_fd(ft_atoi(argv[1]), 1);

*/
	return (0);
}








