//���0/1��������
#include <stdio.h>
#include <vector>
using namespace std;
vector<vector<int> > ps;				//����ݼ�
void PSet(int n)						//��1��n���ݼ�ps
{	vector<vector<int> > ps1;			//���ݼ�
	vector<vector<int> >::iterator it;	//�ݼ�������
	vector<int> s,s1;
	ps.push_back(s);					//���{}�ռ���Ԫ��
	for (int i=1;i<=n;i++)				//ѭ�����1��n
	{	ps1=ps;						//ps1�����һ���õ����ݼ�
		for (it=ps1.begin();it!=ps1.end();++it)
			(*it).push_back(i);		//��ps1��ÿ������Ԫ��ĩβ���i
		for (it=ps1.begin();it!=ps1.end();++it)
			ps.push_back(*it);			//��ps1��ÿ������Ԫ����ӵ�ps��
	}
}
void Knap(int w[],int v[],int W)	//�����еķ�������ѷ���
{
	int count=0;						//�������
	int sumw,sumv;						//��ǰ���������������ܼ�ֵ
	int maxi,maxsumw=0,maxsumv=0;		//���ŷ����ı�š����������ܼ�ֵ
	vector<vector<int> >::iterator it;	//�ݼ�������
	vector<int>::iterator sit;			//�ݼ�����Ԫ�ص�����
	printf("  ���\tѡ����Ʒ\t������\t�ܼ�ֵ\t�ܷ�װ��\n");
	for (it=ps.begin();it!=ps.end();++it)	//ɨ��ps��ÿһ������Ԫ��
	{
		printf("  %d\t",count+1);
		sumw=sumv=0;
		printf("{");
		for (sit=(*it).begin();sit!=(*it).end();++sit)
		{	printf("%d ",*sit);
			sumw+=w[*sit-1];
			sumv+=v[*sit-1];
		}
		printf("}\t\t%d\t%d  ",sumw,sumv);
		if (sumw<=W)
		{	printf("��\n");
			if (sumv>maxsumv)		//�Ƚ������ŷ���
			{	maxsumw=sumw;
				maxsumv=sumv;
				maxi=count;
			}
		}
		else printf("��\n");
		count++;
	}
	printf("��ѷ���Ϊ: ");
	printf("ѡ����Ʒ");
	printf("{ ");
	for (sit=ps[maxi].begin();sit!=ps[maxi].end();++sit)
		printf("%d ",*sit);
	printf("},");
	printf("������:%d,�ܼ�ֵ:%d\n",maxsumw,maxsumv);
}
void main()
{	int n=4,W=6;
	int w[]={5,3,2,1};
	int v[]={4,4,3,1};
	PSet(n);
	printf("0/1��������ⷽ��\n",n);
	Knap(w,v,W);
}
