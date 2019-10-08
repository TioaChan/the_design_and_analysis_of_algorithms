//������-�����㷨����Դ���·��
#include "Graph.cpp"
void disp(MGraph g,int dist[],int path[],int k)	//���dist��path��������
{
	int i;
	printf("k=%d\n",k);
	printf("dist:\n");
	for (i=0;i<g.n;i++)
		printf("%4d",i);
	printf("\n");
	for (i=0;i<g.n;i++)
		if (dist[i]!=INF)
			printf("%4d",dist[i]);
		else
			printf("%4s","��");
	printf("\n");
	printf("path:\n");
	for (i=0;i<g.n;i++)
		printf("%4d",i);
	printf("\n");
	for (i=0;i<g.n;i++)
		printf("%4d",path[i]);
	printf("\n");
}
void Dispath(MGraph g,int dist[],int path[],int v)
//����Ӷ���v�������������·��
{	int i,j,k;
	int apath[MAXV],d;					//���һ�����·��(����)���䶥�����
	for (i=0;i<g.n;i++)					//ѭ������Ӷ���v��i��·��
		if (i!=v)
		{	printf("  �Ӷ���%d������%d��·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);
			d=0; apath[d]=i;			//���·���ϵ��յ�
			k=path[i];
			if (k==-1)					//û��·�������
				printf("��·��\n");
			else						//����·��ʱ�����·��
			{	while (k!=v)
				{	d++; apath[d]=k;
					k=path[k];
				}
				d++; apath[d]=v;		//���·���ϵ����
				printf("%d",apath[d]);	//��������
				for (j=d-1;j>=0;j--)	//�������������
					printf(",%d",apath[j]);
				printf("\n");
			}
		}
}
bool hasminusCycle(MGraph g,int dist[])	//�ж��Ƿ���ڸ���·
{
	for (int i=0;i<g.n;i++)
		for (int j=0;j<g.n;j++)			//����ÿһ����<i,j>
		{
			if (g.edges[i][j]>0 && g.edges[i][j]<INF)
			{
				if (dist[j]>dist[i]+g.edges[i][j])
					return true;		//���ڸ���·
			}
		}
	return false;						//�����ڸ���·
}

void BellmanFord(MGraph g,int v)
{
	int i,k,u;
	int dist[MAXV],path[MAXV];
	for (i=0;i<g.n;i++)
	{
		dist[i]=g.edges[v][i];			//��dist(0)[i]��ʼ��
		if (i!=v && dist[i]<INF) 
			path[i]=v;					//��path(0)[i]��ʼ��
		else 
			path[i]=-1;
	}
	disp(g,dist,path,0);
	for (k=1;k<g.n;k++) //��dist(0)[u]���Ƴ�dist(1)[u], ��,dist(n-1)[u]ѭ��n-1��
	{
		for (u=0;u<g.n; u++)			//�޸�ÿ�������dist[u]��path[u]
		{
			if (u!=v)
			{
				for (i=0;i<g.n;i++)		//��������ÿ������
				{
					if (g.edges[i][u]<INF && dist[u]>dist[i]+g.edges[i][u])
					{
						dist[u]=dist[i]+g.edges[i][u];
						path[u]=i;
					}
				}
			}
		}
		disp(g,dist,path,k);			//���������Ϣ
	}
	Dispath(g,dist,path,v);				//������·��������
	printf("�Ƿ���ڸ���·: %d\n",hasminusCycle(g,dist));
}
/*
void main()
{
	int n=7,e=12;
	int v=0;
	MGraph g;
	int A[7][MAXV]={
		{0,4,-6,6,INF,INF,INF},
		{INF,0,1,INF,7,INF,INF},
		{INF,INF,0,INF,6,4,INF},
		{INF,INF,2,0,INF,5,INF},
		{INF,INF,INF,INF,0,INF,6},
		{INF,INF,INF,INF,1,0,-8},
		{INF,INF,INF,INF,INF,INF,0}};
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("��%d������������·��:\n",v);
	BellmanFord(g,v);
	printf("\n");
}
*/
void main()
{
	int n=3,e=3;
	int v=0;
	MGraph g;
	int A[3][MAXV]={
		{0,1,INF},
		{INF,0,-4},
		{2,INF,0}};
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("��%d������������·��:\n",v);
	BellmanFord(g,v);
	printf("\n");
}
