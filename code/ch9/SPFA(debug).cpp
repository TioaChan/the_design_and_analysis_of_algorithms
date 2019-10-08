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
int visited[MAXV];

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
void disp(queue<int> qu)
{
	printf("qu\t");
	while (!qu.empty())
	{
		printf("%4d",qu.front());
		qu.pop();
	}
	printf("\n");
	printf("i\t");
	for (int i=0;i<G->n;i++)
		printf("%4d",i);
	printf("\nvisited:");
	for (int k=0;k<G->n;k++)
		printf("%4d",visited[k]);
	printf("\ndist\t");
	for (int j=0;j<G->n;j++)
		if (dist[j]==INF)
			printf("%4s","��");
		else
			printf("%4d",dist[j]);
	printf("\n");
}

void SPFA()				//��Դ��s���������������̾���
{
	ArcNode *p;
	int v,w;
	queue<int> qu,qu1;					//����һ������qu
	for (int i=0;i<G->n;i++)		//��ʼ������s��i�ľ���
	{
		dist[i]=INF;
		visited[i]=0;
		path[i]=-1;
	}
    dist[s]=0;						//��Դ���dist��Ϊ0
    visited[s]=1;					//����Դ��s�ķ��ʱ��
	qu.push(s);						//Դ��s����
	qu1=qu;
	disp(qu1);
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
		printf("����%d,���ڵ����\n",v);
		qu1=qu;
		disp(qu1);
    }
}
void main()
{
	int n=4,e=4;
	int A[][MAXV]={
		{0,2,4,INF},
		{INF,INF,1,INF},
		{INF,INF,0,3},
		{INF,INF,INF,0}};
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�G
	printf("�ڽӱ�G\n"); DispAdj(G);
	s=0;
	SPFA();
	printf("�����\n");
	Disppath();
}
