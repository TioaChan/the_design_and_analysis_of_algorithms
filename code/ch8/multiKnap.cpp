//�����ȫ����������㷨
#include <stdio.h>
#include <string.h>
#define MAXN 20				//�����Ʒ��
#define MAXW 100			//�����������
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int n,W;
int w[MAXN],v[MAXN];
//�������ʾ
int dp[MAXN+1][MAXW+1],fk[MAXN+1][MAXW+1];
int solve()					//�����ر�������
{
	int i,j,k;
	for (i=1;i<=n;i++)
	{
		for (j=0;j<=W;j++)
			for (k=0;k*w[i]<=j;k++)
			{
				if (dp[i][j]<dp[i-1][j-k*w[i]]+k*v[i])
				{
					dp[i][j]=dp[i-1][j-k*w[i]]+k*v[i];
					fk[i][j]=k;		//��Ʒiȡk��
				}									
			}
	}
	return dp[n][W];
}
void Traceback()				//���������Ž�
{
	int i=n,j=W;
	while (i>=1)
	{
		printf("��Ʒ%d��%d�� ",i,fk[i][j]);
		j-=fk[i][j]*w[i];		//ʣ������
		i--;
	}
	printf("\n");
}
int solve1()						//��̬�滮������ȫ��������
{	int i,k,j;
	for (i=1;i<=n;i++)
		for (j=0;j<=W;j++)
			if (j<w[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-w[i]]+v[i]);
	return dp[n][W];		//�����ܼ�ֵ
}
void main()
{
	w[1]=3; w[2]=4; w[3]=2;
	v[1]=4; v[2]=5; v[3]=3;
	n=3; W=7;
	memset(dp,0,sizeof(dp));
	memset(fk,0,sizeof(fk));
	printf("���Ž�:\n");
	printf("  �ܼ�ֵ=%d\n",solve());
	printf("  ����: ");Traceback();
	printf("�ⷨ2\n");
	printf("  �ܼ�ֵ=%d\n",solve1());
}
