#include <stdio.h>
#define MAX 51
//�����ʾ
int n;
//�������ʾ
int dp[3];
int solve1()			//��������ⷨ
{
	dp[0]=1;
	dp[1]=2;
	for (int i=2; i<n; i++)
		dp[i%3]=dp[(i-1)%3]+dp[(i-2)%3];
	return dp[(n-1)%3];
}
/*
int fun(int n)			//�ݹ�ⷨ
{
	if (n==1)
		return 1;
	else if (n==2)
		return 2;
	else
		return fun(n-1)+fun(n-2);
}
int solve()				//���涯̬�滮�ⷨ
{
	dp[0]=1;
	dp[1]=2;
	for (int i=2;i<n;i++)
		dp[i]=dp[i-1]+dp[i-2];
	return dp[n-1];
}
*/
void main()
{
	n=10;
	//printf("%d\n",solve());
	printf("%d\n",solve1());	//���:89
	//printf("%d\n",fun(n));
}
