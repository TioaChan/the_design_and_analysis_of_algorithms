#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAX 51
//�����ʾ
struct Cow						//��ţ����������
{
	int no;						//ţ���
	int b;						//���ʼʱ��
	int e;						//�����ʱ��
	bool operator<(const Cow &s) const	//����<��ϵ����
	{
		if (e==s.e)				//����ʱ����ͬ����ʼʱ���������
			return b<=s.b;
		else					//���򰴽���ʱ���������
			return e<=s.e;
	}
};
int n=5;
Cow A[]={{0},{1,1,10},{2,2,4},{3,3,6},{4,5,8},{5,4,7}};	//�±�0����
//�������ʾ
int ans[MAX];							//ans[i]��ʾ��A[i].noͷţ���������
void solve()							//��������ݻ�Ӽ�
{
	sort(A+1,A+n+1);					//A[1..n]��ָ����ʽ����
	memset(ans,0,sizeof(ans));			//��ʼ��Ϊ0
	int num=1;							//�������
	for (int i=1;i<=n;i++)				//i��j��Ϊ�������±�
	{
		if (ans[i]==0)					//��iͷţ��û�а�������
		{
			ans[i]=num;					//��iͷţ��������num
			int preend=A[i].e;			//ǰһ�����ݻ�Ľ���ʱ��
			for (int j=i+1;j<=n;j++)	//����һ�������ݻ�Ӽ�
			{
				if (A[j].b>preend && ans[j]==0)
				{
					ans[j]=num;			//��һ�����ݻ�Ӽ������л������num������
					preend=A[j].e;		//���½���ʱ��
				}
			}
			num++;						//������һ�������ݻ�Ӽ�,num��1
		}
	}
}
void dispa()
{
	printf("  i   ���  ��ʼʱ��  ����ʱ��\n");
	for (int i=1;i<=n;i++)
		printf("  %d     %d    [ %d        %d ]\n",i,A[i].no,A[i].b,A[i].e);
}
void dispb()
{
	dispa();
	printf("ans:\n");
	for (int j=1;j<=n;j++)
		printf("    ans[%d]=%d\n",j,ans[j]);
}

void main()
{
	printf("����ǰA:\n"); dispa();
	solve();
	printf("�����A:\n"); dispb();
	printf("�����\n");
	for (int i=1;i<=n;i++)
		printf("    ţ%d���ŵ�����: %d\n",A[i].no,ans[i]);
}
