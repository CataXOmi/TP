#include <stdio.h>
#include <stdlib.h>

int main()
{FILE *fin=fopen("p_3.in","r");
 FILE *fout=fopen("p_3.out","w");
 int n,i,j,pmax;
 fscanf(fin,"%d",&n);
 int *subs=(int*)malloc(n*sizeof(int));
 for (i=0;i<n;i++)
    {
         fscanf(fin,"%d",&subs[i]);
    }
 int **sir=(int**)malloc(n*sizeof(int*));
 for (i=0;i<n;i++)
    {
     int *sir[i]=(int*)malloc(n*sizeof(int));
    }
 for(i=n-1;i>=0;i--)
    for(j=i+1;j<n;j++)
        if(subs[i]>subs[j])
            sir[i][j]=
 fclose(fin);
 fclose(fout);
 free(subs);
    return 0;
}
