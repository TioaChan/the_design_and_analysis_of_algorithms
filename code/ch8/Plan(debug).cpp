#include <stdio.h>
#define MAXM 10				//����̵���
#define MAXN 10				//���Ͷ�������
//�����ʾ
int m=3,n=5;				//�̵���Ϊm,������Ϊn
int v[MAXM][MAXN]={{0,0,0,0,0,0},{0,3,7,9,12,13},
	{0,5,10,11,11,11},{0,4,6,11,12,12}}; //����v[0]��
//�������ʾ
int dp[MAXM][MAXN];
int pnum[MAXM][MAXN];

void Plan()							//�����ŷ���dp
{
	int maxf,maxj;
	for (int j=0;j<=n;j++)			//�ñ߽�����
		dp[m+1][j]=0;
	for (int i=m;i>=1;i--)			//���̵�3��1���д���
	{
		for (int s=1;s<=n;s++)		//���������������k���̵�
		{
			maxf=0;
			maxj=0;
			for (j=0;j<=s;j++)		//�̵�i���̵�m������s����
			{
				printf("s=%d,j=%d\n",s,j);
				printf("  v[%d][%d]+dp[%d][%d]=%d\n",i,j,i+1,s-j,v[i][j]+dp[i+1][s-j]);
				if ((v[i][j]+dp[i+1][s-j])>=maxf)
				{
					maxf=v[i][j]+dp[i+1][s-j];
					maxj=j;
				}
			}
			dp[i][s]=maxf;			//dp[i][s]��ʾ�����̵�i..m����������s������Ӯ��
			pnum[i][s]=maxj;		//pnum[i][s]��ʾdp[i][s]��Ӧ�̵�i�ķ�������

			printf("dp[%d][%d]=v[%d][%d]+",i,s,i,maxj);
			printf("dp[%d][%d]=%d+%d=%d  ",i+1,s-maxj,v[i][maxj],dp[i+1][s-maxj],dp[i][s]);
			printf("pnum[%d][%d]=%d\n",i,s,pnum[i][s]);
		}
	}
}
void dispPlan()					//������ŷ��䷽��
{
	int k,r,s;
	s=pnum[1][n];
	printf("s=%d\n",s);
	r=n-s;						//rΪ���µ�����
	printf("������Դ���䷽������:\n");

	for (k=1;k<=m;k++)
	{
		printf("  %c�̵����%d��\n",'A'+k-1,s);
		s=pnum[k+1][r];			//����һ���׶η��������
		r=r-s;					//���������ݼ�
	}
	printf("�÷��䷽������Ӯ��Ϊ%d��Ԫ\n",dp[1][n]);
}
void main()
{
	Plan();
	printf("�����\n");

	printf("dp:\n");
	for (int i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%2d ",dp[i][j]);
		printf("\n");
	}
	printf("pnum:\n");
	for (i=1;i<=m;i++)
	{
		for (int j=1;j<=n;j++)
			printf("%2d ",pnum[i][j]);
		printf("\n");
	}
	dispPlan();
}
