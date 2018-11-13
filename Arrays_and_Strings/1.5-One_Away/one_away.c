#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    one_away(char *s1, char *s2);
char    replace_letter(char *s1, char*s2);
char    one_short(char *s1, char *s2);
int     lstrcmp(char *s1, char *s2);

int main(int ac, char **av)
{
    if (ac == 3)
    {
        printf("The two strings provided are%s one or fewer modifications separated.\n", one_away(av[1], av[2]) ? "" : " not");
    }
}

char    one_away(char *s1, char *s2)
{
    int l1 = (int)strlen(s1), l2 = (int)strlen(s2);

    if (l1 == l2 && (!strcmp(s1, s2) || replace_letter(s1, s2)))
        return 1;
    if (l1 == l2 + 1 && one_short(s2, s1))
        return 1;
    if (l1 == l2 - 1 && one_short(s1, s2))
        return 1;
    return 0;
}

char    replace_letter(char *s1, char*s2)
{
    int i = lstrcmp(s1, s2);

    s1[i] = s2[i];
    return (strcmp(s1, s2) ? 0 : 1);
}

char    one_short(char *s1, char *s2)
{
    int i = lstrcmp(s1, s2);

    return (strcmp(s1 + i, s2 + i + 1) ? 0 : 1);
}

int     lstrcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i]) i++;
    return i;
}