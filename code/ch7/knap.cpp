//��ⱳ��������㷨
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 51
//�����ʾ
int n=5;
double W=100;					//����
struct NodeType
{
	double w;
	double v;
	double p;					//p=v/w
	bool operator<(const NodeType &s) const
	{
		return p>s.p;			//��p�ݼ�����
	}
};
NodeType A[]={{0},{10,20},{20,30},{30,66},{40,40},{50,60}};	//�±�0����
//�������ʾ
double V;						//����ֵ
double x[MAXN];
void Knap()						//��ⱳ�����Ⲣ�����ܼ�ֵ
{
	V=0;						//V��ʼ��Ϊ0
	double weight=W;			//��������װ�����������
	memset(x,0,sizeof(x));		//��ʼ��x����
	int i=1;
	while (A[i].w<weight)		//��Ʒi�ܹ�ȫ��װ��ʱѭ��
	{	x[i]=1;					//װ����Ʒi
		weight-=A[i].w;			//���ٱ�������װ�����������
		V+=A[i].v;				//�ۼ��ܼ�ֵ
		i++;					//����ѭ��
	}
	if (weight>0)				//��������������0
	{	x[i]=weight/A[i].w;		//����Ʒi��һ����װ��
		V+=x[i]*A[i].v;			//�ۼ��ܼ�ֵ
	}
}
void dispA()					//���A
{
	int i;
	printf("\tW\tV\tV/W\n");
	for (i=1;i<=n;i++)
		printf("\t%g\t%g\t%3.1f\n",A[i].w,A[i].v,A[i].p);
}
void main()
{
	printf("������\n");
	for (int i=1;i<=n;i++)			//��v/w
		A[i].p=A[i].v/A[i].w;
	printf("(1)����ǰ\n");dispA();
	sort(A+1,A+n+1);				//����
	printf("(2)�����:\n"); dispA();
	Knap();
	printf("(3)�����\n");		//������
	printf("    x: [");
	for (int j=1;j<n;j++)
		printf("%g, ",x[j]);
	printf("%g]\n",x[n]);
	printf("    �ܼ�ֵ=%g\n",V);
}
