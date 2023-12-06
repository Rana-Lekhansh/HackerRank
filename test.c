#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;

    char* data = malloc(alloc_length);

    while (true) {
        printf("Data - %s\n", data);
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        printf("Data - %sCursor - %sline - %s\n", data,cursor,line);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);
        printf("DatLength - %d\n", data_length);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            printf("Yaha tk tho aaye\n");
            break;
        }

        alloc_length <<= 1;
        printf("Alloc_Length - %d\n", alloc_length);

        data = realloc(data, alloc_length);


        if (!data) {
            data = '\0';

            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        printf("part 2");
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);

        if (!data) {
            data = '\0';
        }
    } else {

        data = realloc(data, data_length + 1);

        if (!data) {
            data = '\0';
        } else {
            data[data_length] = '\0';
        }
    }

    return data;
}

char* rtrim(char* str) {
    if (!str) {
        return '\0';
    }

    if (!*str) {
        return str;
    }

    char* end = str + strlen(str) - 1;
    printf("End -- %s\n",end);
    while (end >= str && isspace(*end)) {
        end--;
        printf("New End -- %c\n",end);
    }

   // *(end + 1) = '\0';

    return str;
}

char* ltrim(char* str) {
    if (!str) {
        printf("we are here -1\n");
        return '\0';
    }

    if (!*str) {
        printf("we are here - 2\n");
        return str;
    }

    while (*str != '\0' && isspace(*str)) {
        str++;
        printf("%c\n",*str);
    }

    return str;
}


char *print(){
    char* data ;
    data = (char*)malloc(1000*sizeof(char));

    fgets(data,1000,stdin);
    if (!data) {
            data = '\0';
        }
    return data;

}







int main(){

   printf("\n%s",rtrim(print()));
   //printf("\nEntered text - %s", print());
    return 0;
}
