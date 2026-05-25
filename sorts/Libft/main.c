/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrpere <rodrpere@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 11:52:16 by rodrpere          #+#    #+#             */
/*   Updated: 2026/04/27 14:58:01 by rodrpere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static void	test_fstrlcpy(void)
{
	char src[6] = "ellif";
	char dst[6] = "souma";
	
	printf("\n1. strlcpy:\n");
	printf("Before: %s\n", dst);
	ft_strlcpy(dst, src, 3);
	printf("After: %s\n\n", dst);
}

static void	test_fstrlcat(void)
{
	char src[6] = "that!";
	char dst[50]= "This and ";

	printf("\n2. strlcat:\n");
	printf("Before: %s\n", dst);
	ft_strlcat(dst, src, sizeof(dst));
	printf("After: %s\n\n", dst);
}

static void	test_fifis(void)
{
	char	input[64];
	char	c;

	printf("\n3. isalpha / isdigit / isalnum:\n");
	printf("Choose a character: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	c = input[0];

	printf("isalpha('%c'): %s\n", c, ft_isalpha(c) ? "true" : "false");
	printf("isdigit('%c'): %s\n", c, ft_isdigit(c) ? "true" : "false");
	printf("isalnum('%c'): %s\n\n", c, ft_isalnum(c) ? "true" : "false");
}

static void	test_fASCII(void)
{
	char	input;
	int		num;

	printf("\n4.isascii & isprint:\n");
	printf("Choose an ascii character:\n");
	scanf("%c", &input);

	num = (int) input;
	printf("is it ascii(%d): %s\n\n", num, ft_isascii(num) ? "true" : "false");
	printf("is it print(%d): %s\n", num, ft_isprint(num) ? "true": "false");
}

static void	test_fccase()
{
	char	input;
	int		num;

	printf("\n5.tolower & toupper:\n");
	printf("Choose an character:\n");
	scanf("%c", &input);

	num = (int)input;
	printf("lowercase of (%c) is: %c\n",num, ft_tolower(num));
	printf("uppercase of (%c) is: %c\n",num, ft_toupper(num));
}

static void test_posix()
{
	const char	*search;
	char		input[64];
	char		c;

	printf("\n6. strchr & strrchr:\n");
	printf("Write a string: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	printf("Choose a char:");
	scanf("%c", &c);

	search = ft_strchr(input, c);
	if (search != NULL)
		printf("Character %c found at position: %ld\n", c, search - input);
	else
		printf("Character %c not found.\n", c);
	search = ft_strrchr(input, c);
	if (search != NULL)
		printf("Character %c found at position: %ld\n", c, search - input);
	else
		printf("Character %c not found.\n", c);
}

static void test_split()
{
	char		**res;
	char	input[64];
	int			i;

	i = 0;
	printf("\n7. split:\n");
	printf("Write a string: ");
	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = '\0';
	res = ft_split(input, ' ');
	while (res[i])
	{
		printf("str[%d]: %s\n", i, res[i]);
		i++;
	}
}
static void test_trim()
{
	char *s1 = "   hello world   ";
    char *set = " ";

    char *result = ft_strtrim(s1, set);
	printf("\n7. split:\n");
    if (result)
    {
        printf("Original: '%s'\n", s1);
        printf("Trimmed : '%s'\n", result);
    }
    else
    {
        printf("ft_strtrim returned NULL\n");
    }

    free(result);
}
/*static void test_case3();
static void test_case4();*/

int	main(void)
{
	int	option;
	int ch;
	printf("Starting main program...\n"
		"--------------------------\n");
	printf("select an option:\n"
		"1. strlcpy.\n"
		"2. strlcat.\n"
		"3. isalpha / isdigit / isalnum.\n"
		"4. isascii & isprint.\n"
		"5. tolower & toupper.\n"
		"--------------------------\n"
		"6. strchr & strrchr.\n"
		"7. ft_split\n"
		"8. ft_strtrim\n");
	scanf("%d", &option);
	while ((ch = getchar()) != '\n' && ch != EOF)
		continue;
	switch (option)
	{
		case 1:
			test_fstrlcpy();
			break;
		case 2:
			test_fstrlcat();
			break;
		case 3:
			test_fifis();
			break;
		case 4:
			test_fASCII();
			break;
		case 5:
			test_fccase();
			break;
		case 6:
			test_posix();
			break;
		case 7:
			test_split();
			break;
		case 8:
			test_trim();
			break;
		case 9:
			break;
		case 0:
			break;
		default:
			printf("Error: Select a valid option\n");
			break;
	}
	printf("\nYou have reached the end of the program\nExiting...");
	return (0);
}
