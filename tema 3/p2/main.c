#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void gennr(int n)
{int i,a=1,b=n,c=0,d=n/2;
 FILE *fpi=fopen("p2.in","w");
 srand(time(NULL));
 int r=rand()*rand();
 r=c+r%(d-c+1);
 for(i=0;i<n;i++)
    {int r=rand()*rand();
     r=a+r%(b-a+1);
     fprintf(fpi,"%d\n",r);
    }
 fclose(fpi);
}

void inter(int *v,int st,int mij,int dr,int n)
{int i=st,j=mij+1,k=0,l,a;
 int *w=malloc(n*sizeof(int));
 while(i<=mij && j<=dr)
    if(v[i]<=v[j])
        w[k++]=v[i++];
    else
        w[k++]=v[j++];
 for(l=i;l<=mij;l++)
    w[k++]=v[l];
 for(l=j;l<=dr;l++)
    w[k++]=v[l];
 for(a=st;a<=dr;a++)
    v[a]=w[a-st];
}

void mergesort(int *v,int st,int dr,int n)
{int mij;
 if(st<dr)
    {mij=st+(dr-st)/2;
     mergesort(v,st,mij,n);
     mergesort(v,mij+1,dr,n);
     inter(v,st,mij,dr,n);
    }

}

int main()
{FILE *fpi=fopen("p2.in","r");
 FILE *fpo=fopen("p2.out","w");
 int i,n,k;
 printf("n=");
 scanf("%d",&n);
 gennr(n);
 int *v=malloc(n*sizeof(int));
 fscanf(fpi,"%d",&k);
 for (i=1;i<n;i++)
    {
     fscanf(fpi,"%d",&v[i]);
    }
 mergesort(v,1,k,k);
 for (i=1;i<n;i++)
    {
     fprintf(fpo,"v[%d]=%d\n",i,v[i]);
    }
 free(v);
 fclose(fpi);
 fclose(fpo);
    return 0;
}
