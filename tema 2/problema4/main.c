#include <stdio.h>
#include <stdlib.h>

#define DIM 9

int **sudk;

//function to print sudoku

void afisare(FILE *fout)
{int i,j;
    for(i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            fprintf(fout,"%d\t",sudk[i][j]);
        }
        fprintf(fout,"\n\n");
    }

}

//function to check if all cells are assigned or not
//if there is any unassigned cell
//then this function will change the values of
//row and col accordingly

int number_unassigned(int *row, int *col)
{
    int num_unassign = 0;
    int i,j;
    for(i=0;i<DIM;i++)
    {
        for(j=0;j<DIM;j++)
        {
            //cell is unassigned
            if(sudk[i][j] == 0)
            {
                //changing the values of row and col
                *row = i;
                *col = j;
                //there is one or more unassigned cells
                num_unassign = 1;
                return num_unassign;
            }
        }
    }
    return num_unassign;
}

//function to check if we can put a
//value in a paticular cell or not
int is_safe(int n, int r, int c)
{
    int i,j;
    //checking in row
    for(i=0;i<DIM;i++)
    {
        //there is a cell with same value
        if(sudk[r][i] == n)
            return 0;
    }
    //checking column
    for(i=0;i<DIM;i++)
    {
        //there is a cell with the value equal to i
        if(sudk[i][c] == n)
            return 0;
    }
    //checking sub matrix
    int row_start = (r/3)*3;
    int col_start = (c/3)*3;
    for(i=row_start;i<row_start+3;i++)
    {
        for(j=col_start;j<col_start+3;j++)
        {
            if(sudk[i][j]==n)
                return 0;
        }
    }
    return 1;
}

//function to solve sudoku
//using backtracking
int solve_sudoku()
{
    int row;
    int col;
    //if all cells are assigned then the sudoku is already solved
    //pass by reference because number_unassigned will change the values of row and col
    if(number_unassigned(&row, &col) == 0)
        return 1;
    int i;
    //number between 1 to 9
    for(i=1;i<=9;i++)
    {
        //if we can assign i to the cell or not
        //the cell is matrix[row][col]
        if(is_safe(i, row, col))
        {
            sudk[row][col] = i;
            //backtracking
            if(solve_sudoku())
                return 1;
            //if we can't proceed with this solution
            //reassign the cell
            sudk[row][col]=0;
        }
    }
    return 0;
}

int main()
{int i,j;
 FILE *fin=fopen("p4.in","r");
 FILE *fout=fopen("p4.out","w");
 sudk=(int **)malloc(DIM*sizeof(int*));
 for(i=0;i<DIM;i++)
    {
        sudk[i]=(int*)malloc(DIM*sizeof(int));
    }
 for(i=0;i<DIM;i++)
    for(j=0;j<DIM;j++)
        fscanf(fin,"%d",&sudk[i][j]);
 if (solve_sudoku())
        afisare(fout);
 else
        fprintf(fout,"No solution\n");
 fclose(fin);
 fclose(fout);
 free(sudk);
    return 0;
}
