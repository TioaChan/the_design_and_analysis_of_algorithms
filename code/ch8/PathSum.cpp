#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;
#define MAXN 100
//�����ʾ
int a[MAXN][MAXN];
int n;
//�������ʾ
int ans=0;
int dp[MAXN][MAXN];
int pre[MAXN][MAXN];
int Search()						//����С��·��ans
{	int i,j;
	dp[0][0]=a[0][0];
	for(i=1;i<n;i++)					//���ǵ�1�еı߽�
	{	dp[i][0]=dp[i-1][0]+a[i][0];
		pre[i][0]=i-1;
	}
	for (i=1;i<n;i++)					//���ǶԽ��ߵı߽�
	{	dp[i][i]=a[i][i]+dp[i-1][i-1];
		pre[i][i]=i-1;
	}
	for(i=2;i<n;i++)					//���������������ﵽ·���Ľ��
	{	for(j=1;j<i;j++)
		{	if(dp[i-1][j-1]<dp[i-1][j])
			{	pre[i][j]=j-1;
				dp[i][j]=a[i][j]+dp[i-1][j-1];
			}
			else
			{	pre[i][j]=j;
				dp[i][j]=a[i][j]+dp[i-1][j];
			}
		}
	}
	ans=dp[n-1][0];
	int k=0;
	for (j=1;j<n;j++)					//�����Сans�Ͷ�Ӧ���к�k
	{	if (ans>dp[n-1][j])
		{	ans=dp[n-1][j];
			k=j;
		}
	}
	return k;
}
void Disppath(int k)					//�����С��·��
{	int i=n-1;
	vector<int> path;					//�����·������path
	while (i>=0)					//�ӣ�n-1,k����㷴���������·��
	{	path.push_back(a[i][k]);
		k=pre[i][k];				//��С·����ǰһ���е��к�
		i--;						//��ǰһ�в���
	}
	vector<int>::reverse_iterator it;		//���巴�������
	for (it=path.rbegin();it!=path.rend();++it)
		printf("%d ",*it);			//���������������·��
	printf("\n");
}
int main()
{	int k;
	memset(pre,0,sizeof(pre));
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);				//���������εĸ߶�
	for (int i=0;i<n;i++)				//����������
		for (int j=0;j<=i;j++)
			scanf("%d",&a[i][j]);
	k=Search();					//����С·����
	Disppath(k);					//�������·��
	printf("%d\n",ans);				//�����С·����
	return 0;
}
