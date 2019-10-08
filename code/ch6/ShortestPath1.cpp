#include <stdio.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;
#define INF 0x3f3f3f3f			//��ʾ��
#define MAXN 51
//�����ʾ
int n;							//ͼ�������
int a[MAXN][MAXN];				//ͼ���ڽӾ���
int v;							//Դ��
//�������ʾ
int dist[MAXN];					//dist[i]Դ�㵽����i�����·������
int prev[MAXN];					//prev[i]��ʾԴ�㵽����j�����·�������ж���j��ǰ������
struct NodeType					//���н������
{
    int vno;					//������
	int length;					//·������
    bool operator<(const NodeType & node) const
    {
        return length>node.length;	//lengthԽСԽ���ȳ���
    }
};
void bfs(int v)						//����㷨
{
	NodeType e,e1;
    priority_queue<NodeType> pqu;	//�������ȶ���
	e.vno=v;						//����Դ����e
	e.length=0;
	pqu.push(e);					//Դ����e����
    dist[v]=0;
    while(!pqu.empty())				//���в���ѭ��
    {
		e=pqu.top(); pqu.pop();		//�����н��e
        for (int j=0; j<n; j++)
		{
            if(a[e.vno][j]<INF && e.length+a[e.vno][j]<dist[j])
            {	//��֦��e.vno������j�б߲���·�����ȸ���
                dist[j]=e.length+a[e.vno][j];
				prev[j]=e.vno;
				e1.vno=j;			//�������ڶ���j�Ľ��e1
				e1.length=dist[j];
				pqu.push(e1);		//���e1����
            }
		}
    }
}
void addEdge(int i,int j,int w)		//ͼ�����һ����
{
	a[i][j]=w;
}
void dispapath(int v,int i)			//���v��i�����·��
{
	vector<int> path;
	if (v==i) return;
	if (dist[i]==INF)
		printf("	Դ��%d������%dû��·��\n",v,i);
	else
	{
		int k=prev[i];
		path.push_back(i);		//���Ŀ�궥��
		while (k!=v)			//����м䶥��
		{
			path.push_back(k);
			k=prev[k];
		}
		path.push_back(v);		//���Դ��
		printf("	Դ��%d������%d�����·������: %d, ·��: ",v,i,dist[i]);
		for (int j=path.size()-1;j>=0;j--)	//���������������·��
			printf("%d ",path[j]);
		printf("\n");
	}
}
void dispallpath(int v)			//���Դ��v�������������·��
{
	for (int i=0;i<n;i++)
		dispapath(v,i);
}
void main()
{
	memset(dist,INF,sizeof(dist));	//��ʼ��Ϊ��
	memset(a,INF,sizeof(a));		//��ʼ��Ϊ��
	n=6;							//����ͼ�Ķ������
	for (int i=0;i<n;i++)			//�Խ�������Ϊ0
		a[i][i]=0;
	addEdge(0,2,10);				//���8����
	addEdge(0,4,30);
	addEdge(0,5,100);
	addEdge(1,2,4);
	addEdge(2,3,50);
	addEdge(3,5,10);
	addEdge(4,3,20);
	addEdge(4,5,60);
	v=0;
	bfs(v);
	printf("�����\n");
	dispallpath(v);
}
