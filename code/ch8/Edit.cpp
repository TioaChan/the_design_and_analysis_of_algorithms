#include<stdio.h>
#include<string>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define MAX 201
#define min(x,y) ((x)<(y)?(x):(y))
//�����ʾ
string a="sfdqxbw";
string b="gfdgw";
//�������ʾ
int dp[MAX][MAX];
void solve()					//��dp
{
	int i,j;
	for (i=1;i<=a.length();i++) 
		dp[i][0]=i;			//��a��i���ַ�ȫ��ɾ��ת��Ϊb
	for (j=1; j<=b.length(); j++)
		dp[0][j]=j;			//��a�в���b��ȫ���ַ�ת��Ϊb
	for (i=1; i<=a.length(); i++)
       	for (j=1; j<=b.length(); j++)
		{
			if (a[i-1]==b[j-1])
				dp[i][j]=dp[i-1][j-1];
			else
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
		}
}
void main()
{
	solve();
	printf("�����\n");
	printf("    ���ٵ��ַ���������: %d\n",dp[a.length()][b.length()]);
}
