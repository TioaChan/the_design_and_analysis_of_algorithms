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
int dp[MAXN][MAXA][MAXB];
void solve()
{
	int k,A,B,m;
	memset(dp,0,sizeof(dp));		//��ʼ��Ϊ0
	for (A=0;A<=maxA;A++)
		for (B=0;B<=maxB;B++)
			dp[0][A][B]=1;			//k=0һ���н�

	for(k=1;k<=n;k++)
		for(A=0;A<=maxA;A++)
		{
			for(int B=0;B<=maxB;B++)
			{
				if (A-a[k-1]>=0)
					dp[k][A][B]=dp[k-1][A-a[k-1]][B];	//�ڻ���A������
				if (B-b[k-1]>=0)
					dp[k][A][B]=(dp[k][A][B]			//�ڻ���B������
						|| dp[k-1][A][B-b[k-1]]);
			}
		}
	for(A=0;A<=maxA;A++)			//������ʱ��
		for(int B=0;B<=maxB;B++)
			if (dp[n][A][B])
				{
					m=max(A,B);
					ans=min(ans,m);
				}
} 
int main()
{
	maxA=0; maxB=0;
	for (int i=0;i<n;i++)
	{
		maxA+=a[i];
		maxB+=b[i];
	}
	solve();
	printf("%d\n",ans);
	return 0;
}
