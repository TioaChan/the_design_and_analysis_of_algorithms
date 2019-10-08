//SPFA�㷨����Դ���·��
#include "Graph.cpp"		//����ͼ�Ļ��������㷨
#include <queue>
#include <vector>
using namespace std;
//�����ʾ
int s;
ALGraph *G;
//�������ʾ
int dist[MAXV];
int path[MAXV];

void Disppath()					//����Ӷ���s�������������·��
{
	vector<int> apath;			//�����һ��·��
	for (int i=0;i<G->n;i++)
	{
		if (i==s) continue;
		if (path[i]==-1)
			printf("  �Ӷ���%d��%d��û��·��\n",s,i);
		else
		{
			apath.clear();
			int j=i;
			apath.push_back(j);
			while (j!=s && j!=-1)
			{
				j=path[j];
				apath.push_back(j);
			}
			printf("  �Ӷ���%d��%d�����·������: %2d, ·��: ",s,i,dist[i]);
			for (int k=apath.size()-1;k>=0;k--)
				printf("%d ",apath[k]);
			printf("\n");
		}
	}
}
void SPFA()				//��Դ��s���������������̾���
{
	ArcNode *p;
	int v,w;
	int visited[MAXV];
	queue<int> qu;					//����һ������qu
	for (int i=0;i<G->n;i++)		//��ʼ������s��i�ľ���
	{
		dist[i]=INF;
		visited[i]=0;
		path[i]=-1;
	}
    dist[s]=0;						//��Դ���dist��Ϊ0
    visited[s]=1;					//����Դ��s�ķ��ʱ��
	qu.push(s);						//Դ��s����
    while (!qu.empty())						//�Ӳ���ѭ��
	{
		v=qu.front(); qu.pop();				//���Ӷ���v
		visited[v]=0;						//�ͷŶ�v�ı�ǣ��������½���
		p=G->adjlist[v].firstarc;
		while (p!=NULL)						//������v��ÿ�����ڵ�w
		{
			w=p->adjvex;
			if (dist[w]>dist[v]+p->weight)	//�������������������
			{
				dist[w]=dist[v]+p->weight;   //�ɳ�dist[i]
				path[w]=v;
			}
			if (visited[w]==0)			//����wû�з���
			{
				qu.push(w);				//������w����
				visited[w]=1;
			}
			p=p->nextarc;
		}
    }
}
void main()
{
	int n=7,e=12;
	int A[7][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�G
	s=0;
	SPFA();
	printf("�����\n");
	Disppath();
}
