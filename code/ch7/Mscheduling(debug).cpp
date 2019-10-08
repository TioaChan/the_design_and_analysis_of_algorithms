#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100
//�����ʾ
int n=7;
int m=3;
struct NodeType
{
	int no;							//��ҵ���
    int t;							//ִ��ʱ��
	int mno;						//�������
	bool operator<(const NodeType &s) const 
	{	return t>s.t;  }				//��tԽСԽ���ȳ���
};
struct NodeType A[]={{1,2},{2,14},{3,4},{4,16},{5,6},{6,5},{7,3}};
void solve()							//�������������
{
	NodeType e;
	if (n<=m)
	{	printf("Ϊÿһ����ҵ����һ̨����\n");
		return;
	}
	printf("  ����ǰ");
	for (int s=0;s<n;s++)
		printf(" [%d:%d]",A[s].no,A[s].t);
	printf("\n");
	sort(A,A+n);
	printf("  �����");
	for (s=0;s<n;s++)
		printf(" [%d:%d]",A[s].no,A[s].t);
	printf("\n");

	priority_queue<NodeType> qu;		//С����
	for (int i=0;i<m;i++)
	{
		A[i].mno=i+1;
		printf("  ������%d������ҵ%d,ִ��ʱ��Ϊ%2d,ռ��ʱ���:[%d,%d]\n",
				A[i].mno,A[i].no,A[i].t,0,A[i].t);
		qu.push(A[i]);
	}
	for (int j=m;j<n;j++)
	{
		e=qu.top(); qu.pop();			//����e
		printf("      ����:e.no=%d,e.t=%d,e.mno=%d\n",e.no,e.t,e.mno); 
		printf("  ������%d������ҵ%d,ִ��ʱ��Ϊ%2d,ռ��ʱ���:[%d,%d]\n",
				e.mno,A[j].no,A[j].t,e.t,e.t+A[j].t);
		e.t+=A[j].t;
		qu.push(e);						//e����
		printf("      ����:e.no=%d,e.t=%d,e.mno=%d\n",e.no,e.t,e.mno); 
	}
}
void main()
{
	printf("������ȷ���:\n");
	solve();
}
