#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAX 101
//�����ʾ
struct NodeType
{
	int b;							//��ʼʱ��
	int e;							//����ʱ��
	int length;						//������ִ��ʱ��
    bool operator < (const NodeType t) const
    {	//�����������������غ���
		return e<t.e;				//������ʱ���������
    }
};
int n=11;							//��������
NodeType A[MAX]={{1,4},{3,5},{0,6},{5,7},{3,8},{5,9},{6,10},{8,11},{8,12},{2,13},{12,15}};	//��Ŷ���
//�������ʾ
int dp[MAX];					//��̬�滮����
int pre[MAX];					//pre[i]���ǰ���������

void solve()					//��dp��pre
{
	memset(dp,0,sizeof(dp));	//dp�����ʼ��
	stable_sort(A,A+n);			//�����ȶ��������㷨
	dp[0]=A[0].length;
	pre[0]=-1;
	for (int i=1;i<n;i++)
	{
		int low=0, high=i-1;
		while(low<=high)		//��A[0..i-1]�в��ҽ���ʱ������A[i]��ʼʱ���������A[low-1]
		{
			int mid=(low+high)/2;
			if(A[mid].e<=A[i].b)
				low=mid+1;
			else
				high=mid-1;
		}
		if (low==0)				//�������
		{
			if(dp[i-1]>=A[i].length)
			{
				dp[i]=dp[i-1];
				pre[i]=-2;		//��ѡ�ж���i
			}
			else
			{
				dp[i]=A[i].length;
				pre[i]=-1;		//û��ǰ������
			}
		}
		else					//A[i]ǰ�������м��ݶ���A[low-1]
		{
			if (dp[i-1]>=dp[low-1]+A[i].length)
			{
				dp[i]=dp[i-1];
				pre[i]=-2;		//��ѡ�ж���i
			}
			else
			{
				dp[i]=dp[low-1]+A[i].length;
				pre[i]=low-1;	//ѡ�ж���i
			}
		}
	}
}
void Dispasolution()			//���һ��ѡ��Ķ�������
{	vector<int> res;
	int i=n-1;					//��n-1��ʼ

	while (true)
	{
		if (i==-1)				//A[i]û��ǰ������
			break;
		if (pre[i]==-2)			//��ѡ��A[i]
			i--;
		else					//ѡ��A[i]
		{
			res.push_back(i);
			i=pre[i];
		}
	}
	vector<int>::reverse_iterator it;
	printf("    ѡ��Ķ���: ");
	for (it=res.rbegin();it!=res.rend();++it)
		printf("%d[%d, %d] ",*it,A[*it].b,A[*it].e);
	printf("\n");
	printf("    ���ݶ�������ʱ��: %d\n",dp[n-1]);
}
int main()
{
	for (int i=0; i<n; i++)		//�󶩵��ĳ���
		A[i].length=A[i].e-A[i].b;
	solve();
	printf("�����\n");
	Dispasolution();
    return 0;
}
