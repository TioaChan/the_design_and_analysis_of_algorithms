//�ݹ�����ݼ�����
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > ps;			//����ݼ�
void Inserti(int i)					//���ݼ�ps��ÿ������Ԫ�����i�����뵽ps��
{
	vector<vector<int> > ps1;			//���ݼ�
	vector<vector<int> >::iterator it;	//�ݼ�������
	ps1=ps;								//ps1���ԭ�����ݼ�
	for (it=ps1.begin();it!=ps1.end();++it)
		(*it).push_back(i);			//��ps1��ÿ������Ԫ��ĩβ���i
	for (it=ps1.begin();it!=ps1.end();++it)
		ps.push_back(*it);			//��ps1��ÿ������Ԫ����ӵ�ps��
}
void PSet(int i,int n)				//��1��n���ݼ�ps
{
	if (i<=n)
	{
		Inserti(i);					//��i���뵽�����Ӽ��в������Ӽ�
		PSet(i+1,n);				//�ݹ����
	}
}
void dispps()							//����ݼ�ps
{	vector<vector<int> >::iterator it;	//�ݼ�������
	vector<int>::iterator sit;			//�ݼ�����Ԫ�ص�����
	for (it=ps.begin();it!=ps.end();++it)
	{	printf("{ ");
		for (sit=(*it).begin();sit!=(*it).end();++sit)
			printf("%d ",*sit);
		printf("} ");
	}
	printf("\n");
}
void main()
{
	int n=3;
	vector<int> s;
	ps.push_back(s);
	PSet(1,n);			//��1��n���ݼ�ps
	printf("1��%d���ݼ�:\n  ",n);
	dispps();			//����ݼ�ps
}
