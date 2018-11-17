#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char    *string_compression(char *str);
int     get_compressed_length(char *str, int len);
char    *compress(char *str, int len, int compressed);
void    itoa(char *str, int n);
int     digits(int n);


int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("Here %s compressed would look like: %s\n", av[1], string_compression(av[1]));
    }
}

char    *string_compression(char *str)
{
    int i = -1, len = (int)strlen(str), compressed;

    compressed = get_compressed_length(str, len);
    if (len > compressed) return compress(str, len, compressed);
    return (str);    
}

int     get_compressed_length(char *str, int len)
{
    char c;
    int clen = 0, i = 0, n;

    while (str[i])
    {
        n = 0;
        c = str[i];
        if (i + 1 < len && str[i + 1] == c)
        {
            while (str[i] == c)
            {
                i++;
                n++;
            }
            clen += 1 + digits(n);
        }
        else
        {
            i++;
            clen += 2;
        }
    }
    return (clen);
}

char    *compress(char *str, int len, int compressed)
{
    int i = 0, j = 0, counter;
    char *compressed_string = (char *)malloc(compressed + 1);
    
    compressed_string[compressed] = 0;
    while (str[i])
    {
        counter = 1;
        compressed_string[j] = str[i];
        if (i + 1 < len && str[i + 1] == compressed_string[j])
        {    
            i++;
            while (str[i] == compressed_string[j])
            {
                counter++;
                i++;
            }
        }  
        else i++;
        j++;
        itoa(compressed_string + j, counter);
        j+= digits(counter);
    }
    return (compressed_string);
}

void    itoa(char *str, int n)
{
    int len = digits(n);

    while (len > 0)
    {
        len--;
        str[len] = (n % 10) + '0';
        n /= 10;
    }
}

int     digits(int n)
{
    int i = 0;

    while (n)
    {
        n /= 10;
        i++;
    }
    return (i);
}