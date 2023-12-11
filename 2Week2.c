#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverse_array(int start_index, int end_index, int *array){
    printf("\n");
    while(start_index<=end_index){

        printf("start -%d\t\t%d\t\tend - %d\t\t%d\n",start_index,array[start_index],end_index,array[end_index]);
                 swap(&array[start_index], &array[end_index]);
                 start_index++;
                 end_index--;
   }
    
}

void print_array(int n, int *array)
{
    printf("\nArray - ");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(array + i));
    }
}

void zigzag(int n, int *array)
{
    qsort(array, n, sizeof(int), cmpfunc);
    print_array(n, array);

    int mid = (n + 1) / 2;
    int end = n - 1;
    swap(&array[mid], &array[end]);
    print_array(n, array);
    reverse_array(mid+1,end-1,array);
 
}

int main()
{
    int array[] = {2, 3, 4, 6, 8, 1, 7, 5,9,12,15,11,10,13,14};
    size_t n = sizeof(array) / sizeof(array[0]);
    print_array(n, array);
    zigzag(n, array);
    print_array(n,array);
    
    return 0;
}
