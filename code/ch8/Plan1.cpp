//�ӽ׶�1->m���о���
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
	for (int j=0;j<=n;j++)				//�ñ߽�����
		dp[0][j]=0;
	for (int i=1;i<=m;i++)			//���̵�3��1���д���
	{
		for (int s=1;s<=n;s++)		//�̵�1���̵�i������s����
		{
			maxf=0;
			maxj=0;
			for (j=0;j<=s;j++)		//�Ҹ��̵����ŷ�������j
			{
				if ((v[i][j]+dp[i-1][s-j])>=maxf)
				{
					maxf=v[i][j]+dp[i-1][s-j];
					maxj=j;
				}
			}
			dp[i][s]=maxf;			//dp[i][s]��ʾ�����̵�i..m����������s������Ӯ��
			pnum[i][s]=maxj;		//pnum[i][s]��ʾdp[i][s]��Ӧ�̵�i�ķ�������
		}
	}
}
void dispPlan()					//������ŷ��䷽��
{
	int k,r,s;
	s=pnum[m][n];
	r=n-s;						//rΪ���µ�����
	printf("������Դ���䷽������:\n");

	for (k=m;k>=1;k--)			//��m��1
	{
		printf("  %c�̵����%d��\n",'A'+k-1,s);
		s=pnum[k-1][r];			//����һ���׶η��������
		r=r-s;					//���������ݼ�
	}
	printf("  �÷��䷽������Ӯ��Ϊ%d��Ԫ\n",dp[m][n]);
}
void main()
{
	Plan();
	dispPlan();
}
