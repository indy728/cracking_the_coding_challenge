#include <stdlib.h>
#include <stdio.h>

/*
**  My solution is to initialize a char array for the values of all printable characters that could
**  be within the given array, and iterate once over the given array. For each increment, that 
**  corresponding value would in the value array would increment until either a value is greater
**  than 1 (indicating a character is not unique) or the end of the given array is reached.
**  Time taken: O(n)
**  Memory used: n + printable characters
*/

char    is_unique(char *str)
{
    char arr[127-32] = {0};
        int i = -1;
        char x;

        while(str[++i])
        {
            x = str[i] - 32;
            arr[x]++;
            if (arr[x] > 1)
                return 1;
        }
        return 0;
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        printf("The characters in the string you entered are %sall unique.\n", is_unique(av[1]) ? "not " : "");
    }
    return 0;
}