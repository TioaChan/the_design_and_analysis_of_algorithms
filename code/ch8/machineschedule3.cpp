#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f						//���������
#define MAXN 51								//������ҵ��
#define MAXA MAXN*20
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)<(y)?(x):(y))
//�����ʾ
int n=6;									//��ҵ��
int a[]={2,5,7,10,5,2};
int b[]={3,8,4,11,3,4};
//���ṹ��ʾ
int maxA;
int ans=INF;
int dp[MAXA];	
void solve()								//����㷨
{
	int k,A,m;
	memset(dp,0,sizeof(dp));				//��ʼ��Ϊ0
	for (k=1; k<=n; k++) 
	{
		for(A=maxA; A>=0; A--)
		{
			if(A<a[k-1])					//���ʱ��ֻ���ڻ���B������
				dp[A]=dp[A]+b[k-1];
			else							//����ȡ����A���߻���B�ϴ��������ʱ��
				dp[A]=min(dp[A-a[k-1]],dp[A]+b[k-1]);
		}
	}
	for(A=0; A<=maxA; A++)
	{
		m=max(A,dp[A]);
		ans=min(ans,m);
	}
} 
int main()
{
	maxA=0;
	for (int i=0;i<n;i++)
		maxA+=a[i];
	solve();
	printf("%d\n",ans);
	return 0;
}
