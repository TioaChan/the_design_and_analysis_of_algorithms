//��4.6���㷨
#include "Graph.cpp"				//����ͼ�Ļ��������㷨
#include <string.h>
int visited[MAXV];
bool ExistPath(ALGraph *G,int u,int v)	//�ж�G�дӶ���u��v�Ƿ���ڼ�·��
{
	int w;
	ArcNode *p;
	visited[u]=1;					//���ѷ��ʱ��
	if (u==v)						//�ҵ���һ��·��
		return true;
	p=G->adjlist[u].firstarc;		//pָ�򶥵�u�ĵ�һ�����ڵ�
	while (p!=NULL)
	{	w=p->adjvex;				//wΪ����u�����ڶ���
		if (visited[w]==0)			//��w����δ����,�ݹ������
		{
			bool flag=ExistPath(G,w,v);
			if (flag) return true;
		}
		p=p->nextarc;				//pָ�򶥵�u����һ�����ڵ�
	}
	return false;
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
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
		{
			memset(visited,0,sizeof(visited));
			if (ExistPath(G,i,j) && i!=j)
				printf("����%d������%d���ڼ�·��\n",i,j);
		}
	DestroyAdj(G);
}
