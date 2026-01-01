#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "libft.h"


void print_header(char *name) {
    printf("\n\n=== Testing: %s ===\n", name);
}


char my_strmapi_func(unsigned int i, char c) {
    return (c + i);
}


void my_striteri_func(unsigned int i, char *c) {
    *c = *c + i;
}

int main()
{
    printf("****************************************\n");
    printf("********* LIBFT FULL TEST **************\n");
    printf("****************************************\n");

    // ================= PART 1: CTYPE =================
    
    print_header("ft_isalpha");
    printf("Check 'A': Orig=%d, Mine=%d\n", isalpha('A'), ft_isalpha('A'));
    printf("Check '1': Orig=%d, Mine=%d\n", isalpha('1'), ft_isalpha('1'));

    print_header("ft_isdigit");
    printf("Check '5': Orig=%d, Mine=%d\n", isdigit('5'), ft_isdigit('5'));
    printf("Check 'a': Orig=%d, Mine=%d\n", isdigit('a'), ft_isdigit('a'));

    print_header("ft_isalnum");
    printf("Check 'Z': Orig=%d, Mine=%d\n", isalnum('Z'), ft_isalnum('Z'));
    printf("Check '?': Orig=%d, Mine=%d\n", isalnum('?'), ft_isalnum('?'));

    print_header("ft_isascii");
    printf("Check 127: Orig=%d, Mine=%d\n", isascii(127), ft_isascii(127));
    printf("Check 128: Orig=%d, Mine=%d\n", isascii(128), ft_isascii(128));

    print_header("ft_isprint");
    printf("Check 32 (space): Orig=%d, Mine=%d\n", isprint(32), ft_isprint(32));
    printf("Check 31: Orig=%d, Mine=%d\n", isprint(31), ft_isprint(31));

    print_header("ft_toupper");
    printf("Check 'a' -> %c\n", ft_toupper('a'));
    
    print_header("ft_tolower");
    printf("Check 'Z' -> %c\n", ft_tolower('Z'));

    // ================= PART 1: STRING =================

    print_header("ft_strlen");
    char *s1 = "1337";
    printf("Len of '1337': Orig=%lu, Mine=%zu\n", strlen(s1), ft_strlen(s1));

    print_header("ft_strchr");
    char *s2 = "Hello";
    printf("Search 'e' in 'Hello': Orig=%s, Mine=%s\n", strchr(s2, 'e'), ft_strchr(s2, 'e'));
    
    print_header("ft_strrchr");
    printf("Search 'l' in 'Hello' (last): Orig=%s, Mine=%s\n", strrchr(s2, 'l'), ft_strrchr(s2, 'l'));

    print_header("ft_strncmp");
    printf("Compare 'abc' vs 'abd' (3): Orig=%d, Mine=%d\n", strncmp("abc", "abd", 3), ft_strncmp("abc", "abd", 3));

    print_header("ft_strnstr");
    char *haystack = "Foo Bar Baz";
   
    printf("Search 'Bar' in 'Foo Bar Baz' (len 8): Mine=%s\n", ft_strnstr(haystack, "Bar", 8));
    printf("Expected: Bar Baz\n");

    print_header("ft_strlcpy");
    char dst1[10];
    size_t ret1 = ft_strlcpy(dst1, "Hello World", sizeof(dst1));
    printf("Copy 'Hello World' to size 10 buffer -> Content: %s, Return: %zu\n", dst1, ret1);
    printf("Expected: Hello Wor, Return: 11\n");

    print_header("ft_strlcat");
    char dst2[20] = "Hello";
    size_t ret2 = ft_strlcat(dst2, " World", sizeof(dst2));
    printf("Cat ' World' to 'Hello' -> Content: %s, Return: %zu\n", dst2, ret2);

    print_header("ft_atoi");
    printf("atoi('  -42'): Orig=%d, Mine=%d\n", atoi("  -42"), ft_atoi("  -42"));
    printf("atoi(' +100'): Orig=%d, Mine=%d\n", atoi(" +100"), ft_atoi(" +100"));

    // ================= PART 1: MEMORY =================

    print_header("ft_memset");
    char mem1[10];
    ft_memset(mem1, 'A', 5);
    mem1[5] = 0; // null terminate for printing
    printf("Set 5 bytes to 'A': %s\n", mem1);

    print_header("ft_bzero");
    char mem2[10] = "AAAAA";
    ft_bzero(mem2, 2);
    printf("Bzero 2 bytes (should be empty/null at start): Is check? %d\n", (mem2[0] == 0 && mem2[1] == 0));

    print_header("ft_memcpy");
    char mem3[20];
    ft_memcpy(mem3, "CopyThis", 9);
    printf("Copied: %s\n", mem3);

    print_header("ft_memmove");
    char mem4[] = "123456789";
    ft_memmove(mem4 + 3, mem4, 3); // Overlap check
    printf("Overlap move '123' to index 3: %s\n", mem4);
    printf("Expected: 123123789\n");

    print_header("ft_memchr");
    char *mem5 = "abcdef";
    printf("Find 'd' in 'abcdef': Mine=%s\n", (char *)ft_memchr(mem5, 'd', 6));

    print_header("ft_memcmp");
    printf("Cmp 'abc' vs 'abc': %d\n", ft_memcmp("abc", "abc", 3));
    printf("Cmp 'abc' vs 'abd': %d\n", ft_memcmp("abc", "abd", 3));

    print_header("ft_calloc");
    int *nums = (int *)ft_calloc(5, sizeof(int));
    if (nums) {
        printf("Check if zeroed: %d %d %d\n", nums[0], nums[1], nums[2]);
        free(nums);
    }

    print_header("ft_strdup");
    char *dup = ft_strdup("Duplicate Me");
    printf("Original: Duplicate Me | Mine: %s\n", dup);
    free(dup);

    // ================= PART 2: ADDITIONAL =================

    print_header("ft_substr");
    char *sub = ft_substr("0123456789", 3, 4);
    printf("Sub of '0123456789' (start 3, len 4): %s\n", sub); // Expect 3456
    free(sub);

    print_header("ft_strjoin");
    char *join = ft_strjoin("Part1", "Part2");
    printf("Join: %s\n", join);
    free(join);

    print_header("ft_strtrim");
    char *trim = ft_strtrim("xxHello Worldxx", "x");
    printf("Trim 'x' from 'xxHello Worldxx': %s\n", trim);
    free(trim);

    print_header("ft_split");
    char **tab = ft_split("One,Two,Three", ',');
    if (tab) {
        printf("Split 'One,Two,Three':\n");
        for (int i = 0; tab[i]; i++) {
            printf("[%d]: %s\n", i, tab[i]);
            free(tab[i]);
        }
        free(tab);
    }

    print_header("ft_itoa");
    char *itoa_res = ft_itoa(-12345);
    printf("Itoa -12345: %s\n", itoa_res);
    free(itoa_res);

    print_header("ft_strmapi");
    char *mapi = ft_strmapi("abc", my_strmapi_func);
    // a+0=a, b+1=c, c+2=e
    printf("strmapi on 'abc' (add index): %s\n", mapi); // Expect "ace"
    free(mapi);

    print_header("ft_striteri");
    char iter_str[] = "000";
    ft_striteri(iter_str, my_striteri_func);
    // 0+0=0, 0+1=1, 0+2=2
    printf("striteri on '000' (add index): %s\n", iter_str); // Expect "012"

    print_header("ft_putchar_fd / putstr / putendl / putnbr");
    printf("(Check console below for: A, Hello, World(newline), 123)\n");
    ft_putchar_fd('A', 1);
    printf("\n");
    ft_putstr_fd("Hello", 1);
    printf("\n");
    ft_putendl_fd("World", 1);
    ft_putnbr_fd(123, 1);
    printf("\n");

    printf("\n**************** ALL TESTS FINISHED ****************\n");
    return (0);
}
