#include <stdio.h>
#include <vector>
using namespace std;
#define INF 99999					//���ɱ�ֵ
#define MAXN 21
//�����ʾ
int n=4;
int c[MAXN][MAXN]={ {9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4} };
vector<vector<int> > ps;						//���ȫ����
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
void Allocate(int n,int &mini,int &mincost)	//�����������������ŷ���
{
	Perm(n);						//���ȫ����ps
	for (int i=0;i<ps.size();i++)	//��ÿ�������ĳɱ�
	{
		int cost=0;
		for (int j=0;j<ps[i].size();j++)
			cost+=c[j][ps[i][j]-1];
		if (cost<mincost)				//�Ƚ�����С�ɱ��ķ���
		{
			mincost=cost;
			mini=i;
		}
	}
}
void main()
{
	int mincost=INF,mini;		//mincostΪ��С�ɱ�,miniΪps�����ŷ������
	Allocate(n,mini,mincost);
	printf("���ŷ���:\n");
	for (int k=0;k<ps[mini].size();k++)
		printf("   ��%d���˰�������%d\n",k+1,ps[mini][k]);
	printf("   �ܳɱ�=%d\n",mincost);
}






