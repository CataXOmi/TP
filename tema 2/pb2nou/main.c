#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n,m;

struct cubulet
{
    int lu;
    char culoare[21];
};

int solp(int k,int *x,struct cubulet *cub,int *fr)
{if(fr[x[k]]==1)
    return 0;
 if(k>1 && cub[x[k]].lu>cub[x[k-1]].lu)
    return 0;
  if(k>1 && strcmp(cub[x[k]].culoare,cub[x[k-1]].culoare)==0)
    return 0;
    return 1;
}

void bkt(int k,FILE *fout,int *x,struct cubulet *cub,int *fr)
{int i,j;
 for(i=1;i<=n;i++)
    {x[k]=i;
     if(solp(k,x,cub,fr)==1)
        {fr[x[k]]=1;
         if(k>=m)
            {for(j=1;j<=k;j++)
                {
                    fprintf(fout,"%d %s ",cub[x[j]].lu,cub[x[j]].culoare);
                }
             fprintf(fout,"\n");
            }
         else
            bkt(k+1,fout,x,cub,fr);
         fr[x[k]]=0;
        }
    }
}

int main()
{int i;
 FILE *fin=fopen("p2.in","r");
 FILE *fout=fopen("p2.out","w");
 fscanf(fin,"%d %d",&n,&m);
 int *x=malloc((n+1)*sizeof(int));
 int *fr=malloc((n+1)*sizeof(int));
 struct cubulet* cub=malloc((n+1)*sizeof(struct cubulet));
 for(i=1;i<=n;i++)
        {fscanf(fin,"%d",&cub[i].lu);
         fscanf(fin,"%s",cub[i].culoare);
        }
 while(m<=n)
    {
     bkt(1,fout,x,cub,fr);
     m++;
    }
 fclose(fin);
 fclose(fout);
 free(cub);
 free(x);
 free(fr);
    return 0;
}
