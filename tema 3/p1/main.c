#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void gennr(int n)
{int i,a=150,b=200;
 FILE *fpi=fopen("p1.in","w");
 srand(time(NULL));
 for(i=0;i<n;i++)
    {int r=rand()*rand();
     r=a+r%(b-a+1);
     fprintf(fpi,"%d\n",r);
    }
 fclose(fpi);
}

int pivot(int *v,int st,int dr)
{
    int i=st,j=dr,di=0,dj=-1,aux;
    while(i<j)
        {if(v[i]>=v[j])
                {aux=v[i];v[i]=v[j];v[j]=aux;
                 aux=di;di=-dj;dj=-aux;
                }
         i=i+di;
         j=j+dj;
        }
    return i;
}

void qsor(int *v,int st,int dr)
{int p;
 if(st<dr)
    {p=pivot(v,st,dr);
     qsor(v,st,p-1);
     qsor(v,p+1,dr);
    }
}


int main()
{FILE *fpi=fopen("p1.in","r");
 FILE *fpo=fopen("p1.out","w");
 int i,n,j;
 printf("n=");
 scanf("%d",&n);
 gennr(n);
 int *v=malloc(n*sizeof(int));
 int *poz=malloc(n*sizeof(int));
 for (i=1;i<=n;i++)
    {
     fscanf(fpi,"%d",&v[i]);
     poz[i]=v[i];
    }
 qsor(v,1,n);
 for (i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        if(poz[j]==v[i])
            {
             fprintf(fpo,"%d v[%d]=%d\n",j,i,v[i]);
             poz[j]=0;
             j=n+1;
            }
 fclose(fpi);
 fclose(fpo);
 free(v);
 free(poz);
    return 0;
}
