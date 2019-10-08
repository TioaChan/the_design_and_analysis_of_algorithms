//��������ĸ���-������ѷ�㷨
#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f						//��
#define MAXV 20
//�����ʾ
int n=7,s=0,t=n-1;						//�ֱ��ʾ��㡢�յ�Ͷ������
int f[][MAXV]={{0,6,10,INF,INF,INF,INF},//һ��������
	{INF,0,INF,3,6,INF,INF},{INF,3,0,0,INF,7,INF},
	{INF,INF,INF,0,1,1,3},{INF,INF,INF,INF,0,INF,7},
	{INF,INF,INF,1,INF,0,6},{INF,INF,INF,INF,INF,INF,0}};
int c[][MAXV]={{0,8,14,INF,INF,INF,INF},	//һ������������
	{INF,0,INF,3,6,INF,INF},{INF,5,0,3,INF,8,INF},
	{INF,INF,INF,0,4,3,10},	{INF,INF,INF,INF,0,INF,7},
	{INF,INF,INF,3,INF,0,6},{INF,INF,INF,INF,INF,INF,0}};
//�������ʾ
int maxf=0;									//�������			
//�����̱�ʾ
int pre[MAXV];
int a[MAXV];
int visited[MAXV];
void DFS(int u)							//�Ӷ���u������һ������·��
{
	int v;
	if (visited[t]==1)					//���յ��ѱ�ǣ�����
		return;
	visited[u]=1;						//���ѷ��ʱ�־
	for (v=1;v<=t;v++)					//����ǰ���
	{
		if (c[u][v]>0 && c[u][v]!=INF && visited[v]==0 && c[u][v]>f[u][v])
		{
			a[v]=c[u][v]-f[u][v];
			pre[v]=u;
			DFS(v);
		}
	}
	for (v=1;v<=t;v++)					//���������
	{
		if (c[v][u]>0 && c[v][u]!=INF && visited[v]==0 && f[v][u]>0)
		{
			a[v]=f[v][u];
			pre[v]=-u;
			DFS(v);
		}
	}
}
void argument(int pre[])				//����preָ��·��������
{
	int u,v,min=INF;
	for (v=s;v<=t;v++)
		if (a[v]!=0 && a[v]<min)
			min=a[v];					//����С��������
	u=t; v=pre[u];						//��·�����յ㿪ʼ����
	while (true)
	{
		if (v>=0)						//���������
		{
			f[v][u]+=min;
			u=v;

		}
		else							//���������
		{
			f[u][-v]-=min;
			u=-v;
		}
		if (u==s) break;				//����������
		v=pre[u];
	}
}
void FordFulkerson()					//��������ĸ���-������ѷ�㷨
{
	while (true)
	{
		memset(visited,0,sizeof(visited));
		memset(pre,-1,sizeof(pre));
		memset(a,0,sizeof(a));
		pre[s]=0; a[s]=INF;
		DFS(s);
		if (visited[t]==0)		//û�б���յ�ʱ�˳�ѭ��
			break;
		argument(pre);
	}
	for (int v=1;v<=t;v++)			//�����������������Ϊ�������			
		if (c[s][v]!=0 && c[s][v]!=INF)
			maxf+=f[s][v];
}
void main()
{
	FordFulkerson();
	printf("�����\n");
	printf("    �������=%d\n",maxf);	//���:20
}
