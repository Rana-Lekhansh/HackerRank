#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void print_array(int *arr, int n)
{
    printf("Array--");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(arr + i));
    }
    printf("\n");
}

int sumofarray(int *arr, int start, int end)
{

    int sum = 0;
    for (int i = start; i < end; i++)
    {
        sum = sum + arr[i];
    }
    return sum;
}

char *Result(int *arr, int n)
{

    char *ans = "NO";

    int sumleft = 0;
    int sumright = sumofarray(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        sumright = sumright - arr[i];

        if (sumleft == sumright)
            ans = "YES";
        sumleft = sumleft + arr[i];
    }
    return ans;
}

int main()
{

    int array[] = {2, 0, 0, 0};
    int n = sizeof(array) / sizeof(array[0]);
    print_array(array, n);
    printf("%s", Result(array, n));
    return 0;
}