#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b)
{
    if(a==b)
        return a;
    else
        if(a>b)
            return cmmdc(a-b,b);
        else
            return cmmdc(a,b-a);
}

int main()
{int a,b;
 printf("Introduceti numerele pentru care doriti sa calculati cel mai mare divizor comun: ");
 scanf("%d %d",&a,&b);
 printf("Cel mai mare divizor comun al numerelor date este: %d",cmmdc(a,b));

    return 0;
}
