#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int cmmdc(int u,int v)
{if(u==v)
    return u;
 else
    if(u>v)
        return cmmdc(u-v,v);
    else
        return cmmdc(u,v-u);
}

int dei(int *v,int st,int dr)
{
    int mij,cs,cd;
    if(abs(st-dr)<=1)
        return cmmdc(v[st],v[dr]);
    else
        {mij=st+(dr-st)/2;
         cs=dei(v,st,mij);
         cd=dei(v,mij+1,dr);
         return cmmdc(cs,cd);
        }
}

int main()
{FILE *fpi=fopen("p4.in","r");
 FILE *fpo=fopen("p4.out","w");
 int i,n;
 printf("n=");
 scanf("%d",&n);
 int *v=malloc(n*sizeof(int));
 for (i=1;i<=n;i++)
    {
     fscanf(fpi,"%d",&v[i]);
    }
 fprintf(fpo,"Cel mai mare divizor comun al elementelor date este: %d",dei(v,1,n));
 free(v);
 fclose(fpi);
 fclose(fpo);
    return 0;
}
