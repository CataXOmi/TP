#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void gennr(int n)
{int a=0,b=n;
 FILE *fpi=fopen("p3.in","w");
 srand(time(NULL));
 int r=rand()*rand();
 r=a+r%(b-a+1);
 fprintf(fpi,"%d\n",r);
 fclose(fpi);
}

void dei(int k,int st,int dr,FILE *fp)
{int mij;
 if(st>dr)
         fprintf(fp,"%d ",dr);
 else
    {mij=st+(dr-st)/2;
     if(mij==k)
            fprintf(fp,"%d ",mij);
     else
        {fprintf(fp,"%d ",mij);
         if(mij<k)
            dei(k,mij+1,dr,fp);
         else
            dei(k,st,mij-1,fp);
        }
    }
}

int main()
{FILE *fpi=fopen("p3.in","r");
 FILE *fpo=fopen("p3.out","w");
 int n,k;
 printf("Numarul de etaje este n=");
 scanf("%d",&n);
 gennr(n);
 fscanf(fpi,"%d",&k);
 dei(k,0,n,fpo);
 fclose(fpi);
 fclose(fpo);
     return 0;
}
