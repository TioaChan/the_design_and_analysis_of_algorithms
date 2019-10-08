//��̬�滮���TSP����
#include "Graph.cpp"
#include <stdio.h>
#include <string.h>
#include <set>
#include <vector>
using namespace std;
#define MAX 11								//�������n��Ӧ����������λ��
#define min(x,y) ((x)<(y)?(x):(y))
typedef set< int > SET;						//����set<int>��ʾ���㼯��
//�����ʾ
int s=0;									//ָ�����Ϊ0
MGraph g;									//ͼ���ڽӾ���
//�������ʾ
int dp[1<<MAX][MAX];
int minpathlen;								//������·������
vector<int> minpath;						//������·��(����)
void solve()								//��TSP����
{
	int n=g.n-1;							//nΪ���������1���������0��
	memset(dp,0,sizeof(dp));				//dpԪ�س�ʼ��Ϊ0
	for(int V=0; V<=(1<<n)-1; V++)
	{
		for(int i=1; i<=n; i++)				//�ȶ�1~n�Ķ���ö��
			if(V & (1<<(i-1)))				//����i�ڼ���V�е����
			{
				if(V==(1<<(i-1)))			//���V={i}
					dp[V][i]=g.edges[0][i];
				else
				{
					dp[V][i]=INF;
					for(int j=1; j<=n; j++)
						if(V & (1<<(j-1)) && i!=j)	//ö��V�ж���i�����������j
							dp[V][i]=min(dp[V][i],dp[V^(1<<(i-1))][j]+g.edges[j][i]);
               	}
           	}
	}
}
void BuildPath()				//�������·��
{
	minpathlen=INF;
	int n=g.n-1;
	int V=(1<<n)-1,minj;
	for(int j=1; j<=n; j++)		//�����·������
	{
		if (minpathlen>dp[V][j]+g.edges[j][0])
		{
			minpathlen=dp[V][j]+g.edges[j][0];
			minj=j;
		}
	}
	while (V!=0)					//�����·��
	{
		minpath.push_back(minj);
		V=(V^(1<<(minj-1)));		//��V��ɾ������minj
		int mindp=INF;
		for (int i=1;i<=n;i++)		//����dp[V][*]�в�Ϊ0����Сdp[V][minj]
		{
			if (dp[V][i]!=0 && dp[V][i]<mindp)
			{
				mindp=dp[V][i];
				minj=i;
			}
		}
	}
}
void main()
{
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,6},{6,0,8,5},{8,9,0,5},{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���g
	solve();
	BuildPath();
	printf("�����\n");
	printf("    ���·������: %d\n",minpathlen);
	printf("    ���·��: 0��");
	for (int i=minpath.size()-1;i>=0;i--)
		printf("%d��",minpath[i]);
	printf("0\n");
}
