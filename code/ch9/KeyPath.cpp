//����ͼ�Ĺؼ�·�����㷨
#include <stdio.h>
#include <string.h>
const int MAXV=20;				//ͼ�����Ķ�����
const int MAXL=10;				//������Ϣ������ַ�����
const int INF=32767;			//��INF��ʾ��
//����ͼ���ڽӾ�������MGraph��Ŷ��ͼ
typedef struct
{	int no;					//������
	char data[MAXL];			//����������Ϣ
}  VertexType;				//��������
typedef struct 
{	int edges[MAXV][MAXV];		//�ڽӾ���ı����飬����ȨֵΪT����
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//ͼ�ڽӾ�������
void CreateMGraph(MGraph &g,int a[MAXV][MAXV],char b[MAXV][MAXL],int n)
//ͨ��������a��������Ϣ����b�Ͷ�����n������ͼ���ڽӾ���g
{	int i,j;
	g.n=n;					//�ö�����
	for (i=0;i<g.n;i++)
	{	strcpy(g.vexs[i].data,b[i]); 
		for (j=0;j<g.n;j++)
			g.edges[i][j]=a[i][j];
	}
}
void DispMGraph(MGraph g)		//���ͼ���ڽӾ���
{	int i,j;
	for (i=0;i<g.n;i++)
	{	for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%4s","��");
			else
				printf("%4d",g.edges[i][j]);
		printf("\n");
	}
}
void DispKeyPath(MGraph g,int path[])	//���һ���ؼ�·��
{	int i,apath[MAXV],d;			//��Źؼ�·��(����)���䶥�����
	printf("�ؼ�·��:");
	i=g.n-1; d=0;
	while (i!=-1)
	{	apath[d]=i; d++;
		i=path[i];
	}
	for (i=d-1;i>0;i--)			//��������ؼ�·��
		printf("%s��",g.vexs[apath[i]].data);
	printf("%s\n",g.vexs[apath[i]].data);
}
int LongPath(MGraph g,int path[])	//��ؼ�·�����䳤��
{	int n=g.n,i,j,maxdis,maxj;
	int dist[MAXV];				//����dist����
	for (i=0;i<n;i++)				//��ʼ��
	{	dist[i]=0;
		path[i]=-1;
	}
	for (i=n-1;i>0;i--)			//���ο��Ƕ���n-1������2��1
	{	printf("���Ƕ���i=%d\n",i);
		maxdis=-1;
		for (j=0;j<n;j++)			//�󶥵�i�����ǰ������maxj
			if (g.edges[j][i]!=-1 && g.edges[j][i]!=INF) //����j��i�ı�
			{	dist[j]=g.edges[j][i]+dist[i]; 
				printf("�б�(%d,%d),����Ϊ%d,",j,i,g.edges[j][i]);
				printf("���dist[%d]=%d\n",j,dist[j]);
				if (maxdis<dist[j])
				{	maxdis=dist[j];
					maxj=j;
				}
			}
		dist[i]=maxdis;
		path[i]=maxj;
		printf("i=%d�����:dist[%d]=%d,path[%d]=%d\n",i,i,maxdis,i,maxj);
	}
	return dist[0];
}
void main()
{	int n=10,keyplength;
	int path[MAXV];
	MGraph g;
	int A[MAXV][MAXV]={		//ͼ9.31�ı�����
		{ -1,  6,  4,  5 ,INF,INF,INF,INF,INF,INF},
		{INF, -1, INF,INF, 1 ,INF,INF,INF,INF,INF},
		{INF,INF, -1 ,INF, 1 ,INF,INF,INF,INF,INF},
		{INF,INF,INF,-1 ,INF, 2,  INF,INF,INF,INF},
		{INF,INF,INF,INF, -1 , INF, 9 , 7,INF,INF},
		{INF,INF,INF,INF,INF, -1 ,INF,INF, 0,INF},
		{INF,INF,INF,INF,INF, INF,-1, INF,INF, 2},
		{INF,INF,INF,INF,INF,INF,INF, -1 ,INF, 4 },
		{INF,INF,INF,INF,INF,INF,INF,INF, -1 , 4 },
		{INF,INF,INF,INF,INF,INF,INF,INF,INF, -1 }};
	char B[MAXV][MAXL]={"A","B","C","D","E","D'","F","G","H","I"};//ͼ9.31�Ķ�����Ϣ
	printf("����ͼ���ڽӾ���\n");
	CreateMGraph(g,A,B,n);;
	printf("ͼ���ڽӾ���:\n"); DispMGraph(g);
	keyplength=LongPath(g,path);	//��ؼ�·�����䳤��
	printf("�ؼ�·������=%d\n",keyplength);
	DispKeyPath(g,path);			//���һ���ؼ�·��
}
