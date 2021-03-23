#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int litm(char *a,int n)
{if(n==-1)
    return 0;
 else
    if(a[n]>='a' && a[n]<='z')
          return  1+litm(a,n-1);
    else
        return litm(a,n-1);
}

int main()
{char s[100];
 int n;
 printf("Introduceti sirul dorit: ");
 gets(s);
 n=strlen(s)-1;
 printf("\nNumarul de litere mici din sirul dat este : %d",litm(s,n));
    return 0;
}
