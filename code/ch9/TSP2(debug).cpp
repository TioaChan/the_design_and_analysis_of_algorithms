//��̬�滮���TSP����
#include "Graph.cpp"
#pragma warning(disable:4786)
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
typedef set< int > SET;						//����set<int>��ʾ���㼯��
//�����ʾ
int s=0;									//ָ�����Ϊ0
MGraph g;									//ͼ���ڽӾ���
void dispset(SET V)
{
	SET::iterator it;
	printf("{");
	for (it=V.begin();it!=V.end();++it)
		printf("%d ",*it);
	printf("}");
}

int f(SET V,int i)							//��TSP���н��·������
{
	int minpathlen=INF;						//���·������
	if (V.size()==0)						//��VΪ��ʱ
	{
		printf("����f({ },%d)\n",i);
		printf("���f({ },%d),�ݹ����pathlen=%d\n",i,g.edges[0][i]);
		return g.edges[0][i];
	}
	else									//��VΪ����ʱ
	{
		SET::iterator it;
		printf("����f("); dispset(V); printf(",%d)\n",i);
		for (it=V.begin();it!=V.end();++it)	//ɨ�輯��V�еĶ���j
		{
			SET tmpV=V;
			int j=*it;
			tmpV.erase(j);					//tmpV=V-{j}
			int pathlen1=f(tmpV,j);
			int pathlen=pathlen1+g.edges[j][i];
			printf("    f("); dispset(tmpV); printf(",%d )",j); printf(",pathlen1=%d\n",pathlen1);
			minpathlen=min(minpathlen,pathlen);
		}
		printf("���f("); dispset(V); printf(",%d),minpathlen=%d\n",i,minpathlen);
		return minpathlen;
	}
}
void main()
{
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},{6,0,8,5},{8,9,0,5},{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���g
	SET V;
	for (int i=1;i<g.n;i++)				//����1,2,3����
		V.insert(i);
	printf("TSP·������=%d\n",f(V,s));	//���23
}
