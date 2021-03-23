#include <stdio.h>
#include <stdlib.h>

int main()
{FILE *fin=fopen("p_4.in","r");
 FILE *fout=fopen("p_4.out","w");
 int n,i,j,pmax;
 fscanf(fin,"%d",&n);
 int *cop=(int*)malloc(n*sizeof(int));
 for (i=0;i<n;i++)
    {
         fscanf(fin,"%d",&cop[i]);
    }
 int *lmax=(int*)malloc(n*sizeof(int));
 int *succ=(int*)malloc(n*sizeof(int));
 for(i=n-1;i>=0;i--)
    {lmax[i]=1;
     succ[i]=-1;
     for(j=i+1;j<n;j++)
        if(cop[i]>cop[j] && 1+lmax[j]>lmax[i])
                {
                    lmax[i]=1+lmax[j];
                    succ[i]=j;
                }
    }
     pmax=0;
     for (i=1;i<n;i++)
            if(lmax[i]>lmax[pmax])
                pmax=i;
     fprintf(fout,"Va trebui sa taiem un numar minim de %d copaci\n",n-lmax[pmax]);
     for(i=0;i<n;i++)
     {
        if(lmax[i]!=pmax)
            fprintf(fout,"Va trebui sa taiem copacul %d\n", i+1);
        else
            pmax--;
     }
    free(cop);
    free(lmax);
    free(succ);
    fclose(fin);
    fclose(fout);
    return 0;
}
