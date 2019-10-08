//���������TSP����
#include "Graph.cpp"
#include <stdio.h>
#include <vector>
using namespace std;
//�����ʾ
int s=0;							//ָ�����Ϊ0
MGraph g;							//ͼ���ڽӾ���
//�����̱�ʾ
int Count=1;						//·�������ۼ�
vector<vector<int> > ps;			//���ȫ����
void Insert(vector<int> s,int i,vector<vector<int> > &ps1)
//��ÿ������Ԫ���м����i�õ�ps1
{	vector<int> s1;
	vector<int>::iterator it;
	for (int j=0;j<i;j++)						//��s(��i-1������)��ÿ��λ�ò���i
	{	s1=s;
		it=s1.begin()+j;						//�������λ��
		s1.insert(it,i);						//��������i
		ps1.push_back(s1);						//��ӵ�ps1��
	}
}
void Perm(int n)								//��1��n������ȫ����
{	vector<vector<int> > ps1;					//��ʱ���������
	vector<vector<int> >::iterator it;			//ȫ���е�����
	vector<int> s,s1;
	s.push_back(1);
	ps.push_back(s);							//���{1}����Ԫ��
	for (int i=2;i<=n;i++)						//ѭ�����1��n
	{	ps1.clear();							//ps1��Ų���i�Ľ��
		for (it=ps.begin();it!=ps.end();++it)
			Insert(*it,i,ps1);					//��ÿ������Ԫ���м����i�õ�ps1
		ps=ps1;
	}
}
void TSP(MGraph g,int s)						//�����������TSP����
{
	vector<int> minpath;						//�������·��
	int minpathlen=INF;							//�������·������
	Perm(g.n-1);								//����1��n-1��ȫ����ps
	vector<vector<int> >::reverse_iterator it;	//ȫ���еķ��������
	vector<int> apath;
	int pathlen;
	printf("���Ϊ%d��ȫ��·��\n",s);
	for (it=ps.rbegin();it!=ps.rend();++it)		//����ps�е�ÿ������
	{
		pathlen=0;
		int initv=s;
		apath=(*it);
		for (int i=0;i<(*it).size();i++)		//����һ��������Ϊ·���ĳ���
		{
			pathlen+=g.edges[initv][(*it)[i]];
			initv=(*it)[i];
		}
		pathlen+=g.edges[initv][s];
		if (pathlen<INF)						//����·��ʱ
		{
			printf("   ·��%d:",Count++);
			printf("0��");
			for (i=0;i<apath.size();i++)		//���һ��·��
				printf("%d��",apath[i]);
			printf("%d   ·������: %d\n",0,pathlen);
			if (pathlen<minpathlen)				//�Ƚ������·��
			{
				minpathlen=pathlen;
				minpath=apath;
			}
		}
	}
	printf("���Ϊ%d�����·��\n",s);			//������·��	
	printf("   ���·������: %d\n",minpathlen); 
	printf("   ���·��: ");
	printf("0��");
	for (int j=0;j<minpath.size();j++)
		printf("%d��",minpath[j]);
	printf("%d\n",0);
}
void main()
{
	int A[][MAXV]={						//һ����Ȩ����ͼ
		{0,8,5,36},	{6,0,8,5},	{8,9,0,5},	{7,7,8,0}};
	int n=4,e=12;
	CreateMat(g,A,n,e);					//����ͼ���ڽӾ���g
	TSP(g,s);
}
