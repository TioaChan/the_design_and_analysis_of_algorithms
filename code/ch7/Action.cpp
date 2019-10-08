#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 51
//�����ʾ
struct Action
{	int b;						//���ʼʱ��
	int e;						//�����ʱ��
	bool operator<(const Action &s) const	//����<��ϵ����
	{
		return e<=s.e;			//���ڰ������ʱ���������
	}
};
int n=11;
Action A[]={{0},{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15}};	//�±�0����
//�������ʾ
bool flag[MAX];					//���ѡ��Ļ
int Count=0;					//ѡȡ�ļ��ݻ����
void solve()					//��������ݻ�Ӽ�
{
	memset(flag,0,sizeof(flag));//��ʼ��Ϊfalse
	sort(A+1,A+n+1);			//A[1..n]�������ʱ���������
	int preend=0;				//ǰһ�����ݻ�Ľ���ʱ��
	for (int i=1;i<=n;i++)
	{	if (A[i].b>=preend)
		{	flag[i]=true;		//ѡ��A[i]�
			preend=A[i].e;
		}
	}
}
void main()
{
	solve();
	printf("�����\n");
	printf("  ѡȡ�Ļ:");
	for (int i=1;i<=n;i++)
		if (flag[i])
		{
			printf("[%d,%d] ",A[i].b,A[i].e);
			Count++;
		}
	printf("\n  ��%d���\n",Count);
}
