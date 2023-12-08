#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void print_array(int n, int *ar)
{

    printf("Array - \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(ar + i));
    }
    printf("\n");
}

int max(int n, int *ar)
{
    int maxvalue = ar[0];
    
    for (int i = 1; i < n; i++)
    { //  printf("max = %d\t\tarray = %d\t\t\n",maxvalue,ar[i]); 
        if(ar[i]>maxvalue){
            maxvalue=ar[i];
        }
            }
            return maxvalue;
}

int sockMerchant(int n, int *ar)
{

    int k = 0;
    int size  = max(n, ar);
   // printf("\n%d\n",size);
    int *count = calloc(size, sizeof(int));

    for (int i = 0; i < size; i++)
    {
        count[ar[i]]++;
    }
    print_array(size, count);

    for (int i = 0; i < size; i++)
    {   printf("element - %d\t\t k - %d\t\t\n", count[i],k);
        if(count[i]%2!=0 && count[i]>0){
            k++;}
    }

    return k;
}

int main()
{

    int n = 9;
    int array[] = {10, 20, 20, 10, 10, 30, 50, 10, 20};

    int size  = max(n, array);
    printf("\n%d\n",size);

//    print_array(n, array);

    printf("\nOdd pair--%d\n ", sockMerchant(n, array));

    // print_array(n, array);

    return 0;
}