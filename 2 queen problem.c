#include<stdio.h>
#include<stdlib.h>
//void assign(int **,int);
void assign(int **a,int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		a[i][j]=1;
	}
}
int main()
{
	int *a[3],*b,i,n=0,j,k=0,m=0,x,y;
	for(i=0;i<3;i++)
		a[i]=(int *)calloc(3,sizeof(int));
	//b=(int *)malloc(3*sizeof(int));
	assign(a,3);
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
			{
				a[i][k]=0;
				a[k][j]=0;
			}
			k=i;n=j;x=i;y=j;
			while(k!=-1&&n!=-1 || x!=-1&&y!=3)
			{
				a[k][n]=0;
				k--;
				n--;
				a[x][y]=0;
				x--;
				y++;
			}
			k=i;n=j;x=i;y=j;
			while(k!=3&&n!=3 || x!=3&&y!=-1)
			{
				a[k][n]=0;
				k++;
				n++;
				a[x][y]=0;
				x++;
				y--;
			}
			for(k=0;k<3;k++)
			{
				for(n=0;n<3;n++)
				{
					if(a[k][n]==1)
					{
						printf("When the 1st queen is at (%d,%d)",i+1,j+1);
						printf("the next queen is at (%d,%d)\n\n",k+1,n+1);
						m=1;
					}
				}
			}
			assign(a,3);
		}
	}
	return 0;	
}
