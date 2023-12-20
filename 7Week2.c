#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void getthearray();

int *dynamicArray(int n, int queries_rows, int queries_columns, int **queries, int *result_count)
{
    int LA = 0;
    int *result = malloc(queries_rows * sizeof(int));
    int *resultPtr = result;  // Use a separate pointer for iteration
    int **arr = calloc(n, sizeof(int *));
    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++)
    {
        *(arr + i) = calloc(n, sizeof(int));
    }

    for (int i = 0; i < queries_rows; i++)
    {
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ LA) % n;

        if (queries[i][0] == 1)
        {
            idx = (queries[i][1] ^ LA) % n;

            if (idx == 0)
            {
                arr[idx][a] = queries[i][2];
                a++;
            }
            else
            {
                arr[idx][b] = queries[i][2];
                b++;
            }
        }
        else
        {
            idx = (queries[i][1] ^ LA) % n;
            LA = arr[idx][y % n];
            *resultPtr = LA;
            resultPtr++;
        }
    }

    // Calculate and update result_count
    *result_count = resultPtr - result;

    // Free allocated memory
    for (int i = 0; i < n; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return result;
}

int main()
{
    int row1[] = {1, 0, 5};
    int row2[] = {1, 1, 7};
    int row3[] = {1, 0, 3};
    int row4[] = {2, 1, 0};
    int row5[] = {2, 1, 1};

    int *arr[] = {row1, row2, row3, row4, row5};

    int n = 5;
    int result_count;
    int *result_array = dynamicArray(2, 5, 3, arr, &result_count);
     for(int i =0;i<result_count;i++){
     printf("%d\n", *(result_array+i));
     }
    return 0;
}

void getthearray()
{
    int row = 0, column = 0;
    printf("Enter the number of row - ");
    scanf("%d", &row);
    printf("Enter the number of column - ");
    scanf("%d", &column);

    int **arr = malloc(row * sizeof(int *));

    for (int i = 0; i < row; i++)
    {
        *(arr + i) = malloc(column * sizeof(int));
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            printf("enter the array[%d][%d]-", i, j);
            scanf("%d", (*(arr + i) + j));
        }
    }

    printf("Array - \n");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf(" %d ", *(*(arr + i) + j));
        }
        printf("\n");
    }
}
