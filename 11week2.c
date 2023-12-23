#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int answer(int n)
{
    if ((n / 10) == 0)
        return n;
    else
    {
        int sum = 0;
        int remain = 0;
        while (n)
        {

            remain = n % 10;

            sum = sum + remain;

            n = n / 10;
        }
        return answer(sum);
    }
}

int superDigit(char *n, int k)
{
    int numberofdigits = strlen(n);
    char *ptr;
    int ret;
    ret = strtol(n, &ptr, 10);
    int sum = 0;
    int remain = 0;
    while (ret)
    {

        remain = ret % 10;

        sum = sum + remain;

        ret = ret / 10;
    }
    return answer(sum * k);
}

int main()
{
    char *n = "123";
    int k = 3;
    printf("%d", superDigit(n, k));


    const char *str = "3546630947312051453014172159647935984478824945973141333062252613718025688716704470547449723886626736";

    // Convert string to long long int
   int numberofdigits = strlen(str);

    // Print the result
    printf("\nConverted number: %d\n", numberofdigits);
    return 0;
}