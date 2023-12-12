#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int pageCount(int n, int p) {

int diff1 = n-p;
int diff2 = p-1;



if(diff1<=diff2){
    return diff1/2;
}
else if(diff1==0||diff2==0)  {
    return 0;
}
else if(diff1==1||diff2==1)  {
    return 1;
}
else{
    return (diff2+1)/2;
}

}

int main(){
    
   int n = 7;
   int p = 4;
   printf("Ans- %d", pageCount(n,p));


    return 0;
 }