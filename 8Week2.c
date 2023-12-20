#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int cmp(const void *a, const void *b)
{
    return strcmp(*(const char **)a, *(const char **)b);
}

void print_array(char *arr, int n)
{
    printf("Array--");
    for (int i = 0; i < n; i++)
    {
        printf("%c", *(arr + i));
    }
    printf("\n");
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(char *arr, int low, int high)
{
    char pivot = arr[low];
    int count = 0;
    for (int i = low + 1; i <= high; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    int pivot_index = low + count;
    swap(&arr[pivot_index], &arr[low]);

    int i = low;
    int j = high;

    while (i < pivot_index && j > pivot_index)
    {
        while (arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < pivot_index && j > pivot_index)
        {
            swap(&arr[i], &arr[j]);
        }
    }
    return pivot_index;
}

void quicksort(char *arr, int s, int e)
{
    if (s >= e)
        return;

    int pi = partition(arr, s, e);
    quicksort(arr, s, pi - 1);
    quicksort(arr, pi + 1, e);
}


char* gridChallenge(int numStrings, char** array) {
    
    int n = 0;
    for (int i = 0; i < numStrings; i++)
    {
         n = strlen(*(array+i));
        quicksort(*(array+i), 0, n - 1);
        print_array(*(array+i), n);
    }
    
    int flag = 0;

    char *result = "YES";
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < numStrings; j++)
        {   

            if(array[j - 1][i]>array[j][i]){
                flag++;
                break;}

        }
        if (flag == 1)
        {   
            result = "NO";
            break;
        }
    }

   return result;

}


int main()
{   
    char **array;
    int numStrings = 3;

    // Allocate memory for the array of strings
    array = (char **)malloc(numStrings * sizeof(char *));

    // Check if memory allocation was successful
    if (array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    // Allocate memory for each individual string
    for (int i = 0; i < numStrings; i++) {
        array[i] = (char *)malloc(20 * sizeof(char)); // Assuming each string can hold 19 characters plus the null terminator
    }

    // Assign values to each string
    strcpy(array[0], "avhc");
    strcpy(array[1], "byuf");
    strcpy(array[2], "zuig");

    char* result = gridChallenge(numStrings, array);
    
    printf( "%s\n", result);

    return 0;
}
