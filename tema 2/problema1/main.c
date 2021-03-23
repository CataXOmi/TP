#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;

struct steag
{
    char culoare[20];
}*cul;

int solp(int k,int *x)
{int i;
    for(i=1;i<k;i++)
        if(x[i]==x[k])
            return 0;
    return 1;
}

void bkt(int k, FILE *fout,int *x)
{int i,j;
 for(i=1;i<=n;i++)
    {x[k]=i;
     if(solp(k,x)==1)
        {if(k==3)
            {for(j=1;j<=k;j++)
                fprintf(fout,"%s ",cul[x[j]].culoare);
             fprintf(fout,"\n");
            }
         else
            bkt(k+1,fout,x);
        }
    }
}

int main()
{int  i;
 FILE *fin=fopen("p1.in","r");
 fscanf(fin,"%d",&n);
 FILE *fout=fopen("p1.out","w");
 cul=(struct steag*)malloc(n*sizeof(struct steag));
 int *x=malloc(n*sizeof(int));
 for(i=1;i<=n;i++)
    {
     fscanf(fin,"%s",cul[i].culoare);
     fgetc(fin);
    }

 bkt(1,fout,x);
 fclose(fin);
 fclose(fout);
 free(cul);

    return 0;
}
