//��̬�滮���TSP����
#include "Graph.cpp"
#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
#define min(x,y) ((x)<(y)?(x):(y))
typedef set< int > SET;						//����set<int>��ʾ���㼯��
//�����ʾ
int s=0;									//ָ�����Ϊ0
MGraph g;									//ͼ���ڽӾ���
int f(SET V,int i)							//��TSP���н��·������
{
	int minpathlen=INF;						//���·������
	if (V.size()==0)						//��VΪ��ʱ
		return g.edges[0][i];
	else									//��VΪ����ʱ
	{
		SET::iterator it;
		for (it=V.begin();it!=V.end();++it)	//ɨ�輯��V�еĶ���j
		{
			SET tmpV=V;
			int j=*it;
			tmpV.erase(j);					//tmpV=V-{j}
			int pathlen=f(tmpV,j)+g.edges[j][i];
			minpathlen=min(minpathlen,pathlen);
		}
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
