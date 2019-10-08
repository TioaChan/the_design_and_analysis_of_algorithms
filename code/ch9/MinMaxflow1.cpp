//����С����������㷨
#include <stdio.h>
#include <string.h>
#define MAXV 10
#define INF 0x3f3f3f3f
//�����ʾ
int n,s,t;
/*
int n=6,s=0,t=n-1;						//�ֱ��ʾ��㡢�յ�Ͷ������
int c[MAXV][MAXV]={{0,4,5,INF,INF,INF}, //һ������������
	{INF,0,1,3,INF,INF},{INF,INF,0,INF,2,INF},
	{INF,INF,INF,0,INF,5},{INF,1,INF,3,0,2},
	{INF,INF,INF,INF,INF,0}};
int b[MAXV][MAXV]={{0,1,3,INF,INF,INF},	//һ����������λ��������
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,4,INF},
		{INF,INF,INF,0,INF,2},
		{INF,2,INF,1,0,4},
		{INF,INF,INF,INF,INF,0}};
*/

int c[MAXV][MAXV];				//����
int b[MAXV][MAXV];				//��λ��������
//�������ʾ
int w[MAXV][MAXV];				//һ����Ȩͼw
int f[MAXV][MAXV];				//������
int maxf=0;						//�������
int mincost=0;					//�������С����
void Init()						//��ʼ��
{
	n=7; s=0; t=n-1;
	memset(f,0,sizeof(f));			//��ʼ��һ������
	memset(c,INF,sizeof(c));		//����c
	for (int i=0;i<n;i++)
		c[i][i]=0;
	c[0][1]=10; c[0][2]=6; c[0][3]=3;
	c[1][4]=4; c[1][5]=6;
	c[2][4]=3; c[2][5]=3;
	c[3][4]=1; c[3][5]=2;
	c[4][6]=12;
	c[5][6]=9;
	memset(b,INF,sizeof(b));		//����b
	for (int j=0;j<n;j++)
		b[j][j]=0;
	b[0][1]=0; b[0][2]=0; b[0][3]=0; 
	b[1][4]=2; b[1][5]=4;
	b[2][4]=5; b[2][5]=4;
	b[3][4]=6; b[3][5]=3;
	b[4][6]=3;
	b[5][6]=12;
}
void disp(int a[MAXV][MAXV])		//���һ������
{
	int i,j;
	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
			if (a[i][j]!=INF)
				printf("%4d",a[i][j]);
			else
				printf("%4s","��");
			printf("\n");
	}
}
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
	printf("path:");
	for (i=0;i<n;i++)
		printf("%3d",path[i]);
	printf("\n");
	j=t; i=path[j];							//���յ�t��ǰ����
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//����ǰ���
		{
			printf("%d  ",c[i][j]-f[i][j]);
			if (c[i][j]-f[i][j]<min)
				min=c[i][j]-f[i][j];
		}
		if (c[j][i]>0 && c[j][i]<INF)		//��������
		{
			printf("%d ",f[i][j]);
			if (f[j][i]<min)
				min=f[j][i];
		}
		if (i==s) break;					//���������ʱ�˳�ѭ��
		j=i;
		i=path[j];
	}
	//printf("������� MIN=%d\n",min);
	return min;
}
void argument(int path[],int min)		//������С������min�����������е���
{
	int i,j;
	j=t,i=path[j];
	printf("��������\n");
	maxf+=min;
	while (true)
	{
		if (c[i][j]>0 && c[i][j]<INF)		//ǰ��ߵ���
		{
			f[i][j]+=min;
			mincost+=min*b[i][j];		//�ۼ���С����
			printf("f[%d][%d]����Ϊ%d\n",i,j,f[i][j]);
		}
		if (c[j][i]>0 && c[j][i]<INF)		//����ߵ���
		{
			f[j][i]-=min;
			mincost+=-min*b[i][j];		//�ۼ���С����
			printf("f[%d][%d]����Ϊ%d\n",j,i,f[j][i]);
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
		printf("k=%d\n",k++);
		Createw();
		printf("w:\n"); disp(w);
		if (BellmanFord(path))
		{
			min=Getargpathmin(path);
			printf("min=%d\n",min);
			argument(path,min);
			printf("f:\n");	disp(f);
			printf("mincost=%d\n",mincost);
		}
		else break;
	}
}
void main()
{
/*
	int i;
	n=6; s=0; t=n-1;
	int f[MAXV][MAXV];
	memset(f,0,sizeof(f));			//��һ����������
	int c[MAXV][MAXV]={				//һ������������
		{0,4,5,INF,INF,INF},
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,2,INF},
		{INF,INF,INF,0,INF,5},
		{INF,1,INF,3,0,2},
		{INF,INF,INF,INF,INF,0}};
	int b[MAXV][MAXV]={				//һ����������λ��������
		{0,1,3,INF,INF,INF},
		{INF,0,1,3,INF,INF},
		{INF,INF,0,INF,4,INF},
		{INF,INF,INF,0,INF,2},
		{INF,2,INF,1,0,4},
		{INF,INF,INF,INF,INF,0}};
		*/
	Init();
	//Createw();
	//printf("c:\n"); disp(c);
	//printf("b:\n"); disp(b);
	//printf("w:\n"); disp(w);
	FordFulkerson();

	//printf("��С�������������:\n");
	//disp(f);
	//int minf=0;
	//for (i=0;i<n;i++)
	//	for (int j=0;j<n;j++)
	//		minf+=f[i][j]*b[i][j];
	printf("maxft=%d\n",maxf);
	printf("mincost=%d\n",mincost);
}
