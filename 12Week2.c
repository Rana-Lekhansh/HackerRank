#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int power(int n, int p)
{

    int ans = 1;
    for (int i = 0; i < p; i++)
    {
        ans = ans * n;
    }
    return ans;
}

int powerto(int n, int p)
{

    if (p == 0)
        return 1;
    else if (p == 1)
        return n;
    return n * powerto(n, p - 1);
}

int check_power(int n)
{
    int i = 0;
    int new_n = n;
    while (n % 2 == 0)
    {
        n = n / 2;
        i++;
    }

    if (power(2, i) == new_n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char *near(int n)
{
    int a = 0;
    int new = n;
    while (n)
    {
        if (check_power(n))
        {
            a = new - n;
            if (check_power(new - n))
            {
                int i = 0;
                while (a % 2 == 0)
                {
                    a = a / 2;
                    i++;
                }

                if (i % 2 == 0)
                {
                    return "Love";
                }
                else
                    return "Rich";
            }
            else{
                 return near(a);

            }

        }
        n--;
    }
}

int main()
{

    printf("%s", near(6));

    return 0;
}