#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef void    pixel;

void    str_split_to_int(int *layer, char *str, int n);
void    print_array(int **arr, int n);
void    rotate_array(int **arr, int n);


int main(int ac, char **av)
{
    if (ac == 2)
    {
        int n, i = -1, j;
        FILE *fp = fopen(av[1], "r");
        char    line[256];

        n = atoi(fgets(line, sizeof(line), fp));
        int **arr = (int **)malloc(sizeof(int *) * n);
        int layer[n];

        while (++i < n)
        {
            j = -1;
            fgets(line, sizeof(line), fp);
            str_split_to_int(layer, line, n);
            arr[i] = (int *)malloc(sizeof(int) * n);
            while (++j < n)
                arr[i][j] = layer[j];
        }

        fclose(fp);



        printf("Here's the picture you gave:\n");
        print_array(arr, n);
        printf("\nAnd here's that picture rotated 90 degrees clockwis:\n");
        rotate_array(arr, n);
        print_array(arr, n);
    }
}

void    str_split_to_int(int *layer, char *str, int n)
{
    int i = -1, j = 0;

    while (++i < n && str[j])
    {
        layer[i] = atoi(str + j);
        while(str[j] && str[j] != '\n' && str[j] != ' ')
            j++;
        j++;
    }
}

void    rotate_array(int **arr, int n)
{
    int i, j = 0, k, x = n;
    int swap[n-1];

    while(x > 1)
    {
        i = -1;
        while (++i < x - 1)
        {
            k = i + j;
            swap[i] = arr[j][k];
            arr[j][k] = arr[n - 1 - k][j];
            arr[n - 1 - k][j] = arr[n - 1 - j][n - 1 - k];
            arr[n - 1 - j][n - 1 - k] = arr[k][n - 1 - j];
            arr[k][n - 1 - j] = swap[i];
        }
        j++;
        x -= 2;
    }
}

void    print_array(int **arr, int n)
{
    int i = -1, j;

    while (++i < n)
    {
        j = -1;
        while (++j < n - 1)
            printf("%d ",arr[i][j]);
        printf("%d\n",arr[i][j]);
    }
}