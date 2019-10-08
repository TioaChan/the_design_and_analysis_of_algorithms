#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
#define N 1050
#define INF 0x3f3f3f3f

//�����ʾ
int n,m;					//����Ķ�������ͱ���
struct Edge					//������
{
	int from,to;			//һ����(from,to)
	int flow;				//�ߵ�����
	int cap;				//�ߵ�����
	int cost;				//�ߵķ���
};
vector<Edge> edges;			//������������б�
vector<int> G[N];			//�ڽӱ�G[i][j]��ʾ����i�ĵ�j������edges�����е��±�
//�������ʾ
int maxf=0;					//�������������û��ʹ�ã�����˵������������Ĺ��̣�
int mincost=0;				//���������С����

bool visited[N];
int pre[N],a[N],dist[N];
void Init(int n)				//��ʼ��
{
	for (int i=0; i<=n; i++)	//ɾ�����������
		G[i].clear();		
	edges.clear();				//ɾ�����б�
}
void AddEdge(int from,int to,int cap,int cost)	//���һ����
{
	Edge temp1 = {from,to,0,cap,cost};	//ǰ��ߣ���ʼ����Ϊ0
	Edge temp2 = {to,from,0,0,-cost };	//����ߣ���ʼ����Ϊ0
	edges.push_back(temp1);				//���ǰ���
	G[from].push_back(edges.size()-1);	//ǰ��ߵ�λ��
	edges.push_back(temp2);				//��ӷ����
	G[to].push_back(edges.size()-1);	//����ߵ�λ��
}
bool SPFA(int s,int t)				//SPFA�㷨��cost��С��·��
{
	for (int i=0; i<N;i++)			//��ʼ��dist����
		dist[i]=INF;
	dist[s]=0;
	memset(visited,0,sizeof(visited));	
	memset(pre, -1, sizeof(pre));
	pre[s]=-1;							//��������ǰ��Ϊ-1
	queue<int> qu;						//����һ������
	qu.push(s);
	visited[s]=1;
	a[s]=INF;
	while (!qu.empty())					//���в���ѭ��
	{
		int u=qu.front(); qu.pop();
		visited[u]=0;
		for (int i=0; i<G[u].size();i++)				//���Ҷ���u�����й�����
		{
			Edge &e=edges[G[u][i]];						//������e=(u,G[u][i])
			if (e.cap>e.flow && dist[e.to]>dist[u]+e.cost)	//�ɳ�
			{
				dist[e.to]=dist[u]+e.cost;
				pre[e.to]=G[u][i];						//����e.to��ǰ������ΪG[u][i]
				a[e.to]=min(a[u], e.cap-e.flow);
				if (!visited[e.to])						//e.to���ڶ�����
				{
					qu.push(e.to);						//��e.to����
					visited[e.to]=1;
				}
			}
 		}
	}
	if (dist[t]==INF)					//�Ҳ��������յ㣬����false
		return false;
	maxf+=a[t];							//�ۼ��������
	mincost += dist[t]*a[t];			//�ۼ���С����
	for (int j=t; j!=s; j=edges[pre[j]].from)	//��������·������
	{
		edges[pre[j]].flow += a[t];		//ǰ�������a[t]
		edges[pre[j]+1].flow -= a[t];	//����߼���a[t]
	}
	return true;				//�ҵ������յ㣬����true
}
void MinCost(int s,int t)		//�����С����
{
	while (SPFA(s,t));			//SPFA�㷨���������
}

int main()
{
	n=4,m=5;
	Init(n+1);
	AddEdge(1,2,1,1); AddEdge(2,1,1,1);	//1 2 1������������ͼ��
	AddEdge(2,3,1,1); AddEdge(3,2,1,1);	//2 3 1
	AddEdge(3,4,1,1); AddEdge(4,3,1,1);	//3 4 1
	AddEdge(1,3,1,2); AddEdge(3,1,1,2);	//1 3 2
	AddEdge(2,4,1,2); AddEdge(4,2,1,2);	//2 4 2
	AddEdge(0,1,2,0);					//�������0����������1�ı���������Ϊ2
	AddEdge(n,n+1,2,0);					//����n�������յ�n+1�ı���������Ϊ2
	MinCost(0,n+1);
	cout << mincost << endl;			//���6
	return 0;
}
