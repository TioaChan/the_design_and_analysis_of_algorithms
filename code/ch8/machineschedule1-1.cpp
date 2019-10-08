#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f						//���������
#define MAXN 51								//������ҵ��
#define MAXA MAXN*20
#define MAXB MAXN*20
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
//�����ʾ
int n=6;									//��ҵ��
int a[]={2,5,7,10,5,2};
int b[]={3,8,4,11,3,4};
//���ṹ��ʾ
int maxA,maxB;
int ans=INF;
int dp[2][MAXA][MAXB];						//��������
void solve()								//����㷨
{
	int k,A,B,m,c=0;
	for (A=0;A<=maxA;A++)
		for (B=0;B<=maxB;B++)
		{
			dp[1][A][B]=0;
			dp[0][A][B]=1;					//k=0һ���н�
		}
	for(k=1;k<=n;k++)
	{
		c=1-c;
		memset(dp[c],0,sizeof(dp[c]));		//��ʼ��dp[c]Ϊ0
		for(A=0;A<=maxA;A++)
			for(int B=0;B<=maxB;B++)
			{
				if (A-a[k-1]>=0)			//�ڻ���A������
					dp[c][A][B]=dp[1-c][A-a[k-1]][B];
				if (B-b[k-1]>=0)			//�ڻ���B������
					dp[c][A][B]=(dp[c][A][B]
						|| dp[1-c][A][B-b[k-1]]);
			}
	}
	for(A=0;A<=maxA;A++)
		for(int B=0;B<=maxB;B++)
			if (dp[c][A][B])
				{
					m=max(A,B);
					if (m<ans)
						ans=m;
				}
} 
int main()
{
	int i;
	maxA=0; maxB=0;
	for (i=0;i<n;i++)
	{ 
		maxA+=a[i];
		maxB+=b[i];
	}
	solve();
	printf("%d\n",ans);
	return 0;
}
