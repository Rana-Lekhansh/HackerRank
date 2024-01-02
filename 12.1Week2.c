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

void reverse(int *arr, int n){

int temp;
for(int i=0;i<n/2;i++){
    temp = arr[i];
    arr[i] = arr[n-i-1];
    arr[n-i-1]=temp;
}

}
int *binary(int n, int *s){

    int *result ;
    result = malloc(32*sizeof(int));
    int *resultPtr = result;
    *s = 0;
    int i = 0;
    while(n){
      
      *resultPtr = n%2;
      resultPtr++; 
        n = n/2;
    }

    *s = resultPtr - result;
return result;
}


int countone(int *arr, int n){

int count=0;
for(int i=0;i<n;i++){
  if(arr[i]==1)count++;
}
return count;
}

int countSetBits(long long n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}
char* counterGame(long long n) {

   int size;
   int * array = binary(n-1,&size);
   int a = countSetBits(n - 1);

    if (a % 2 == 1)
    {
        return "Louise";
    }
    else
    {
        return "Richard";
    }
   

}

int main(){
  
    printf("%s", counterGame(605846385118282));
    return 0;
 }