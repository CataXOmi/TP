#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int lit(char *a, char b)
{char *pr;
 if((strcmp(a,"")==0))
    return 1;
 pr=strchr(a,b);
 if (pr==0)
        return 0;
 strcpy(a,a+1);
 strcpy(pr,pr+1);
 return 1 + lit(a,b);
}
int main()
{char s[100],b;
 printf("Introduceti sirul dorit: ");
 gets(s);
 printf("\nIntroduceti litera pe care doriti s-o cautati : ");
 scanf("%c",&b);
 printf("\nLitera data s-a gasit in sir de %d ori .",lit(s,b));
    return 0;
}
