//����ķ�㷨����С������
#include "Graph.cpp"
void Prim(MGraph g,int v)
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
		printf(" ��(%d,%d)ȨΪ:%d\n",closest[k],k,mincost);
		lowcost[k]=0;					//���k�Ѿ�����U
		for (j=0;j<g.n;j++)				//�޸�����lowcost��closest
			if (g.edges[k][j]!=0 && g.edges[k][j]<lowcost[j])
			{
				lowcost[j]=g.edges[k][j];
				closest[j]=k;
			}
	}
}
void main()
{
	MGraph g;
	int A[][MAXV]={			//һ����Ȩ����ͼ
		{0,  6,  INF,INF,INF,1,  INF},
		{6,  0,  4,  INF,INF,INF,3},
		{INF,4,  0,  2,  INF,INF,INF},
		{INF,INF,2,  0,  6,  INF,5},
		{INF,INF,INF,6,  0,  8,  7},
		{1,  INF,INF,INF,8,  0,  INF},
		{INF,3,  INF,5,  7,  INF,0}};
	int n=7,e=9;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���g
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("Prim�㷨���:\n");
	Prim(g,0);
}
