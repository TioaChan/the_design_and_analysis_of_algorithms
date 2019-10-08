//���ö���ʽ��֦�޽編���0/1����������㷨
#include <stdio.h>
#include <queue>
using namespace std;
#define MAXN 20						//��������Ʒ��
#define INF 0x3f3f3f3f3				//�����
//�����ʾ
int n=3,W=30;
int w[]={0,16,15,15};				//�������±�0����
int v[]={0,45,25,25};  				//��ֵ���±�0����
//�������ʾ
int maxv=-9999;						//�������ֵ,ȫ�ֱ���
int bestx[MAXN];					//������Ž�,ȫ�ֱ���

int total=1;						//��ռ��н�����ۼ�,ȫ�ֱ���

struct NodeType						//�����еĽ������
{	int no;							//�����
	int i;							//��ǰ����������ռ��еĲ��
	int w;							//��ǰ����������
	int v;							//��ǰ�����ܼ�ֵ
	int x[MAXN];					//��ǰ�������Ľ�����
	double ub;						//�Ͻ�
	bool operator<(const NodeType &s) const	//����<��ϵ����
	{
		return ub<s.ub;				//ubԽ��Խ���ȳ���
	}
};
void bound(NodeType &e)			//�����֦���e���Ͻ�
{
	int i=e.i+1;
	int sumw=e.w;
	double sumv=e.v;
	while ((sumw+w[i]<=W) && i<=n)
	{	sumw+=w[i];				//���㱳����װ������
		sumv+=v[i];				//���㱳����װ���ֵ
		i++;
	}
	if (i<=n)	
		e.ub=sumv+(W-sumw)*v[i]/w[i];
	else
		e.ub=sumv;
}
void EnQueue(NodeType e,priority_queue<NodeType> &qu)	//���e����qu
{
	if (e.i==n)					//����Ҷ�ӽ��
	{
		if (e.v>maxv)			//�ҵ������ֵ�Ľ�
		{
			maxv=e.v;
			for (int j=1;j<=n;j++)
				bestx[j]=e.x[j];
		}
	}
	else qu.push(e);	
}
void bfs()							//��0/1���������Ž�
{
	int j;
	NodeType e,e1,e2;				//����3�����
	priority_queue<NodeType> qu;				//����һ������
	e.i=0;							//������ó�ֵ�����μ�Ϊ0
	e.w=0; e.v=0;
	e.no=total++; 
	for (j=1;j<=n;j++)
		e.x[j]=0;
	bound(e);						//��������Ͻ�
	qu.push(e);						//��������
	while (!qu.empty())				//�Ӳ���ѭ��
	{
		e=qu.top(); qu.pop();		//���ӽ��e
		if (e.w+w[e.i+1]<=W)		//��֦��������ӽ��
		{
			e1.no=total++; 
			e1.i=e.i+1;				//�������ӽ��
			e1.w=e.w+w[e1.i];
			e1.v=e.v+v[e1.i];
			for (j=1;j<=n;j++)		//���ƽ�����
				e1.x[j]=e.x[j];
			e1.x[e1.i]=1;
			bound(e1);				//�����ӽ����Ͻ�
			EnQueue(e1,qu);			//���ӽ����Ӳ���
		}
		e2.no=total++;				//�����Һ��ӽ��
		e2.i=e.i+1;
		e2.w=e.w; e2.v=e.v;
		for (j=1;j<=n;j++)			//���ƽ�����
			e2.x[j]=e.x[j];
		e2.x[e2.i]=0;
		bound(e2);					//���Һ��ӽ����Ͻ�
		if (e2.ub>maxv)				//���Һ��ӽ�����,�����,���򱻼�֦
			EnQueue(e2,qu);
	}
}
void main()
{
	bfs();								//���ö���ʽ��֦�޽編��0/1��������
	printf("��֦�޽編���0/1��������:\n  X=[");
	for(int i=1;i<=n;i++)				//������Ž�
		printf("%2d",bestx[i]);			//�������X[n]����
	printf("]��װ���ܼ�ֵΪ%d\n",maxv);
}
