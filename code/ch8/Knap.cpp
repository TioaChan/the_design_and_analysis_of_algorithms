//���0/1����������㷨
#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20					//�����Ʒ��
#define MAXW 100				//�����������
//�����ʾ
int n=5,W=10;					//5����Ʒ,��������������10
int w[MAXN]={0,2,2,6,5,4};		//�±�0����
int v[MAXN]={0,6,3,5,4,6};		//�±�0����
//�������ʾ
int dp[MAXN][MAXW];
int x[MAXN];
int maxv; 						//������Ž���ܼ�ֵ

void Knap()						//��̬�滮����0/1��������
{
	int i,r;
	for (i=0;i<=n;i++)			//�ñ߽�����dp[i][0]=0
		dp[i][0]=0;
	for (r=0;r<=W;r++)			//�ñ߽�����dp[0][r]=0
		dp[0][r]=0;
	for (i=1;i<=n;i++)
	{	for (r=1;r<=W;r++)
			if (r<w[i])
				dp[i][r]=dp[i-1][r];
			else
				dp[i][r]=max(dp[i-1][r],dp[i-1][r-w[i]]+v[i]);
	}
}
void Buildx()					//���������Ž�
{
	int i=n,r=W;
	maxv=0;
	while (i>=0)				//�ж�ÿ����Ʒ
	{
		if (dp[i][r]!=dp[i-1][r]) 
		{
			x[i]=1;				//ѡȡ��Ʒi
			maxv+=v[i];			//�ۼ��ܼ�ֵ
			r=r-w[i];
		}
		else
			x[i]=0;				//��ѡȡ��Ʒi
		i--;
	}
}
void main()
{
	Knap();
	Buildx();
	printf("�����(���ŷ���)\n");		//������
	printf("    ѡȡ����Ʒ: ");
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("%d ",i);
	printf("\n");
	printf("    �ܼ�ֵ=%d\n",maxv);
}
