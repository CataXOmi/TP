#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

struct proiect
{
    int zile, punctaj;
};

void genper(int n)
{int i;
 FILE *fout=fopen("date.in","w");
 srand(time(NULL));
 for(i=0;i<n;i++)
    {long int r=rand()*rand();
     r=1+r%(11-1+1);
     fprintf(fout,"%ld\t",r);
     long int rp=rand()*rand();
     rp=2+rp%(10-2+1);
     fprintf(fout,"%ld\n",rp);
    }
 fclose(fout);
}

int comp(const void *a, const void *b)
{
 return (*(struct proiect*)b).punctaj - (*(struct proiect*)a).punctaj;
}

int main()
{int i,n;
 printf ("Numarul proiectelor este : ");
 scanf("%d",&n);
 genper(n);
 struct proiect *proj;
 proj=(struct proiect*)malloc(n*sizeof(struct proiect));
 FILE *fin=fopen("date.in","r");
 FILE *fout=fopen("date.out","w");
 for(i=0;i<n;i++)
    fscanf(fin,"%d %d", &proj[i].zile, &proj[i].punctaj);
 fclose(fin);
 for(i=0;i<n;i++)
    printf("%d\t%d\n", proj[i].zile, proj[i].punctaj);
 qsort(proj,n,sizeof(struct proiect),comp);
 printf("\n");
 for(i=0;i<n;i++)
    printf("%d\t%d\n", proj[i].zile, proj[i].punctaj);
 int zi[6];
 for (i=0;i<6;i++)
    zi[i]=0;
 for(i=0;i<n;i++)
    {
        int nrz=5;
        while(nrz)
        {
            if (zi[nrz]==0 && nrz<=proj[i].zile)// cele care au punctaj mare si zilele mai mari sau egale cu 5 vor fi puse pe ultimele pozitiii
            {
                zi[nrz]=proj[i].punctaj;
                break;
            }
            nrz--;
        }
    }
    int sum=0;
    for (i=1;i<=5;i++)
    {
        sum=sum+zi[i];
    }
    fprintf(fout,"%d = ",sum);
    for (i=1;i<5;i++)
        fprintf(fout,"%d + ",zi[i]);
    fprintf(fout,"%d",zi[5]);
    fclose(fout);
    free(proj);

    return 0;
}
