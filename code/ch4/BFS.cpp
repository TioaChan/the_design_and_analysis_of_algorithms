//ͼ�Ĺ�ȱ����㷨
#include "Graph.cpp"
#include <queue>
#include <string.h>
using namespace std;

void BFS(MGraph g,int v)					//�ڽӾ����DFS�㷨
{
	queue<int> qu;							//����һ������qu
	int visited[MAXV];						//�����Ž��ķ��ʱ�־������
	int w,i;
	memset(visited,0,sizeof(visited));		//���ʱ�־�����ʼ��

	printf("%3d",v);						//��������ʶ���ı��
	visited[v]=1;							//���ѷ��ʱ��
	qu.push(v);								//v����
	while (!qu.empty())						//���в���ʱѭ��
	{
		w=qu.front(); qu.pop();				//���Ӷ���w
		for (i=0;i<g.n;i++)					//���붥��w���ڵĶ���
			if (g.edges[w][i]!=0 && g.edges[w][i]!=INF && visited[i]==0)
			{	//����ǰ�ڽӶ���iδ������
				printf("%3d",i);			//�������ڶ���
				visited[i]=1;				//�øö����ѱ����ʵı�־
				qu.push(i);					//�ö������
			}
	}
	printf("\n");
}
void BFS(ALGraph *G,int v)					//�ڽӱ��DFS�㷨
{
	ArcNode *p;
	queue<int> qu;							//����һ������qu
	int visited[MAXV];						//�����Ŷ���ķ��ʱ�־������
	int w;
	memset(visited,0,sizeof(visited));		//���ʱ�־�����ʼ��
	printf("%3d",v);						//��������ʶ���ı��
	visited[v]=1; 							//���ѷ��ʱ��
	qu.push(v);								//v����
	while (!qu.empty())						//���в���ʱѭ��
	{
		w=qu.front(); qu.pop();				//���Ӷ���w
		p=G->adjlist[w].firstarc;			//�Ҷ���w�ĵ�һ���ڽӵ�
		while (p!=NULL) 
		{	if (visited[p->adjvex]==0)		//����ǰ�ڽӶ���δ������
			{	printf("%3d",p->adjvex);	//�������ڶ���
				visited[p->adjvex]=1;		//�øö����ѱ����ʵı�־
				qu.push(p->adjvex);			//�ö������
			}
			p=p->nextarc;					//�Ҷ���w����һ���ڽӵ�
		}
	}
	printf("\n");
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
	printf("BFS:");
	BFS(g,0);printf("\n");
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	printf("BFS:");
	BFS(G,0);printf("\n");
	DestroyAdj(G);
}
