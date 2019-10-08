#include<stdio.h>
#define INF 32767
#define MAXV 20
#define MAXL 20
typedef struct
{	int no;						//������
	char data[MAXL];			//����������Ϣ
} VertexType;					//��������
typedef struct
{	int edges[MAXV][MAXV];		//�ڽӾ���ı�����
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//������ͼ�ڽӾ�������
void CreateMat(MGraph &g,int A[][MAXV],int n,int e)
{	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MGraph g)
{	int i,j;
	printf("  n=%d,e=%d\n",g.n,g.e);
	for (i=0;i<g.n;i++)
	{	for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%4s","��");
			else
				printf("%3d",g.edges[i][j]);
		printf("\n");
	}
}
int color[MAXV];			//������ɫ����
bool ok(MGraph g,int k)		//�ж϶���k����ɫ�Ƿ�����ͻ
{
    int i;
    for (i=0;i<k;i++)
        if (g.edges[k][i]==1 && color[i]==color[k])
            return false;
        return true;
}
void graphcolor(MGraph g,int m)	//�ǵݹ���ݷ����m��ɫ����
{
    int i,k,count=0;
    for (i=0;i<g.n;i++)
        color[i]=0;			//��ʼ��
    k=0;
    while (k>=0)
    {
        color[k]=color[k]+1;
        while (color[k]<=m)
            if (ok(g,k)) break;
            else color[k]=color[k]+1;		//������һ����ɫ
		if (color[k]<=m && k==g.n-1)		//�����ϣ������
		{
			printf(" ����%d: ",++count);
			for (i=0;i<g.n;i++)
				printf("%d ",color[i]);
			printf("\n");
		}
		else if (color[k]<=m && k<g.n-1)
			k++;							//������һ������
		else
		{
			color[k]=0;
			k=k-1;							//����
		}
    }
}
void main()
{
	int m=3;
	MGraph g;
	int A[][MAXV]={							//һ��������ͨͼ
		{0,1,0,0,0},
		{1,0,0,0,0},
		{0,1,0,0,1},
		{0,1,0,0,1},
		{0,0,1,1,0}};
	int n=5,e=5;
	CreateMat(g,A,n,e);						//����ͼ���ڽӾ���洢�ṹg
	printf("�ڽӾ���:\n"); DispMat(g);		//����ڽӾ���g
    printf("3��ɫ��������н�:\n");
    graphcolor(g,m);
}
