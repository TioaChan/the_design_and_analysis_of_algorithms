#include <stdio.h>
#include <string>
using namespace std;
#define MAXM 51
#define MAXN 51
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
string s="abcde";
string t="abgde";
//�������ʾ
int dp[MAXM][MAXN];
int Maxlength(string s,string t)	//��s��t������������Ӵ��ĳ���
{	int ans=0;
	int i,j;
	int n=s.length();
	int m=t.length();
	memset(dp,0,sizeof(dp));		//��ʼ������dp
	for(i=0; i<n; i++)				//��ʼ��dp��һ��
		if(s[i]==t[0])
			dp[i][0]=1;
    for(j=0; j<m; j++)				//��ʼ��dp��һ��
		if(s[0]==t[j])
			dp[0][j]=1;
	for(i=1; i<n; i++)				//����״̬ת�Ʒ�����dp������Ԫ��
		for(j=1; j<m; j++)
		{	if (s[i]==t[j])
				dp[i][j]=dp[i-1][j-1]+1;
			ans=max(ans,dp[i][j]);
		}
	return ans;
}
void main()
{
	printf("�����\n");
	printf("   ��Ĺ��������Ӵ�: %d\n",Maxlength(s,t));	//�����2
}
