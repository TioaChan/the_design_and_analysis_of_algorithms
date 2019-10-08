//���������㷨�����Դ���·��
#include "Graph.cpp"
void disp(int A[][MAXV],int path[][MAXV],int n,int k)	//������
{
	int i,j;
	printf("A(%d)\t\t\t\t\t\tpath(%d)\n",k,k);
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (A[i][j]!=INF)
				printf("%4d",A[i][j]);
			else
				printf("%4s","��");
		printf("\t");
		for (j=0;j<n;j++)
			printf("%4d",path[i][j]);
		printf("\n");
	}
}
void Dispath(MGraph g,int A[][MAXV],int path[][MAXV])
//������е����·���ͳ���
{	int i,j,k,s;
	int apath[MAXV],d;		//���һ�����·���м䶥��(����)���䶥�����
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++)
		{	if (A[i][j]!=INF && i!=j)			//������i��j֮�����·��
			{	printf("  ��%d��%d��·��Ϊ:",i,j);
				k=path[i][j];
				d=0; apath[d]=j;				//·��������յ�
				while (k!=-1 && k!=i)			//·��������м��
				{	d++; apath[d]=k;
					k=path[i][k];
				}
				d++; apath[d]=i;				//·����������
				printf("%d",apath[d]);			//������
				for (s=d-1;s>=0;s--)			//���·���ϵ��м䶥��
					printf(",%d",apath[s]);
				printf("\t·������Ϊ:%d\n",A[i][j]);
			}
		}
}
void Floyd(MGraph g)
{	int A[MAXV][MAXV],path[MAXV][MAXV];
	int i,j,k;
	for (i=0;i<g.n;i++)
		for (j=0;j<g.n;j++) 
		{	A[i][j]=g.edges[i][j];
			if (i!=j && g.edges[i][j]<INF)
				path[i][j]=i;	//����i��j�б�ʱ
			else
				path[i][j]=-1;	//����i��jû�б�ʱ
		}
	for (k=0;k<g.n;k++)
	{
		for (i=0;i<g.n;i++)
			for (j=0;j<g.n;j++)
				if (A[i][j]>A[i][k]+A[k][j])
				{	A[i][j]=A[i][k]+A[k][j];
					path[i][j]=path[k][j];	//�޸����·��
				}
		disp(A,path,g.n,k);			//���������Ϣ
	}
	Dispath(g,A,path);				//������·��
}
void main()
{
	int n=4,e=8;
	MGraph g;
	int A[4][MAXV]={
		{0,  5,INF,7},
		{INF,0,  4,2},
		{3,  3,  0,2},
		{INF,INF,1,0}};
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("����������·��:\n");
	Floyd(g);
	printf("\n");
}