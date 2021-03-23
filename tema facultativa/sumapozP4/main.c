#include <stdio.h>
#include <stdlib.h>

int suma(int *v,int s,int n)
{if(n==-1)
    return s;
 else
    if(v[n]>0)
        suma(v,s+v[n],n-1);
    else
        suma(v,s,n-1);
}

int main()
{int *v,n,i;
 printf("Numarul de elemente n al vectorului este : ");
 scanf("%d",&n);
 v=malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    scanf("%d",&v[i]);
 printf("Suma elementelor stric pozitive din vectorul dat este : %d", suma(v,0,n-1));

    return 0;
}
