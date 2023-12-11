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
        if (ar[i] > maxvalue)
        {
            maxvalue = ar[i];
        }
    }
    return maxvalue;
}

int sockMerchant(int n, int *ar)
{

    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (ar[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {   printf("i - %d\t\tj - %d\t\t\n", ar[i],ar[j]);
                if (ar[i] == ar[j]){
                    ar[j] = -1;
                    ar[i] = -1;
                printf("\nbreak\n");
                k++;
                break;

            }
        }
    }
    }

 //   for (int i = 0; i < n; i++){
 //      if(ar[i]!=-1)k++;
 //   }
   // print_array(n, ar);
    return k-1;
}

int main()
{

    int n = 9;
    int array[] = {10, 20, 20, 10, 10, 30, 50, 10, 20};

    int size = max(n, array);
    printf("\n%d\n", size);

    //    print_array(n, array);

    printf("\nOdd pair--%d\n ", sockMerchant(n, array));

    // print_array(n, array);

    return 0;
}