#include <stdio.h>
#include <stdlib.h>

int main(){
     
     char* str = " 1007, he is also 007";
     char *ptr;
     int value;

     value = strtol(str,&ptr,10);
     printf("Number is %d\n", value);
     printf("string -- %s", ptr);
     

    return 0;
}