//��³˹�����㷨����С������
#include "Graph.cpp"
#include <algorithm>
using namespace std;
#define MaxSize 100
//----���鼯��������--------
typedef struct node
{	int data;			//����Ӧ������
	int rank;			//����Ӧ��
	int parent;		//����Ӧ˫���±�
} UFSTree;			//���鼯���Ľ������
void MAKE_SET(UFSTree t[],int n)	//��ʼ�����鼯��
{ 	for (int i=0;i<n;i++)			//������Ϊ0��(n-1)
	{	t[i].rank=0;				//�ȳ�ʼ��Ϊ0
		t[i].parent=i;				//˫�׳�ʼ��ָ������
	}
}
int FIND_SET(UFSTree t[],int x)			//��x���������в��Ҽ��ϱ��
{	if (x!=t[x].parent)					//��˫�ײ�������
		return(FIND_SET(t,t[x].parent));	//�ݹ���˫������x
	else
		return(x);						//��˫��������,����x
}
void UNION(UFSTree t[],int x,int y)		//��x��y���ڵ������ϲ�
{	x=FIND_SET(t,x);
	y=FIND_SET(t,y);
	if (t[x].rank>t[y].rank)			//x�����ȴ���y������
		t[y].parent=x;				//��x�����Ϊy��˫�׽��
	else								//y�����ȴ��ڵ���x������
	{ 	t[x].parent=y;				//��y�����Ϊx��˫�׽��
		if (t[x].rank==t[y].rank)		//x��y��������ͬ
			t[y].rank++;				//y��������1
	}
}
struct Edge
{
	int u;		//�ߵ���ʼ����
	int v;		//�ߵ���ֹ����
	int w;		//�ߵ�Ȩֵ
	bool operator<(const Edge &e) const
	{
		return w<e.w;			//���ڰ�w��������
	}
};

void Kruskal(MGraph g)			//Kruskal�㷨
{
	int i,j,k,u1,v1,sn1,sn2;
	UFSTree t[MaxSize];
	Edge E[MaxSize];
	k=0;
	for (i=0;i<g.n;i++)			//��g�����ǲ��ֲ����ı߼�E
		for (j=0;j<i;j++)
			if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)
			{	E[k].u=i;E[k].v=j;E[k].w=g.edges[i][j];
				k++;
			}
	sort(E,E+k);				//��w��������
	MAKE_SET(t,g.n);			//��ʼ�����鼯��t
	k=1;						//k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1
	j=0;						//E�бߵ��±�,��ֵΪ0
	while (k<g.n)				//���ɵı���С��nʱѭ��
	{	u1=E[j].u;
		v1=E[j].v;				//ȡһ���ߵ�ͷβ������u1��v2
		sn1=FIND_SET(t,u1);
		sn2=FIND_SET(t,v1);		//�ֱ�õ��������������ļ��ϱ��
		if (sn1!=sn2)			//��Ӹñ߲��ṹ�ɻ�·,������Ϊ��С��������һ�������
		{	printf("  (%d,%d):%d\n",u1,v1,E[j].w);
			k++;				//���ɱ�����1
			UNION(t,u1,v1);		//��u1��v1��������ϲ�
		}
		j++;					//ɨ����һ����
	}
}
void main()
{
	MGraph g;
	int A[][MAXV]={				//һ����Ȩ����ͼ
		{0,  6,  INF,INF,INF,1,  INF},
		{6,  0,  4,  INF,INF,INF,3},
		{INF,4,  0,  2,  INF,INF,INF},
		{INF,INF,2,  0,  6,  INF,5},
		{INF,INF,INF,6,  0,  8,  7},
		{1,  INF,INF,INF,8,  0,  INF},
		{INF,3,  INF,5,  7,  INF,0}};
	int n=7,e=9;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	printf("ͼ���ڽӾ���:\n");
	DispMat(g);				//����ڽӾ���g
	printf("Kruskal�㷨���:\n");
	Kruskal(g);
}
