//����ݼ�����-�ⷨ2
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > ps;				//����ݼ�
void PSet(int n)						//��1��n���ݼ�ps
{
	vector<vector<int> > ps1;			//���ݼ�
	vector<vector<int> >::iterator it;	//�ݼ�������
	vector<int> s,s1;
	ps.push_back(s);				//���{}
	for (int i=1;i<=n;i++)				//ѭ�����1��n
	{
		ps1=ps;
		for (it=ps1.begin();it!=ps1.end();++it)
			(*it).push_back(i);		//��ps1��ÿ������Ԫ��ĩβ���i
		for (it=ps1.begin();it!=ps1.end();++it)
			ps.push_back(*it);		//��ps1��ÿ������Ԫ����ӵ�ps��
	}
}
void dispps()					//����ݼ�ps
{
	vector<vector<int> >::iterator it;	//�ݼ�������
	vector<int>::iterator sit;			//�ݼ�����Ԫ�ص�����
	for (it=ps.begin();it!=ps.end();++it)
	{
		printf("{ ");
		for (sit=(*it).begin();sit!=(*it).end();++sit)
			printf("%d ",*sit);
		printf("} ");
	}
	printf("\n");
}
void main()
{	int n=3;
	PSet(n);
	printf("1��%d���ݼ�:\n  ",n);
	dispps();
}

