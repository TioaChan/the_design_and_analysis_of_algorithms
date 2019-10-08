#include <stdio.h>
#define MAXM 10				//����̵���
#define MAXN 10				//�������
//�����ʾ
int m=3,n=5;				//�̵���Ϊm,������Ϊn
int v[MAXM][MAXN]={{0,0,0,0,0,0},{0,3,7,9,12,13},
	{0,5,10,11,11,11},{0,4,6,11,12,12}}; //����v[0]��
//�������ʾ
int dp[MAXM][MAXN];
int pnum[MAXM][MAXN];

void Plan()								//�����ŷ���dp
{
	int maxf,maxj;
	for (int j=0;j<=n;j++)				//�ñ߽�����
		dp[m+1][j]=0;
	for (int i=m;i>=1;i--)				//i���̵�3��1���д���
	{
		for (int s=1;s<=n;s++)			//�̵�i���̵�m������s����
		{
			maxf=0;
			maxj=0;
			for (j=0;j<=s;j++)			//�Ҹ��̵��������maxf�ͷ�������maxj
			{
				if ((v[i][j]+dp[i+1][s-j])>=maxf)
				{
					maxf=v[i][j]+dp[i+1][s-j];
					maxj=j;
				}
			}
			dp[i][s]=maxf;
			pnum[i][s]=maxj;
		}
	}
}
void dispPlan()					//������ŷ��䷽��
{
	int k,r,s;
	s=pnum[1][n];
	r=n-s;						//rΪ���µ�����
	printf("������Դ���䷽������:\n");
	for (k=1;k<=m;k++)
	{
		printf("  %c�̵����%d��\n",'A'+k-1,s);
		s=pnum[k+1][r];			//����һ���׶η��������
		r=r-s;					//���������ݼ�
	}
	printf("  �÷��䷽������Ӯ��Ϊ%d��Ԫ\n",dp[1][n]);
}
void main()
{
	Plan();
	dispPlan();
}
