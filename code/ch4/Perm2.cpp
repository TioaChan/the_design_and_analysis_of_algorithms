//�ݹ����ȫ��������
#include <stdio.h>
#include <vector>
using namespace std;
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
void Perm(int i,int n)					//��1��n��ȫ����ps
{
	vector<vector<int> >::iterator it;			//ȫ���е�����
	if (i<=n)
	{
		vector<vector<int> > ps1;				//��ʱ���������
		for (it=ps.begin();it!=ps.end();++it)
			Insert(*it,i,ps1);			//��ÿ������Ԫ���м����i�õ�ps1
		ps=ps1;
		Perm(i+1,n);					//�����������i+1
	}
}
void dispps()									//���ȫ����ps
{	vector<vector<int> >::reverse_iterator it;	//ȫ���еķ��������
	vector<int>::iterator sit;					//���м���Ԫ�ص�����
	for (it=ps.rbegin();it!=ps.rend();++it)
	{	for (sit=(*it).begin();sit!=(*it).end();++sit)
			printf("%d",*sit);
		printf("  ");
	}
	printf("\n");
}
void main()
{
	int n=3;
	printf("1��%d��ȫ��������:\n  ",n);
	vector<int> s;
	s.push_back(1);
	ps.push_back(s);			//��ʼ��psΪ{{1}}
	Perm(2,n);
	dispps();
}
