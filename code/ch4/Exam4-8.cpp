//��4.8���㷨
#include "Graph.cpp"	//����ͼ�Ļ��������㷨
#include <queue>
#include <vector>
using namespace std;
void Findpath(int pre[],int v,vector<int> &path)	//��pre������·��path
{
	int d=v;
	while (d!=-1)
	{
		path.push_back(d);
		d=pre[d];
	}
}
void ShortPath(ALGraph *G,int u,int v,vector<int> &path)
//��ͼG�дӶ���u������v����̣��棩·��path
{
	ArcNode *p;
	int w;
	queue<int> qu;						//����һ������qu
	int pre[MAXV];						//��ʾǰ����ϵ
	int visited[MAXV];					//�����Ŷ���ķ��ʱ�־������
	memset(visited,0,sizeof(visited));	//���ʱ�־�����ʼ��
	qu.push(u);							//����u����
	visited[u]=1;
	pre[u]=-1;
	while (!qu.empty())			//�Ӳ���ʱѭ��
	{
		w=qu.front(); qu.pop();	//���Ӷ���w
		if (w==v)				//�ҵ�vʱ���·��֮�沢�˳�
		{
			Findpath(pre,v,path);
			return;
		}
		p=G->adjlist[w].firstarc;	//��w�ĵ�һ���ڽӵ�
		while (p!=NULL)
		{
			if (visited[p->adjvex]==0)
			{
				visited[p->adjvex]=1;		//����w���ڽӵ�
				qu.push(p->adjvex);			//��w���ڽӵ����
				pre[p->adjvex]=w;			//����p->adjvex�����ǰ��Ϊw
			}
			p=p->nextarc;			//��w����һ���ڽӵ�
		}
	}
}
void Disppath(vector<int> path)		//�������·��path
{
	vector<int>::reverse_iterator it;
	for (it=path.rbegin();it!=path.rend();++it)
		printf("%d ",*it);
	printf("\n");
}
void main()
{
	ALGraph *G;
	int A[][MAXV]={			//���̡̳���ͼ4.11������ͼ
		{0,1,0,0,1},
		{0,0,1,1,1},
		{0,0,0,0,0},
		{0,0,1,0,1},
		{0,0,0,0,0}};
	int n=5,e=7;
	int u=0,v=2;
	CreateAdj(G,A,n,e);		//����ͼ���ڽӱ�洢�ṹG
	vector<int> path;
	printf("�����\n");
	for (int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			if (i!=j)
			{
				path.clear();
				ShortPath(G,i,j,path);
				if (path.size()>0)
				{
					printf("  �Ӷ���%d��%d�����·��: ",i,j);
					Disppath(path);
				}
			}
	DestroyAdj(G);			//�����ڽӱ�G
}
