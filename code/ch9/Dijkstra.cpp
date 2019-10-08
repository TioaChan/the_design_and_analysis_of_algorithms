//�ҿ�˹�����㷨����Դ���·��
#include "Graph.cpp"
void Dispath(MGraph g,int dist[],int path[],int S[],int v)
//����Ӷ���v�������������·��
{	int i,j,k;
	int apath[MAXV],d;					//���һ�����·��(����)���䶥�����
	for (i=0;i<g.n;i++)					//ѭ������Ӷ���v��i��·��
		if (S[i]==1 && i!=v)
		{	printf("  �Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
			d=0; apath[d]=i;			//����·���ϵ��յ�
			k=path[i];
			if (k==-1)				//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//����·���ϵ����
				printf("%d",apath[d]);	//��������
				for (j=d-1;j>=0;j--)	//�������������
					printf(",%d",apath[j]);
				printf("\n");
			}
		}
}
void Dijkstra(MGraph g,int v)			//Dijkstra�㷨
{
	int dist[MAXV],path[MAXV];
	int S[MAXV];
	int mindis,i,j,u;
	for (i=0;i<g.n;i++)
	{	dist[i]=g.edges[v][i];		//�����ʼ��
		S[i]=0;						//S[]�ÿ�
		if (g.edges[v][i]<INF)		//·����ʼ��
			path[i]=v;				//����v������i�б�ʱ���ö���i��ǰһ������Ϊv
		else
			path[i]=-1;				//����v������iû��ʱ���ö���i��ǰһ������Ϊ-1
	}
	S[v]=1;path[v]=0;				//Դ����v����s��
	for (i=0;i<g.n;i++)				//ѭ��ֱ�����ж�������·�������
	{	mindis=INF;					//mindis����С·������
		for (j=0;j<g.n;j++)			//ѡȡ����s���Ҿ�����С����Ķ���u
			if (S[j]==0 && dist[j]<mindis) 
			{	u=j;
				mindis=dist[j];
			}
		S[u]=1;						//����u����s��
		for (j=0;j<g.n;j++)			//�޸Ĳ���S�еĶ���ľ���
			if (S[j]==0)
				if (g.edges[u][j]<INF && dist[u]+g.edges[u][j]<dist[j])
				{	dist[j]=dist[u]+g.edges[u][j];
					path[j]=u;
				}
	}
	Dispath(g,dist,path,S,v);		//������·��
}
void main()
{
	int n=7,e=12;
	int v=0;
	MGraph g;
	int A[7][MAXV]={
		{0,4,6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,8},
		{INF,INF,INF,INF,INF,INF,0}};
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("��%d������������·��:\n",v);
	Dijkstra(g,v);
	printf("\n");
}