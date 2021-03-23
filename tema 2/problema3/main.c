#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <time.h>
int n;

void genper(int p)
{int i;
 FILE *fout=fopen("p3.in","w");
 srand(time(NULL));
    long int r=rand()*rand();
     r=0+r%(10-0+1);
     fprintf(fout,"%ld\t",r);

  fclose(fout);
}


int solp(int k,int *x)
{int i;
    for(i=1;i<k;i++)
        if(x[i]==x[k] || abs(x[i]-x[i+1])<2) // abs(x[k-1]-x[k])<2
            return 0;
    return 1;
}

void bkt(int k, FILE *fout,int *x)
{int i,j;
 for(i=1;i<=n;i++)
    {x[k]=i;
     if(solp(k,x)==1)
        {if(k==n)
            {for(j=1;j<=k;j++)
                fprintf(fout,"%d ",x[j]);
             fprintf(fout,"\n");
            }
         else
            bkt(k+1,fout,x);
        }
    }
}




int main()
{
 genper(1);
 FILE *fin=fopen("p3.in","r");
 FILE *fout=fopen("p3.out","w");
 fscanf(fin,"%d",&n);
 int *x=malloc((n+1)*sizeof(int)); // x=(int*)calloc(n+1,sizeof(int));
 if(n<4)
    fprintf(fout,"Numarul generat este mai mic decat 4");
 else
    bkt(1,fout,x);
 fclose(fin);
 fclose(fout);
 free(x);

    return 0;
}
