#include <stdio.h>
#include <stdlib.h>

void pd(int **a,int **c,int n)
{int i,j;
 for (i=2;i<=n;i++)
    for (j=1;j<=n;j++)
        if(a[i][j]==0)
            c[i][j]=c[i-1][j];
        else
            if (c[i-1][j-1]>c[i-1][j+1])
                    c[i][j]=c[i-1][j-1]+1;
            else
                    c[i][j]=c[i-1][j+1]+1;
}

void drum(int **a,int **c,int i,int j,FILE *fp)
{if(i==1)
    fprintf(fp,"%d %d\n",i,j);
 else
        {if(a[i][j]==0)
            drum(a,c,i-1,j,fp);
         else
            {if(c[i-1][j-1]+1==c[i][j])
                drum(a,c,i-1,j-1,fp);
             else
                drum(a,c,i-1,j+1,fp);
            }
         fprintf(fp,"%d %d\n",i,j);
        }
}

void afis(int **a,int **c,FILE *fp,int n)
{int j,maxim=0,jm;
 for(j=1;j<=n;j++)
        if(c[n][j]>maxim)
            {maxim=c[n][j];
             jm=j;
            }
 fprintf(fp,"%d\n",maxim);
 drum(a,c,n,jm,fp);
}

int main()
{FILE *fin=fopen("p_2.in","r");
 FILE *fout=fopen("p_2.out","w");
 int n,i,j;
 fscanf(fin,"%d",&n);
 int **a=(int**)malloc(n*sizeof(int*));
 for (i=1;i<=n;i++)
    {
     a[i]=(int*)malloc(n*sizeof(int));
    }
 for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
        fscanf(fin,"%d",&a[i][j]);
  int **c=(int**)calloc(n,sizeof(int*));
    for (i=1;i<=n;i++)
    {
        c[i]=(int*)calloc(n,sizeof(int));
    }
 pd(a,c,n);
 afis(a,c,fout,n);
 free(a);
 free(c);
 fclose(fin);
 fclose(fout);
 return 0;
}
