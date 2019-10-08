//��֦�޽編���TSP����
#include "Graph.cpp"
#pragma warning( disable:4786)
#include <stdio.h>
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
	printf("    ·��: ");
	for (int i=0;i<path.size();i++)
		printf("%2d",path[i]);
	printf(", ·������: %d\n",pathlen);
}
void disp(NodeType e)	//���·�����䳤��
{
	printf("\te.v=%d, e.num=%d\n",e.v,e.num);
	printf("\tpath: ");
	for (int i=0;i<e.path.size();i++)
		printf("%2d",e.path[i]);
	printf(", pathlen=%d\n",e.pathlen);
	printf("\tvisited: ");
	for (int j=0;j<g.n;j++)
		printf("%2d",e.visited[j]);
	printf("\n");
}

void TSP()		//��֦�޽編�����Ϊs��TSP����
{
	NodeType e,e1;
	priority_queue<NodeType> qu;		//�������ȶ���qu
	e.v=0;							//�������0��Ӧ�Ľ��e
	e.pathlen=0;
	e.path.push_back(0);
	e.num=1;
	memset(e.visited,0,sizeof(e.visited));
	e.visited[0]=1;
	qu.push(e);						//�����e����
	while (!qu.empty())				//�Ӳ���ѭ��
	{
		e=qu.top(); qu.pop();		//���ӽ��e
		printf("(%d)����\n",Count++); disp(e);
		if (e.num==g.n)				//�ﵽҶ�ӽ��
		{
			if (g.edges[e.v][s]!=0 && g.edges[e.v][s]!=INF)	//e.v�����s�б�
			{
				e.path.push_back(s);				//·���м������s
				e.pathlen+=g.edges[e.v][s];			//�����e.v�����s��·������
				dispasolution(e.path,e.pathlen);
				if (e.pathlen<minpathlen)
				{
					minpathlen=e.pathlen;
					minpath=e.path;
				}
			}
		}
		else
		{
			for (int j=1;j<g.n;j++)					//j�Ӷ���1��n-1ѭ��
			{
				if (g.edges[e.v][j]!=0 && g.edges[e.v][j]!=INF)	//��ǰ���㵽����j�б�
				{
					if (e.visited[j]==0)			//����j��·����û���ظ�
					{
						e1.v=j;
						e1.num=e.num+1;
						e1.path=e.path;
						e1.path.push_back(j);
						e1.pathlen=e.pathlen+g.edges[e.v][j];
						for (int i=0;i<g.n;i++)
							e1.visited[i]=e.visited[i];
						if (e1.pathlen<minpathlen)	//��֦
						{
							e1.visited[j]=1;
							qu.push(e1);
							printf("  ����: ");disp(e1);
						}
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
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���洢�ṹg
	printf("�ڽӾ���:\n"); DispMat(g);	//����ڽӾ���g
	s=0;
	TSP();
	printf("���·�����䳤��:\n");
	dispasolution(minpath,minpathlen);
}
