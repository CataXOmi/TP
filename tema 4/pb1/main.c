#include <stdio.h>
#include <stdlib.h>

int main()
{FILE *fin=fopen("p_1.in","r");
 FILE *fout=fopen("p_1.out","w");
 int n,m,i,j,k,pmax;
 fscanf(fin,"%d %d",&n,&m);
 int **a=(int**)malloc(n*sizeof(int*));
 for (i=0;i<n;i++)
    {
     a[i]=(int*)malloc(m*sizeof(int));
    }
 for (i=0;i<n;i++)
    for(j=0;j<m;j++)
        fscanf(fin,"%d",&a[i][j]);
 int *lmax=(int*)malloc(n*sizeof(int));
 int *succ=(int*)malloc(n*sizeof(int));
 for (j=0;j<m;j++)
    {for(i=n-1;i>=0;i--)
        {lmax[i]=1;
         succ[i]=-1;
         for(k=i+1;k<n;k++)
            if(a[k][j]>=a[i][j] && 1+lmax[k]>lmax[i])
                {
                    lmax[i]=1+lmax[k];
                    succ[i]=k;
                }
        }
     pmax=0;
     for (i=0;i<n;i++)
            if(lmax[i]>lmax[pmax])
                pmax=i;
     fprintf(fout,"Pe coloana %d avem ",j+1);
     fprintf(fout,"un subsir de lungime maxima %d\n",lmax[pmax]);
     fprintf(fout,"\t");
     i=pmax;
     while (i!=-1)
        {
          fprintf(fout,"%d ",a[i][j]);
          i=succ[i];
        }
     fprintf(fout,"\n");
    }
  free(a);
  free(lmax);
  free(succ);
  fclose(fin);
  fclose(fout);
    return 0;
}
