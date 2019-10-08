//ͼ����ȱ����㷨
#include "Graph.cpp"
#include <string.h>
int visited[MAXV];
void DFS(MGraph g,int v)
{	int w;
	printf("%3d",v);					//��������ʶ���ı��
	visited[v]=1;						//���ѷ��ʱ��
	for (w=0;w<g.n;w++)					//�Ҷ���v���������ڵ�
		if (g.edges[v][w]!=0 && g.edges[v][w]!=INF && visited[w]==0)
			DFS(g,w);					//�Ҷ���v��δ���ʹ������ڵ�w
}
void DFS(ALGraph *G,int v)
{	ArcNode *p;
	printf("%3d",v);					//��������ʶ���ı��
	visited[v]=1;						//���ѷ��ʱ��
	p=G->adjlist[v].firstarc;			//pָ�򶥵�v�ĵ�һ���ڽӵ�
	while (p!=NULL)
	{	if (visited[p->adjvex]==0)		//��p->adjvex����δ����,�ݹ������
			DFS(G,p->adjvex);
		p=p->nextarc;					//pָ�򶥵�v����һ���ڽӵ�
	}
}
void main()
{
	MGraph g;
	ALGraph *G;
	int A[][MAXV]={			//һ������ͼ
		{0,1,0,0,1},
		{0,0,1,1,1},
		{0,0,0,0,0},
		{0,0,1,0,1},
		{0,0,0,0,0}};
	int n=5,e=7;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	memset(visited,0,sizeof(visited));	//��ʼ��visited����
	printf("DFS:");
	DFS(g,0);printf("\n");
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	memset(visited,0,sizeof(visited));	//��ʼ��visited����
	printf("DFS:");
	DFS(G,0);printf("\n");
	DestroyAdj(G);
}
