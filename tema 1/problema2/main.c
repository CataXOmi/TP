#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

struct melodie
{
    int id;
    int timp;
};

void genper(int n)
{int i;
 FILE *fout=fopen("date.in","w");
 srand(time(NULL));
 for(i=0;i<n;i++)
    {long int r=rand()*rand();
     r=1+r%(10-1+1);
     fprintf(fout,"%ld\t",r);
     long int rp=rand()*rand();
     rp=0+rp%(59-0+1);
     fprintf(fout,"%ld\n",rp);
    }
 fclose(fout);
}

int comp(const void *a, const void *b)
{
 return (*(struct melodie*)a).timp - (*(struct melodie*)b).timp;
}

int main()
{int i,n,s,min,sec,tmpmel=0,k=0;
 printf ("Numarul melodiilor este : ");
 scanf("%d",&n);
 printf ("Durata spectacolului este : ");
 scanf("%d",&s);
 genper(n);
 struct melodie *mel;
 mel=(struct melodie*)malloc(n*sizeof(struct melodie));
 FILE *fin=fopen("date.in","r");
 FILE *fout=fopen("date.out","w");
 for(i=0;i<n;i++)
    {fscanf(fin,"%d %d", &min, &sec);
     mel[i].timp=min*60+sec;
     mel[i].id=i+1;
    }
 fclose(fin);
 for(i=0;i<n;i++)
    printf("%d\t%d\n", mel[i].id, mel[i].timp);
 qsort(mel,n,sizeof(struct melodie),comp);
 printf("\n");
 for(i=0;i<n;i++)
    printf("%d\t%d\n", mel[i].id, mel[i].timp);
 while(tmpmel<s)
    {tmpmel+=mel[k].timp;
     fprintf(fout,"%d\t%d\n", mel[k].id, mel[k].timp);
     k++;
    }
 fprintf(fout,"Sandel va canta %d melodii",k);
    return 0;
}
