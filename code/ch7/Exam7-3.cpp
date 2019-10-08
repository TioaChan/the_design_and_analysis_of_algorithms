#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 40001
//�����ʾ
int n;
struct NodeType  
{	int b;   					//�����ײ�
    	int e;   					//����β��
	bool operator<(const NodeType &s) const
	{	if (e==s.e)
			return b<s.b;
		return e<s.e;			//��e��������
	}
} A[MAX];
//�������ʾ
int ans;
void solve()
{	int t,i;
	for (i=0; i<n; i++)
		if (A[i].b>A[i].e)			//������β��,ʹ�ײ�С��β��   
		{	t=A[i].b;
			A[i].b=A[i].e;
			A[i].e=t;
		}
	sort(A,A+n);					//����
	int preend=A[0].e;
	ans=1;
	for(i=1; i<n; i++)
	{	if (A[i].b>preend)			//A[j]��ǰһ����ⲻ�ཻ
		{	ans++;
			preend=A[i].e;
		}
	}
	ans=n-ans;
}
int main()  
{	while(scanf("%d",&n)!=EOF)		//������Ŀ��ֻ��һ��������������ʵ�ʿ����ж��
	{	for(int i=0; i<n; i++)
			scanf("%d%d",&A[i].b,&A[i].e);
		solve();
		printf("%d\n",ans); 
	}
    	return 0;
}
