//��9.2���㷨
#include "Graph.cpp"
#include <string.h>
#include <vector>
using namespace std;
int visited[MAXV];
void FindaPath(ALGraph *G,int u,int v,vector<int> apath,vector<int> &path)
{
	int w;
	ArcNode *p;
	visited[u]=1;
	apath.push_back(u);			//����u���뵽apath·����
	if (u==v)					//�ҵ�һ��·��
	{
		path=apath;				//��apath���Ƶ�path
		return;					//����true
	}
	p=G->adjlist[u].firstarc;	//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{
		w=p->adjvex;			//���ڵ�ı��Ϊw
		if (visited[w]==0)
			FindaPath(G,w,v,apath,path);
		p=p->nextarc;			//pָ�򶥵�u����һ�����ڵ�
	}
}
void main()
{
	ALGraph *G;
	int A[][MAXV]={			//���̡̳���ͼ4.11������ͼ
		{0,1,0,0,1},
		{0,0,1,1,1},
		{0,0,0,0,0},
		{0,0,1,0,1},
		{0,0,0,0,0}};
	int n=5,e=7;
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	printf("ͼ���ڽӱ�:\n");
	DispAdj(G);				//����ڽӱ�G
	vector<int> path,apath;
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j)
			{
				memset(visited,0,sizeof(visited));
				path.clear();
				FindaPath(G,i,j,apath,path);
				if (path.size()>0)
				{
					printf("����%d��%d�ļ�·��: ",i,j);
					for (int k=0;k<path.size();k++)
						printf("%d ",path[k]);
					printf("\n");
				}
			}
	DestroyAdj(G);
}
