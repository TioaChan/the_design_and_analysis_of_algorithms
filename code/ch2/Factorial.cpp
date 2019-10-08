//��n!�ĵݹ�ͷǵݹ��㷨
#include <stdio.h>
#include <stack>
using namespace std;

int fun(int n)				//��n!�ĵݹ��㷨
{	if (n==1)				//���1
		return(1);			//���2
	else					//���3
		return(fun(n-1)*n);	//���4
}

int fun1(int n)				//��n!�ķǵݹ��㷨
{
	int f=1,i;
	for (i=2;i<=n;i++)
		f=f*i;
	return(f);
}
typedef struct
{	int n;				//����nֵ
	int f;				//����f(n)ֵ
	int tag;			//��ʶ�Ƿ����f(n)ֵ,1:δ���,0:�����
} NodeType;				//ջԪ������

int fun2(int n)			//n!�ĵݹ��㷨ת���ķǵݹ��㷨
{
	NodeType e,e1,e2;
	stack<NodeType> st;
	e.n=n;
	e.tag=1;
	st.push(e);							//��ֵ��ջ
	while (!st.empty())					//ջ����ʱѭ��
	{
		if (st.top().tag==1)			//δ�����ջ��Ԫ�ص�fֵ
		{
			if (st.top().n==1)			//(1)ʽ
			{
				st.top().f=1;
				st.top().tag=0;
			}
			else						//(2)ʽ�ֽ����
			{
				e1.n=st.top().n-1;
				e1.tag=1;
				st.push(e1);			//������(n-1)!��ջ
			}
		}
		else 							//st.top().tag=0���Ѽ����fֵ
		{
			e2=st.top();
			st.pop();					//��ջe2
			st.top().f=st.top().n*e2.f;	//(2)ʽ��ֵ����
			st.top().tag=0;				//��ʾջ��Ԫ�ص�fֵ�����
		}
		if (st.size()==1 && st.top().tag==0) //ջ��ֻ��һ�������f��Ԫ��ʱ�˳�ѭ��
			break;
	}
	return(st.top().f);
}
void main()
{
	int n=6;
	printf(" fun�Ľ��:fun(%d) =%d\n",n,fun(n));
	printf("fun1�Ľ��:fun1(%d)=%d\n",n,fun1(n));
	printf("fun2�Ľ��:fun2(%d)=%d\n",n,fun2(n));
}