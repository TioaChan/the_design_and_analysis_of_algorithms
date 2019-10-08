//���ݷ����TSP����
#include "Graph.cpp"
#pragma warning( disable:4786)
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
typedef set< int > SET;						//����set<int>��ʾ���㼯��
//�����ʾ
int s;										//ָ�����
MGraph g;									//ͼ���ڽӾ���
//�����̱�ʾ
int Count=1;								//·�������ۼ�
vector<int> minpath;						//�������·��
int minpathlen=INF;							//�������·������
void dispasolution(vector<int> path,int pathlen)	//���һ����
{
	printf("    ��%d��·��: ",Count++);
	for (int i=0;i<path.size();i++)
		printf("%2d",path[i]);
	printf(", ·������: %d\n",pathlen);
}
void TSP(SET V,int i,vector<int> path,int pathlen)	//���ݷ���Ӷ���s������TSP·���ͳ���
{
	int prev;
	if (path.size()>0)						//path��Ϊ��
		prev=path.back();					//prevΪ·���ϵ����һ������
	path.push_back(i);						//��ӵ�ǰ����i
	pathlen+=g.edges[prev][i];				//�ۼ�·������
	if (V.size()==0)							//�ҵ�һ��Ҷ�ӽ��
	{
		if (g.edges[i][s]!=0 && g.edges[i][s]!=INF)	//�ö���i�����s�б�
		{	
			path.push_back(0);					//·���м������0
			pathlen+=g.edges[i][s];				//�ۼ�·������
			dispasolution(path,pathlen);		//���һ��·��
			if (pathlen<minpathlen)				//�Ƚ������·��
			{
				minpathlen=pathlen;
				minpath=path;
			}
		}
	}
	else										//���ڷ�Ҷ�ӽ��
	{
		SET::iterator it;
		for (it=V.begin();it!=V.end();it++)
		{
			SET tmpV=V;
			int j=*it;							//ѡ�񶥵�j
			tmpV.erase(j);						//��V��ɾ������j�õ�tmpV
			if (pathlen<minpathlen)				//��֦
				TSP(tmpV,j,path,pathlen);		//�ݹ����
		}
	}
}
void main()
{
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36}, {6,0,8,5}, {8,9,0,5}, {7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);		//����ͼ���ڽӾ���洢�ṹg
	s=0;					//��ʼ����Ϊ0
	vector<int> path;
	int pathlen=0;
	SET V;
	for (int i=1;i<g.n;i++)			//����1,2,3��
		V.insert(i);
	printf("�����\n");
	TSP(V,0,path,pathlen);
	printf("    ���·��: ");		//������·��
	for (int j=0;j<minpath.size();j++)
		printf("%3d",minpath[j]);
	printf("\n    ·������:   %d\n",minpathlen);
}
