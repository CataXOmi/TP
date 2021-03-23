#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anagr(char *s, char *b)
{char *pr;
 if((strcmp(s,"")==0)&&(strcmp(b,"")==0))
    return 1;
 pr=strchr(s,b[0]);
 if (pr==0)
        return 0;
 strcpy(b,b+1);
 strcpy(pr,pr+1);
 return anagr(s,b);
}


int main()
{char s[100],b[100];
 int m,n;
 printf("Introduceti primul sir : ");
 scanf("%s",s);
 printf("\nIntroduceti al doilea sir : ");
 scanf("%s",b);
 m=strlen(b);
 n=strlen(s);
 if(n!=m)
    printf("\nSirurile date nu au aceeasi lungime, deci nu sunt anagrame!!");
 else
    if(anagr(s,b))
        printf("\nSirurile date sunt anagrame!!");
    else
        printf("\nSirurile date nu sunt anagrame!!");
    return 0;
}
