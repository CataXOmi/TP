#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int maxim(int *v, int max, int n)
{if(n==-1)
    return max;
 else
    if(v[n]>max)
        maxim(v,v[n],n-1);
    else
        maxim(v,max,n-1);
}


int main()
{int *v,n,i;
 printf("Numarul de elemente n al vectorului este : ");
 scanf("%d",&n);
 v=malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    scanf("%d",&v[i]);
 printf("Maximul dintre elementele vectorului dat este : %d", maxim(v,INT_MIN,n-1));

    return 0;
}
