#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int nrpr(int v)
{int i,ok=1;
 for(i=2;i<=v/2;i++)
    {
     if(v%i==0)
            ok=0;
    }
 return ok;
}

void gennr(int n)
{int i,a=1,b=n;
 FILE *fpi=fopen("p4.in","w");
 srand(time(NULL));
 for(i=0;i<n;i++)
    {int r=rand()*rand();
     r=a+r%(b-a+1);
     fprintf(fpi,"%d\n",r);
    }
 fclose(fpi);
}

int cmmdc(int *v,int st,int dr)
{if(st==dr)
    return v[st];
 int mij,cs,cd,r;
 mij=st+(dr-st)/2;
 cs=cmmdc(v,st,mij);
 cd=cmmdc(v,mij+1,dr);
 while(cd!=0)
    {r=cs%cd;
     cs=cd;
     cd=r;
    }
 return cs;
}

int main()
{FILE *fpi=fopen("p4.in","r");
 FILE *fpo=fopen("p4.out","w");
 int i,n,k=0;
 printf("n=");
 scanf("%d",&n);
 gennr(n);
 int *v=malloc(n*sizeof(int));
 for (i=1;i<=n;i++)
    {
     fscanf(fpi,"%d",&v[i]);
    }
 for(i=1;i<=n;i++)
    if(nrpr(v[i]))
        k++;
 for(i=1;i<=n;i++)
    {if(v[i]==1)
        {fprintf(fpo,"Cel mai mare divizor comun al elementelor date este: %d",1);
         break;
        }
     else
        if(k>=2)
             {fprintf(fpo,"Cel mai mare divizor comun al elementelor date este: %d",1);
              break;
             }
        else
            {
                fprintf(fpo,"Cel mai mare divizor comun al elementelor date este: %d",cmmdc(v,1,n));
            }
    }
 free(v);
 fclose(fpi);
 fclose(fpo);
    return 0;
}
