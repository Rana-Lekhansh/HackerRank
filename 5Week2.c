#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char *readline()
{
    size_t alloc_size = 1024;
    size_t data_size = 0;
    char *data = malloc(alloc_size * sizeof(char));

    while (true)
    {
        printf("Enter the string - ");
        char *line = fgets(data, alloc_size, stdin);

        if (!line)
        {
            break;
        }
        data_size = strlen(line);

        if (data_size < alloc_size - 1 || data[data_size - 1] == '\n')
        {
            break;
        }

        alloc_size <<= 1;
        data = realloc(data, alloc_size);
        if (!data)
        {
            data = '\0';

            break;
        }
    }
    return data;
}

int main()
{

    int n = 3;
    char * string = readline();

for(int i=0;i<strlen(string);i++){
   if(isalpha(string[i])){

    char base =   isupper(string[i])  ? 'A' : 'a';
    string[i] = (string[i] - base + n)%26 + base; 
   }


}
    
    printf("%s", string);

    return 0;
}