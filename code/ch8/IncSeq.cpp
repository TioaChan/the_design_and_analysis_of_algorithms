#include <stdio.h>
#define MAX 100
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int a[]={2,1,5,3,6,4,8,9,7};
int n=sizeof(a)/sizeof(a[0]);
//�������ʾ
int ans=0;
int dp[MAX];
void solve(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		dp[i]=1;
		for(j=0;j<i;j++)
		{
			if (a[i]>a[j])
				dp[i]=max(dp[i],dp[j]+1);
		}
	}
	ans=dp[0];
	for(i=1;i<n;i++)
		ans=max(ans,dp[i]);
}
void main()
{
	solve(a,n);
	for (int i=0;i<n;i++)
		printf("dp[%d]=%d\n",i,dp[i]);
	printf("�����\n");
	printf("   ����������еĳ���: %d\n",ans);
}
