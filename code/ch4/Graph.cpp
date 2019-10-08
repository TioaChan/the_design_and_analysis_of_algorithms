//ͼ�Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
#define MAXV 50					//��󶥵����
#define MAXL 20
#define INF 0x3f3f3f3f			//��ʾ��
//�ڽӾ�������Ͷ������£�
typedef struct
{	int no;						//������
	char data[MAXL];			//����������Ϣ
} VertexType;					//��������
typedef struct
{	int edges[MAXV][MAXV];		//�ڽӾ���ı�����
	int n,e;					//������������
	VertexType vexs[MAXV];		//��Ŷ�����Ϣ
} MGraph;						//������ͼ�ڽӾ�������
//ͼ���ڽӱ�洢���͵Ķ������£�
typedef struct ANode
{	int adjvex;					//�ñߵ��յ���
	int weight;					//�ñߵ�Ȩֵ
	struct ANode *nextarc;		//ָ����һ���ߵ�ָ��
} ArcNode;						//�߽������
typedef struct Vnode
{	char data[MAXL];			//����������Ϣ
	ArcNode *firstarc;			//ָ���һ����
} VNode;						//�ڽӱ�ͷ�������
typedef VNode AdjList[MAXV];	//AdjList���ڽӱ�����
typedef struct 
{	AdjList adjlist;			//�ڽӱ�
	int n,e;					//ͼ�ж�����n�ͱ���e
} ALGraph;						//������ͼ�ڽӱ�����

void CreateMat(MGraph &g,int A[][MAXV],int n,int e)	//����ͼ���ڽӾ���
{	int i,j;
	g.n=n; g.e=e;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			g.edges[i][j]=A[i][j];
}
void DispMat(MGraph g)			//���ͼ���ڽӾ���
{	int i,j;
	printf("  n=%d,e=%d\n",g.n,g.e);
	for (i=0;i<g.n;i++)
	{	for (j=0;j<g.n;j++)
			if (g.edges[i][j]==INF)
				printf("%4s","��");
			else
				printf("%4d",g.edges[i][j]);
		printf("\n");
	}
}
void CreateAdj(ALGraph *&G,int A[][MAXV],int n,int e)	//����ͼ���ڽӱ�
{	int i,j;
	ArcNode *p;
	G=(ALGraph *)malloc(sizeof(ALGraph));
	G->n=n; G->e=e;
	for (i=0;i<n;i++)
		G->adjlist[i].firstarc=NULL;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
			if (A[i][j]!=0 && A[i][j]!=INF)
			{	p=(ArcNode *)malloc(sizeof(ArcNode));
				p->adjvex=j;
				p->weight=A[i][j];
				p->nextarc=G->adjlist[i].firstarc;
				G->adjlist[i].firstarc=p;
			}
}
void DispAdj(ALGraph *G)		//���ͼ���ڽӱ�
{	int i;
	ArcNode *p;
	printf("n=%d,e=%d\n",G->n,G->e);
	for (i=0;i<G->n;i++)
	{	printf("[%3d]:",i);
		p=G->adjlist[i].firstarc;
		while (p!=NULL)
		{	printf("��(%d,%d)",p->adjvex,p->weight);
			p=p->nextarc;
		}
		printf("����\n");
	}
}
void DestroyAdj(ALGraph *&G)	//����ͼ���ڽӱ�
{	int i;
	ArcNode *pre,*p;
	for (i=0;i<G->n;i++)
	{	pre=G->adjlist[i].firstarc;
		while (pre!=NULL)
		{	p=pre->nextarc;
			free(pre);
			pre=p;
		}
	}
	free(G);
}
