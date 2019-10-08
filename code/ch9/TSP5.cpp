//̰�ķ����TSP����
#include "Graph.cpp"
#pragma warning( disable:4786) 
#include <vector>
#include <queue>
using namespace std;
void TSP(MGraph g)					//��̰�ķ�������Ϊ0��TSP����
{
	int i,j,k,minj,minedge;
	bool find;
	vector<int> minpath;			//���·��
	int minpathlen=0;				//���·������
	minpath.push_back(0);			//���0����·��
	i=0;							//��ǰ����Ϊ���0
	while (minpath.size()!=g.n)		//��δ�����ж���ʱѭ��
	{
		find=false;
		minedge=INF;
		for (j=1;j<g.n;j++)			//�Ӷ���1��n-1ѭ���Ҿ��붥��i����Ķ���minj
		{
			if (g.edges[i][j]!=0 && g.edges[j][j]!=INF)	//��ǰ����i������j�б�
			{
				k=0;
				while (k<minpath.size() && j!=minpath[k])	//�ж�·�����Ƿ��ж���j
					k++;
				if (k=minpath.size())		//����j����·����
				{
					if (g.edges[i][j]<minedge)
					{
						minedge=g.edges[i][j];
						minj=j;
					}
				}

			}
		}
		minpath.push_back(minj);
		minpathlen+=minedge;
		i=minj;
	}
	minpath.push_back(0);			//·���м������
	minpathlen+=g.edges[minj][0];
	printf("·������=%d, ",minpathlen);
	printf("·��:");
	printf("%d",minpath[0]);
	for (i=1;i<minpath.size();i++)
		printf("��%d",minpath[i]);
	printf("\n");
}
void main()
{
	MGraph g;
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},
		{6,0,8,5},
		{8,9,0,5},
		{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���洢�ṹg
	printf("�ڽӾ���:\n"); DispMat(g);	//����ڽӾ���g
	printf("���Ϊ0�Ľ�:\n");TSP(g);
}
