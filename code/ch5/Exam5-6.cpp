//��5.6���㷨
#include "Graph.cpp"
#include <vector>
using namespace std;
int visited[MAXV];						//ȫ�ֱ���
void dispapath(vector<int> path)		//���һ��·��
{
	printf("  ");
	for (int i=0;i<path.size();i++)
		printf("%d  ",path[i]);
	printf("\n");
}
void dfs(ALGraph *G,int u,int v,vector<int> path)	//���u��v��ȫ��·��
{
	ArcNode *p;
	path.push_back(u);				//·������d��1������u���뵽·����
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v && path.size()>=1)		//�ҵ�һ��·�������
		dispapath(path);
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	int w=p->adjvex;			//wΪ����u�����ڵ�
		if (visited[w]==0)			//��w����δ����,�ݹ������
			dfs(G,w,v,path);
		p=p->nextarc;				//pָ�򶥵�u����һ�����ڵ�
	}
	visited[u]=0;					//����
}
void main()
{
	ALGraph *G;
	int A[][MAXV]={				//���̡̳���ͼ4.11������ͼ
		{0,1,0,0,1},
		{0,0,1,1,1},
		{0,0,0,0,0},
		{0,0,1,0,1},
		{0,0,0,0,0}};
	int n=5,e=7;
	CreateAdj(G,A,n,e);			//����ͼ���ڽӱ�洢�ṹG
	vector<int> path,apath;
	int u=0,v=2;
	printf("�Ӷ���%d��%d��ȫ��·��\n",u,v),
	memset(visited,0,sizeof(visited));
	dfs(G,u,v,path);
	DestroyAdj(G);				//����ͼG
}
