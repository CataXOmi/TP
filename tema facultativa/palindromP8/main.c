#include <stdio.h>
#include <stdlib.h>

int inv(int n)
{int in;
 while(n!=0)
            {in=in*10+n%10;
             n=n/10;
            }
 return in;
}

int pali(int n,int in)
{if (n==0)
    return 1;
 if(n%10!=in%10)
        return 0;
 else
    return pali(n/10,in/10);
}
int main()
{int nr,aux;
 printf("Introduceti numarul : ");
 scanf("%d",&nr);
 aux=nr;
 if (pali(nr,inv(aux)))
    printf("\nNumarul dat este palindrom!!");
 else
    printf("\nNumarul dat nu este palindrom!!");
    return 0;
}
