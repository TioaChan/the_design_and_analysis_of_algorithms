#include <stdio.h>
#include <string.h>
#define MAX 101
//�����ʾ
int n=8,m=3;
int relation[][2]={{1,2},{2,3},{4,8}};		//���ѹ�ϵ

//���鼯�Ļ��������㷨
typedef struct node
{	int data;							//����Ӧ������
	int rank;							//����Ӧ��
	int parent;							//����Ӧ˫���±�
} UFSTree;								//���鼯���Ľ������
void MAKE_SET(UFSTree t[],int n)		//��ʼ�����鼯��
{ 	for (int i=1;i<=n;i++)				//������Ϊ0��(n-1)
	{	t[i].rank=0;					//�ȳ�ʼ��Ϊ0
		t[i].parent=i;					//˫�׳�ʼ��ָ������
	}
}
int FIND_SET(UFSTree t[],int x)			//��x���������в��Ҽ��ϱ��
{	if (x!=t[x].parent)					//��˫�ײ�������
		return(FIND_SET(t,t[x].parent));	//�ݹ���˫������x
	else
		return(x);						//��˫��������,����x
}
void UNION(UFSTree t[],int x,int y)		//��x��y���ڵ������ϲ�
{	x=FIND_SET(t,x);
	y=FIND_SET(t,y);
	if (t[x].rank>t[y].rank)			//x�����ȴ���y������
		t[y].parent=x;				//��x�����Ϊy��˫�׽��
	else								//y�����ȴ��ڵ���x������
	{ 	t[x].parent=y;				//��y�����Ϊx��˫�׽��
		if (t[x].rank==t[y].rank)		//x��y��������ͬ
			t[y].rank++;				//y��������1
	}
}
int solve()						//������Ȧ����
{
	int sum=0,i;
	UFSTree t[MAX];
	MAKE_SET(t,n);
	for (i=0;i<m;i++)
		UNION(t,relation[i][0],relation[i][1]);
	for(i=1;i<=n;i++)
		if (FIND_SET(t,i)==i && t[i].rank!=0)
			sum++;				//������i�ĸ�Ϊi������rank!=0,��Ӧһ������Ȧ
	return sum;
}
void main()
{
	printf("%d\n",solve());		//�������Ȧ����
}
