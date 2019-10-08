#include "Graph.cpp"					//����ͼ�Ļ��������㷨
#include <vector>
#include <string.h>
using namespace std;
//�����ʾ
MGraph g;								//ͼ���ڽӾ���
//�����̱�ʾ
MGraph tree;							//�����С������
int visited[MAXV];
vector<int> path;						//���TSP·��
void Prim(int v)						//������С������tree
{	int lowcost[MAXV];
	int mincost;
	int closest[MAXV],i,j,k;
	for (j=0;j<g.n;j++)				//����ʼ��lowcost��closest����
	{	lowcost[j]=g.edges[v][j];
		closest[j]=v;
	}
	for (i=1;i<g.n;i++)				//�ҳ�(n-1)������
	{	mincost=INF;
		for (j=0;j<g.n;j++)			//��(V-U)���ҳ���U����Ķ���k
			if (lowcost[j]!=0 && lowcost[j]<mincost)
			{	mincost=lowcost[j];
				k=j;					//k��¼�������ı��
			}
		tree.edges[closest[k]][k]=mincost;//������С��������һ�������
		tree.edges[k][closest[k]]=mincost;
		lowcost[k]=0;					//���k�Ѿ�����U
		for (j=0;j<g.n;j++)			//�޸�����lowcost��closest
			if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k;
			}
	}
}
void DFS(int v)						//DFS�㷨
{	path.push_back(v);					//�����ʶ�����ӵ�path��
	visited[v]=1;						//���ѷ��ʱ��
	for (int w=0;w<tree.n;w++)			//�Ҷ���v���������ڵ�
		if (tree.edges[v][w]!=0 && tree.edges[v][w]!=INF && visited[w]==0)
			DFS(w);					//�Ҷ���v��δ���ʹ������ڵ�w
}
void TSP(int v)						//TSP�㷨
{	tree.n=g.n;
	memset(tree.edges,INF,sizeof(tree.edges));
	Prim(v);
	memset(visited,0,sizeof(visited));
	DFS(v);
}
void ApproxTSP()						//���TSP����Ľ��ƽ�
{	vector<int> minpath;
	int minpathlen=INF;
	printf("�����\n");
	for (int v=0;v<g.n;v++)
	{	path.clear();
		TSP(v);
		printf("  �Ӷ���%d��������:\n\t·��: ",v);
		int pathlen=0;
		for (int i=0;i<path.size();i++)
		{	printf("%d��",path[i]);
			if (i!=path.size()-1)
				pathlen+=g.edges[path[i]][path[i+1]];
		}
		printf("��%d",v);
		pathlen+=g.edges[path[path.size()-1]][v];
		printf(", ����=%d\n",pathlen);
		if (pathlen>INF)
			printf("\t��·��������\n");
		else if (pathlen<minpathlen)
		{	minpathlen=pathlen;
			minpath=path;
		}
	}
	printf("  ���Ž��ƽ�\n\t·��: ");
	for (int i=0;i<minpath.size();i++)
		printf("%d��",minpath[i]);
	printf("��%d",minpath[0]);
	printf(", ����=%d\n",minpathlen);
}
void main()
{	int A[][MAXV]={					//һ����Ȩ����ͼ
		{0,1,5,2,INF}, {1,0,INF,6,3},
		{5,INF,0,4,3}, {2,6,4,0,2}, {INF,3,3,2,0}};
	int n=5,e=8;
	CreateMat(g,A,n,e);				//����ͼ���ڽӾ���g
	ApproxTSP();
}
