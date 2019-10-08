//����С����������㷨
#include <stdio.h>
#include <string.h>
#define MAXV 10
#define INF 0x3f3f3f3f
//�����ʾ
int n=6,s=0,t=n-1;						//�ֱ��ʾ��㡢�յ�Ͷ������
int c[MAXV][MAXV]={{0,4,5,INF,INF,INF}, //һ������������
	{INF,0,1,3,INF,INF},{INF,INF,0,INF,2,INF},
	{INF,INF,INF,0,INF,5},{INF,1,INF,3,0,2},
	{INF,INF,INF,INF,INF,0}};
int b[MAXV][MAXV]={{0,1,3,INF,INF,INF},	//һ����������λ��������
	{INF,0,1,3,INF,INF},{INF,INF,0,INF,4,INF},
	{INF,INF,INF,0,INF,2},{INF,2,INF,1,0,4},
	{INF,INF,INF,INF,INF,0}};
//�������ʾ
int w[MAXV][MAXV];				//һ����Ȩͼw
int f[MAXV][MAXV];				//������
int maxf=0;						//�������
int mincost=0;					//�������С����
void Createw()					//��c��b��f���츳Ȩͼw
{
	int i,j;
	for (i=0;i<n;i++)			//w����Ԫ�س�ʼ��
		for (j=0;j<n;j++)
			w[i][j]=INF;
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			if (c[i][j]!=0 && c[i][j]<INF)
			{
				if (f[i][j]<c[i][j])
					w[i][j]=b[i][j];
				else if (f[i][j]==c[i][j])
					w[i][j]=INF;
				if (f[i][j]>0)
					w[j][i]=-b[i][j];
				else if (f[i][j]==0)
					w[j][i]=INF;
			}
			else if (i==j)
				w[i][j]=0;
		}
}
bool BellmanFord(int path[])		//��w���s��t�����·��path
{
	int dist[MAXV];					//dist[i]���s������i�����·������
	for (int i=0;i<n;i++)			//��ʼ��
	{
		dist[i]=w[s][i];			//��dist(0)[i]��ʼ��
		if (i!=s && dist[i]<INF) 
			path[i]=s;				//��path(0)[i]��ʼ��
		else 
			path[i]=-1;
	}
	for (int k=1;k<n;k++)
	{
		for (int u=0;u<n; u++)		//�޸�ÿ�������dist[u]��path[u]
		{
			if (u!=s)
			{
				for (int i=0;i<n;i++)	//��������ÿ������
				{
					if (w[i][u]<INF && dist[u]>dist[i]+w[i][u])
					{
						dist[u]=dist[i]+w[i][u];
						path[u]=i;
					}
				}
			}
		}
	}
	if (path[t]==-1)
		return false;	//��û�д���㵽�յ�����·��,����false
	else
		return true;	//�����ڴ���㵽�յ�����·��,����true
}
int Getargpathmin(int path[])	//��path��ʾ����С������min
{
	int i,j,min=INF;
	j=t; i=path[j];							//���յ�t��ǰ����
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//����ǰ���
		{
			if (c[i][j]-f[i][j]<min)
				min=c[i][j]-f[i][j];
		}
		if (c[j][i]>0 && c[j][i]<INF)		//��������
		{
			if (f[j][i]<min)
				min=f[j][i];
		}
		if (i==s) break;					//���������ʱ�˳�ѭ��
		j=i;
		i=path[j];
	}
	return min;
}
void argument(int path[],int min)		//������С������min�����������е���
{
	int i,j;
	j=t,i=path[j];
	maxf+=min;
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//ǰ��ߵ���
		{
			f[i][j]+=min;
			mincost+=min*b[i][j];			//�ۼ���С����
		}
		if (c[j][i]>0 && c[j][i]<INF)		//����ߵ���
		{
			f[j][i]-=min;
			mincost+=-min*b[j][i];			//�ۼ���С����
		}
		if (i==s) break;					//���������ʱ�˳�ѭ��
		j=i;
		i=path[j];
	}
}
void FordFulkerson()			//����С���������f
{
	int k=0;
	int path[MAXV],min;
	while (true)
	{
		Createw();
		if (BellmanFord(path))
		{
			min=Getargpathmin(path);
			argument(path,min);
		}
		else break;
	}
}
void main()
{
	memset(f,0,sizeof(f));		
	FordFulkerson();
	printf("�����\n");
	printf("    �����������: %d\n",maxf);
	printf("    �������С����: %d\n",mincost);
}
