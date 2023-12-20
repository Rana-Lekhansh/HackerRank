#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void print_array(int * arr, int n){
    printf("Array--\n");
    for(int i=0;i<n;i++){
        printf("%d ", *(arr+i));
    }
    printf("\n");
}

int cmp(const void *a, const void *b){
    return  (*(int *)a - *(int *)b);
}

int max(int * arr,int n){

    int max_value = arr[0];
for(int i = 1;i<n;i++){
    if(arr[i]>max_value)max_value= arr[i];
}
return max_value;
}


int min(int * arr,int n){

    int min_value = arr[0];
for(int i = 1;i<n;i++){
    if(arr[i]<min_value)min_value= arr[i];
}
return min_value;
}

//optimal solution
int maxMin(int k, int n, int* arr) {

qsort(arr, n, sizeof(int), cmp);
    int result_value = arr[k - 1] - arr[0];

    for (int i = k; i < n; i++) {
        int current_result = arr[i] - arr[i - k + 1];
        result_value = (current_result < result_value) ? current_result : result_value;
    }

    return result_value;

}


int result(int k, int* arr, int n){

int b = k;
qsort(arr, n, sizeof(int), cmp);
print_array(arr,n);
int * new_array = malloc(k*sizeof(int));
int min_result = 0;
int i=0 , j = 0,a=0;
int result_value = max(arr,n);
while(k<=n){
for( i=a ,j=0; i< k && j < b;i++,j++){
    new_array[j] = arr[i];
}
print_array(new_array,b);
a++;
k++;


min_result = max(new_array,b)-min(new_array,b);

if( min_result< result_value){result_value=min_result;}  

}

return result_value;

}

int main(){
    
    
    //int array[]  = {6327,571,6599,479,7897,9322,4518,5716,677,7432,815,6920,4329,4104,7775,5708,7991,5802,8619,6053,7539,7454,9000,3267,6343,7165,4095,439,5621,4095,153,1948,1018,6752,8779,5267,2426,9649,2190,9103,7081,3006,2376,7762,3462,151,3471,1453,2305,8442};
    
    int array[]={100,
200,
300,
350,
400,
401,
402};
    
    
    
    int n = sizeof(array)/sizeof(array[0]);
    int k = 3; 
    print_array(array,n);
    
    
    printf("result - %d", result(k,array,n));
    
    //printf("result - %d", n);


    return 0;
 }