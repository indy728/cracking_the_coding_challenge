#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// typedef void    pixel;

void    str_split_to_int(int *layer, char *str, int n);
void    print_array(int **arr, int m, int n);
void    zero_array(int **arr, int m, int n);


int main(int ac, char **av)
{
    if (ac == 2)
    {
        int m, n, i = -1, j;
        FILE *fp = fopen(av[1], "r");
        char    line[256];

        m = atoi(fgets(line, sizeof(line), fp));
        n = atoi(fgets(line, sizeof(line), fp));
        int **arr = (int **)malloc(sizeof(int *) * n);
        int layer[m];

        while (++i < n)
        {
            j = -1;
            fgets(line, sizeof(line), fp);
            str_split_to_int(layer, line, m);
            arr[i] = (int *)malloc(sizeof(int) * m);
            while (++j < m)
                arr[i][j] = layer[j];
        }

        fclose(fp);



        printf("Here's the picture you gave:\n");
        print_array(arr, m, n);
        printf("\nAnd here's that file zero'd per the rules:\n");
        zero_array(arr, m, n);
        print_array(arr, m, n);
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

void    zero_array(int **arr, int m, int n)
{
    int i = -1, j, k, x = n;
    int z_rows[m], z_cols[n];

    bzero(z_rows, m * sizeof(int));
    bzero(z_cols, m * sizeof(int));

    while (++i < n)
    {
        j = -1;
        while (++j < m)
        {
            if (arr[i][j] == 0)
            {
                z_rows[i] = 1;
                z_cols[j] = 1;
            }
        }
    }
    i = -1;
    while (++i < n)
    {
        j = -1;
        while (++j < m)
        {
            if (z_rows[i] || z_cols[j])
                arr[i][j] = 0;
        }
    }
}

void    print_array(int **arr, int m, int n)
{
    int i = -1, j;

    while (++i < n)
    {
        j = -1;
        while (++j < m - 1)
            printf("%d ",arr[i][j]);
        printf("%d\n",arr[i][j]);
    }
}