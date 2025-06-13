/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwotsche <dwotsche@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:56:58 by dwotsche          #+#    #+#             */
/*   Updated: 2025/06/13 11:39:12 by dwotsche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	// ----- Testing the MEMSET -----
	// char str[50] = "GeeksForGeeks is for programming geeks.";
	// printf("\nBefore memset(): %s\n", str);
	// memset(str + 13, '.', 8*sizeof(char));
	// printf("After memset(): %s", str);

	// ----- Testing the MEMCPY -----
	// int	a = 20;
	// int	b = 10;
	// printf("Value of b before calling memcpy: %d\n", b);
	// memcpy(&b, &a, sizeof(int));
	// printf("Value of b after calling memcpy: %d\n", b);

	// int	c = 20;
	// int	d = 10;
	// printf("Value of d before calling memcpy: %d\n", d);
	// ft_memcpy(&d, &c, sizeof(int));
	// printf("Value of d after calling memcpy: %d\n", d);

	// char str1[] = "Geeks";
	// char str2[6] = "";
	// memcpy(str2, str1, sizeof(str1));
	// printf("str2 after memcpy:\n");
	// printf("%s\n",str2);

	// char str3[] = "Geeks";
	// char str4[6] = "";
	// ft_memcpy(str4, str3, sizeof(str3));
	// printf("str2 after memcpy:\n");
	// printf("%s",str4);

	// ----- Testing the STRLCPY -----
	// char dst[50] = "";
	// const char src[50] = "This is the Text";
	// printf("This is before FT_STRLCPY:\nDST: %s\nSRC: %s\n", dst, src);
	// ft_strlcpy(dst, src, ft_strlen(src));
	// printf("This is after FT_STRLCPY:\nDST: %s\nSRC: %s\n", dst, src);

	// char str2[50] = "GeeksForGeeks is for programming geeks.";
	// printf("\nBefore ft_memset(): %s\n", str2);
	// ft_memset(str2 + 13, '.', 8*sizeof(char));
	// printf("After ft_memset(): %s", str2);

	// ----- Testing the STRCHR -----
	// const char* str = "aGeeksforGeeksa";
	// char ch = 'a';
	// const char* res = strchr(str, ch);
	// if (res != NULL)
	// {
	// 	printf("Character '%c' found at position: %ld\n",
	// 		ch, res - str);
	// }
	// else
	// 	printf("Character '%c' not found.\n", ch);

	// const char* res2 = ft_strchr(str, ch);
	// if (res2 != NULL)
	// {
	// 	printf("Character '%c' found at position: %ld\n",
	// 		ch, res2 - str);
	// }
	// else
	// 	printf("Character '%c' not found.\n", ch);
	
	// ----- Testing the STRRCHR -----
	// char str[] = "GeeksforGeeks";
	// char chr = 'k';
	// char* ptr = strrchr(str, chr);
	// if (ptr) {
	// 	printf("Last occurrence of %c in %s is at index %ld\n",
	// 		chr, str, ptr - str);
	// }
	// else {
	// 	printf("%c is not present in %s\n", chr, str);
	// }

	// char* ptr2 = ft_strrchr(str, chr);
	// if (ptr2) {
	// 	printf("Last occurrence of %c in %s is at index %ld\n",
	// 		chr, str, ptr2 - str);
	// }
	// else {
	// 	printf("%c is not present in %s\n", chr, str);
	// }

	// ----- Testing the SRNCMP -----
	// char str[][5] = { "R2D2", "C3PO", "R2A6"};
	// int n = 0;
	// printf("looking for R2 astromech droids...\n");
	// while (n < 3)
	// {
	// 	if (strncmp(str[n], "R2xx", 2) == 0)
	// 	{
	// 		printf("found %s\n", str[n]);
	// 	}
	// 	n++;
	// }
	
	// int i = 0;
	// printf("looking for R2 astromech droids...\n");
	// while (i < 3)
	// {
	// 	if (strncmp(str[i], "R2xx", 2) == 0)
	// 	{
	// 		printf("found %s\n", str[i]);
	// 	}
	// 	i++;
	// }

	// ----- Testing MEMCHR -----
	const char str[] = "ABCDEFG";
	const int chars[] = {'D', 'd'};
	for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i)
	{
		const int c = chars[i];
		const char *ps = memchr(str, c, strlen(str));
		ps ? printf ("character '%c'(%i) found: %s\n", c, c, ps)
		: printf ("character '%c'(%i) not found\n", c, c);
	}
	
	return 0;
}
