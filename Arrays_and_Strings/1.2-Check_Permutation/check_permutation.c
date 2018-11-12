#include <stdlib.h>
#include <stdio.h>

/*
**  My solution is to initialize a char array for the values of all printable characters that could
**  be within the given array, and iterate once over each given array. For each increment, that 
**  corresponding value in the value array would either increase for string1 or decrease for string2.
**  At the end if there are leftover characters in either string or if the array sum is anything 
**  other than one, the strings are not permutations.
**  Time taken: O(n)
**  Memory used: (n + printable characters) * sizeof(int)
*/

char    check_permutation(char *s1, char *s2);
char    checksum(int *arr, int range);

int main(int ac, char **av)
{
    if (ac == 3)
    {
        printf("The strings you entered are%s permutations.\n", check_permutation(av[1], av[2]) ? " not" : "");
    }
    return 0;
}

char    check_permutation(char *s1, char *s2)
{
    int arr[127-32] = {0};
    int i = 0;
    char x, y;

    while(s1[i] && s2[i])
    {
        x = s1[i] - 32;
        y = s2[i] - 32;
        arr[x]++;
        arr[y]--;
        i++;
    }

    if (s1[i] || s2[i] || checksum(arr, 127 - 32))
        return 1;
    return 0;
}

char    checksum(int *arr, int range)
{
    int sum = 0;

    for (int i = 0; i < range; i++)
    {
        sum += arr[i];
    }

    return sum == 0 ? 0 : 1;
}