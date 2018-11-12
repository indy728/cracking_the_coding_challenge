#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    pal_perm(char *str);
char    is_upper(char c);
char    is_lower(char c);

int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("The string you entered is%s a permutation of a palindrome.\n", pal_perm(av[1]) ? "" : " not");
    }
    return 0;
}

char    pal_perm(char *str)
{
    int i, odds = 0, len = strlen(str);
    int arr[26] = {0};
    char c;

    if (len < 2) return 0;
    for (i = 0 ; i < len ; i++)
    {
        c = str[i];
        if (is_upper(c))
            c -= 'A' - 'a';
        if (is_lower(c))
            arr[c - 'a']++;

    }
    i = -1;
    while(++i < (26)) if (arr[i] % 2) odds++;
    return odds > 1 ? 0 : 1;
}

char    is_upper(char c)
{
    return ('A' <= c  && c <= 'Z') ? 1 : 0;
}

char    is_lower(char c)
{
    return ('a' <= c && c <= 'z') ? 1 : 0;
}