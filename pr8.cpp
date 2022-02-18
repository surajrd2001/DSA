#include <stdio.h>

#define SIZE 5

int maze[SIZE][SIZE] = {
    {0,1,0,1,1},
    {0,0,0,0,0},
    {1,0,1,0,1},
    {0,0,1,0,0},
    {1,0,0,1,0}
};


int solution[SIZE][SIZE];

void printsolution()
{
    int i,j;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            printf("%d\t",solution[i][j]);
        }
        printf("\n\n");
    }
}

int solvemaze(int r, int c)
{
 
    if((r==SIZE-1) && (c==SIZE-1))
    {
        solution[r][c] = 1;
        return 1;
    }
 
    if(r>=0 && c>=0 && r<SIZE && c<SIZE && solution[r][c] == 0 && maze[r][c] == 0)
    {

        solution[r][c] = 1;
   
        if(solvemaze(r+1, c))
            return 1;
      
        if(solvemaze(r, c+1))
            return 1;
       
        if(solvemaze(r-1, c))
            return 1;
      
        if(solvemaze(r, c-1))
            return 1;
       
        solution[r][c] = 0;
        return 0;
    }
    return 0;

}

int main()
{
    int i,j;
    for(i=0; i<SIZE; i++)
    {
        for(j=0; j<SIZE; j++)
        {
            solution[i][j] = 0;
        }
    }
    if (solvemaze(0,0))
        printsolution();
    else
        printf("No solution\n");
    return 0;
}