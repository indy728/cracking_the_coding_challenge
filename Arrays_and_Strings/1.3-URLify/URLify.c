#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *urlify(char *str);
int     url_strlen(char *str);
char    is_whitespace(char c);

int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("%s\n", urlify(av[1]));
    }
    return 0;
}

char    *urlify(char *str)
{
    int i = 0, j = 0, len = 0, url_len = url_strlen(str);
    char    *url = (char *)malloc(url_len + 1);
    url[url_len] = 0;

    while (is_whitespace(str[i]))
        i++;
    while(str[i] && len < url_len)
    {
        if (is_whitespace(str[i]))
        {
            len += 3;
            strcpy(url + j, "%20");
            j+= 3;
            while (is_whitespace(str[i]))
                i++;
            if (!str[i])
                len -= 3;
        }
        else
        {
            url[j] = str[i];
            ++i;
            ++j;
            ++len;
        }
    }
    return url;

}

int    url_strlen(char *str)
{
    int i = 0, len = 0;

    while (is_whitespace(str[i]))
        i++;
    while(str[i])
    {
        if (is_whitespace(str[i]))
        {
            len += 3;
            while (is_whitespace(str[i]))
                i++;
            if (!str[i])
                len -= 3;
        }
        else
        {
            ++i;
            ++len;
        }
    }
    return len;
}

char    is_whitespace(char c)
{
    return c == ' ' || c == '\t' ? 1 : 0;
}