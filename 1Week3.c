#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void print_char_array(int n, char *ar)
{

    // printf("Array - \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %c ", *(ar + i));
    }
    printf("\n");
}

void print_int_array(int n, int *ar)
{

    // printf("Array - \n");
    for (int i = 0; i < n; i++)
    {
        printf(" %d ", *(ar + i));
    }
    printf("\n");
}

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char** bomberMan(int n, int grid_count, char** grid, int* result_count) {

int * arr = (int *)malloc(n*grid_count*sizeof(int));
 *result_count = 0; 
int k = 0;
for (int i = 0; i < grid_count; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (grid[i][j] == 'O')
            {
                arr[k] = 10 * i + j;
                k++;
            }
        }
    }
 result_count = &k;

for (int i = 0; i < grid_count; i++)
    {
        for (int j = 0; j < n; j++)
        {
             grid[i][j] = 'O';
        }
    }



for (int l = 0; l < k; l++)
    {   
        int i = arr[l] / 10;
        int j = arr[l] % 10;
        grid[i][j] = '.';
        if ((i + 1) < 6){
            grid[i+1][j] = '.'; }
        if ((i - 1) >= 0){
            grid[i - 1][j] = '.';}
        if ((j + 1) < 7){
            grid[i][j + 1] = '.';}
        if ((j - 1) >= 0){
            grid[i][j - 1] = '.';}
    }



return grid;

}


def bombBlast(grid):
    x = len(grid)
    y = len(grid[0])
    blast = [['O'] * y for _ in range(x)]
    for i in range(x):
        for j in range(y):
            if grid[i][j] == 'O':
                blast[i][j] = '.'
                if i-1 >= 0:
                    blast[i-1][j] = '.'
                if j-1 >= 0:
                    blast[i][j-1] = '.'
                if i+1 < x:
                    blast[i+1][j] = '.'
                if j+1 < y:
                    blast[i][j+1] = '.'
    for i in range(len(blast)):
        blast[i] = ''.join(blast[i])
    return blast

def bomberMan(n, grid):
    x = len(grid)
    y = len(grid[0])
    if n == 1:
        return grid
    if n % 2 == 0:
        return ['O' * y for _ in range(x)]
    
    blast = bombBlast(grid)
    blast2 = bombBlast(blast)
        
    if n % 4 == 1:
        return blast2
    if n % 4 == 3:
        return blast

char **bobmBlast(char **grid){

    

}








int main()
{
    char **grid;
    grid = (char **)malloc(6 * sizeof(char *));

    for (int i = 0; i < 6; i++)
    {
        grid[i] = (char *)malloc(7 * sizeof(char));
    }

    strcpy(grid[0], ".......");
    strcpy(grid[1], "...O...");
    strcpy(grid[2], "....O..");
    strcpy(grid[3], ".......");
    strcpy(grid[4], "OO.....");
    strcpy(grid[5], "OO.....");


    for (int i = 0; i < 6; i++)
    {
        print_char_array(7, *(grid + i));
    }
    printf("\n"); printf("\n"); printf("\n");
   
   int result_count;
    char **answer = bomberMan(7, 6, grid, &result_count);


    for (int i = 0; i < 6; i++)
    {
        print_char_array(7, *(answer + i));
    }

    return 0;
}






/*
def bomberMan(n, grid):
    if n==1:
        return grid
    
    if n%2 == 0
        return ['O'*c for i range(r)]

    n //=2

    for q in range ((n+1)%2 + 1):
        newgrid = [['O']*c for i in range(r)]
        def set(x,y):
            if 0<=x<r && 0<=y<c:
                newgrid[x][y] = '.'

        xi = [0,0,0,1,-1]
        yi = [0,-1,1,0,0]

        for x in range(r)
            for y in range(c)
                if grid[x][y] == 'O'
                    for i,j in zip[xi,yi]
                        set(x+i,y+i)
        
        grid = newgrid

return ["".join(x) for x in grid]*/



