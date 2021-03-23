#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

struct restaurant
{
    int cod,nrport;
    int tmpprep,pret;
};

void genper(int n)
{int i;
 FILE *fout=fopen("comanda.in","w");
 srand(time(NULL));
 for(i=0;i<n;i++)
    {long int rc=rand()*rand();//cod
     rc=10000+rc%(99999-10000+1);
     fprintf(fout,"%ld\t",rc);

     long int rtmp1=rand()*rand();//timp
     rtmp1=5+rtmp1%(59-1+1);
     fprintf(fout,"%ld\t",rtmp1);
     long int rtmp2=rand()*rand();
     rtmp2=0+rtmp2%(59-0+1);
     fprintf(fout,"%ld\t",rtmp2);

     long int rpr=rand()*rand();//pret
     rpr=1+rpr%(1000-1+1);
     fprintf(fout,"%ld\t",rpr);

     long int rpo=rand()*rand();//portii
     rpo=1+rpo%(50-1+1);
     fprintf(fout,"%ld\n",rpo);
    }
 fclose(fout);
}

int comp(const void *a, const void *b)
{struct restaurant *va=(struct restaurant*)a;
 struct restaurant *vb=(struct restaurant*)b;
 return (double)vb->pret/vb->tmpprep - (double)va->pret/va->tmpprep;
}


int main()
{int n,tm,ts,min,sec,i,tmp2,com,tbuc,trm=0;
 printf("Numarul tipurilor de mancare este : ");
 scanf("%d",&n);
 printf("Timpul pe care il are bucatarul este : ");
 scanf("%d %d",&tm,&ts);
 genper(n);
 struct restaurant *men;
 men=(struct restaurant *)malloc(n*sizeof(struct restaurant));
 FILE *fin=fopen("comanda.in","r");
 FILE *fout=fopen("comanda.out","w");
 for(i=0;i<n;i++)
    {fscanf(fin,"%d",&men[i].cod);
     fscanf(fin,"%d %d", &min, &sec);
     men[i].tmpprep=min*60+sec;
     fscanf(fin,"%d %d", &men[i].pret, &men[i].nrport);
     if(men[i].nrport>1)
        men[i].pret=men[i].nrport*men[i].pret;
     tmp2=men[i].tmpprep;
     com=men[i].nrport;
     while(com!=1)
        {men[i].tmpprep=men[i].tmpprep+tmp2/2;
         com--;
        }
    }
 fclose(fin);
 for(i=0;i<n;i++)
    printf("%d\t%d\t%d\t%d\n", men[i].cod, men[i].tmpprep, men[i].pret, men[i].nrport);
 qsort(men,n,sizeof(struct restaurant),comp);
 printf("Dupa sortare : \n");
 for(i=0;i<n;i++)
    printf("%d\t%d\t%d\t%d\n", men[i].cod, men[i].tmpprep, men[i].pret, men[i].nrport);
 tbuc=tm*60+ts;
 int k=0;
 while(trm<=tbuc) // && k<n ??
    {trm+=men[k].tmpprep;
     fprintf(fout,"%d\t%d\t%d\t%d\n", men[k].cod, men[k].tmpprep, men[k].pret, men[k].nrport);
     k++;
    }

    return 0;
}
