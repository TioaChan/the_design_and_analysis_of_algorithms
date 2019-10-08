#include <stdio.h>
#include <algorithm> 
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define N 100
//�����ʾ
int n=4;
int a[N]={5,12,4,8};				//��ӦM1��ʱ��
int b[N]={6,2,14,7};				//��ӦM2��ʱ��
struct NodeType
{
	int no;							//��ҵ���
    bool group;						//1�����һ��N1,0����ڶ���N2
    int time;						//a,b����Сʱ��
	bool operator<(const NodeType &s) const
	{
		return time<s.time;			//��time��������
	}
};
//�������ʾ
int best[N];							//���ŵ�������
void display(NodeType c[])
{
	int i;
	printf("c:\n");
	printf("��ҵ��\t");
	for (i=0;i<n;i++)
		printf("%d\t",c[i].no);
	printf("\n");

	printf("M1ʱ��\t");
	for (i=0;i<n;i++)
		printf("%d\t",a[c[i].no]);
	printf("\n");

	printf("M2ʱ��\t");
	for (i=0;i<n;i++)
		printf("%d\t",b[c[i].no]);
	printf("\n");

	printf("���\t");
	for (i=0;i<n;i++)
		printf("%d\t",c[i].group);
	printf("\n");

	printf("time\t");
	for (i=0;i<n;i++)
		printf("%d\t",c[i].time);
	printf("\n");
}
int solve()								//�����ˮ��ҵ��������
{
	int i,j,k;
	NodeType c[N];
	for(i=0;i<n;i++)					//n����ҵ��,���ÿ����ҵ����С�ӹ�ʱ�� 
	{
		c[i].no=i;
		c[i].group=(a[i]<=b[i]);		//a[i]<=b[i]��Ӧ��1��N1,a[i]>b[i]��Ӧ��0��N2
		c[i].time=a[i]<=b[i]?a[i]:b[i];	//��1����a[i],��0����b[i]
	}
	printf("����ǰ��c����Ԫ��\n"); display(c);
	sort(c,c+n);						//cԪ�ذ�time��������
	printf("������c����Ԫ��\n"); display(c);
	j=0; k=n-1;
	for(i=0;i<n;i++)					//ɨ��c����Ԫ��,�������ŵ��ȷ���
	{
		if(c[i].group==1)				//��1��,��time�������з���best��ǰ�沿��
			best[j++]=c[i].no;
		else							//��0��,��time�ݼ����зŵ�best�ĺ��沿��
			best[k--]=c[i].no;
	}
	int f1=0;						//�ۼ�M1�ϵ�ִ��ʱ��
	int f2=0;							//���ŵ����µ�������ʱ��
	for(i=0;i<n;i++)
	{
		f1+=a[best[i]];
		f2=max(f2,f1)+b[best[i]];
    }
	return f2;
}
void main()
{
	printf("�����\n");
	printf("    ��ʱ��: %d\n",solve());	//���:33
	printf("    ���ȷ���: ");
	for(int i=0;i<n;i++)
		printf("%d ",best[i]+1);		//���:3 1 4 2
	printf("\n");
}

