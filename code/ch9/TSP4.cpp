//��֦�޽編���TSP����
#include "Graph.cpp"
#pragma warning( disable:4786)
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
//�����ʾ
int s;										//ָ�����
MGraph g;									//ͼ���ڽӾ���
//�����̱�ʾ
int Count=1;								//·�������ۼ�
vector<int> minpath;						//�������·��
int minpathlen=INF;							//�������·������
struct NodeType								//���н������
{
	int v;									//��ǰ����
	int num;								//·���еĽ�����
	vector<int> path;						//��ǰ·��
	int pathlen;							//��ǰ·������
	int visited[MAXV];						//������ʱ��
	bool operator<(const NodeType &s) const
	{
		return pathlen>s.pathlen;			//pathlenԽСԽ���ȳ���
	}
};
void dispasolution(vector<int> path,int pathlen)	//���һ����
{
	printf("    ��%d��·��: ",Count++);
	for (int i=0;i<path.size();i++)
		printf("%2d",path[i]);
	printf(", ·������: %d\n",pathlen);
}
void TSP()		//��֦�޽編�����Ϊs��TSP����
{
	NodeType e,e1;
	priority_queue<NodeType> qu;	//�������ȶ���qu
	e.v=0;							//�������s��Ӧ�Ľ��e
	e.pathlen=0;
	e.path.push_back(0);
	e.num=1;
	memset(e.visited,0,sizeof(e.visited));
	e.visited[0]=1;
	qu.push(e);						//�����e����
	while (!qu.empty())				//�Ӳ���ѭ��
	{
		e=qu.top(); qu.pop();		//���ӽ��e
		if (e.num==g.n)				//����Ҷ�ӽ��
		{
			if (g.edges[e.v][s]!=0 && g.edges[e.v][s]!=INF)	//e.v�����s�б�
			{
				e.path.push_back(s);				//·���м������s
				e.pathlen+=g.edges[e.v][s];			//�����e.v�����s��·������
				dispasolution(e.path,e.pathlen);
				if (e.pathlen<minpathlen)			//�Ƚ������·��
				{
					minpathlen=e.pathlen;
					minpath=e.path;
				}
			}
		}
		else										//��Ҷ�ӽ��
		{
			for (int j=1;j<g.n;j++)					//j�Ӷ���1��n-1ѭ��
			{
				if (g.edges[e.v][j]!=0 && g.edges[e.v][j]!=INF)	//��ǰ���㵽����j�б�
				{
					if (e.visited[j]==1) 			//����·�����ظ��Ķ���j
						continue;
					e1.v=j;						//����e.v�����ڶ���j��Ӧ�Ľ��e1
					e1.num=e.num+1;
					e1.path=e.path;
					e1.path.push_back(j);		//path��Ӷ���j
					e1.pathlen=e.pathlen+g.edges[e.v][j];
					for (int i=0;i<g.n;i++)		//����visited
						e1.visited[i]=e.visited[i];
					if (e1.pathlen<minpathlen)	//��֦
					{
						e1.visited[j]=1;
						qu.push(e1);
					}
				}
			}
		}
	}
}
void main()
{
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},	{6,0,8,5}, {8,9,0,5}, {7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���g
	s=0;
	printf("�����\n");
	TSP();
	printf("  ���·��:    ");
	for (int i=0;i<minpath.size();i++)
		printf("%2d",minpath[i]);
	printf(", ·������: %d\n",minpathlen);
}
