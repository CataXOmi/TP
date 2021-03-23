#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

void gennr(int n)
{int i,a=-100000,b=100000;
 FILE *fp1=fopen("nrout1.txt","w");
 srand(time(NULL));
 for(i=0;i<n;i++)
    {long int r=rand()*rand();
     r=a+r%(b-a+1);
     fprintf(fp1,"%ld\n",r);
    }
 fclose(fp1);
}

void bubble(long int *v,int n)
{int i,gata,f;
 long int aux;
 f=n-1;
 do
    {gata=1;
     for(i=0;i<f;i++)
            if(v[i]>v[i+1])
                {gata=0;
                 aux=v[i];
                 v[i]=v[i+1];
                 v[i+1]=aux;
                }
     f--;
    }
 while (!gata);
}

int comp(void *a, void *b)
{return (*(long int*)a-*(long int*)b);

}

int main()
{int n,i;
 long int *v,*a;
 printf("n=");
 scanf("%d",&n);
 FILE *fp1=fopen("nrout1.txt","r");
 v=malloc(n*sizeof(long int));
 a=malloc(n*sizeof(long int));
 for (i=0;i<n;i++)
    fscanf(fp1,"%ld",&v[i]);
 for(i=0;i<n;i++)
    a[i]=v[i];
 double t=clock();
 bubble(a,n);
 t=clock()-t;
 printf ("\nTimp executare bubble : %lf",t/CLOCKS_PER_SEC);
 double q=clock();
 qsort(v,n,sizeof(long int),comp);
 q=clock()-q;
 printf ("\nTimp executare qsort : %lf",q/CLOCKS_PER_SEC);
 fclose(fp1);
    return 0;
}
