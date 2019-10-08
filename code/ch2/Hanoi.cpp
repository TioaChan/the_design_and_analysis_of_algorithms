//Hanoi����ĵݹ�ͷǵݹ��㷨
#include <stdio.h>
#include <stack>
using namespace std;

void Hanoi(int n,char x,char y,char z)		//�ݹ��㷨
{
	if (n==1)
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,x,z);
	else
	{
		Hanoi(n-1,x,z,y);
		printf("\t����%d����Ƭ��%c�ƶ���%c\n",n,x,z);
		Hanoi(n-1,y,x,z);
	}
}

typedef struct
{	int n;			//����nֵ
	char x,y,z;		//����f(n)ֵ
	int tag;		//��ʶ�Ƿ����f(n)ֵ,1:δ���,0:�����
} NodeType;			//ջԪ������

void Hanoi1(int n,char x,char y,char z)	//�ǵݹ��㷨
{
	NodeType e,e1,e2,e3;
	stack<NodeType> st;
	e.n=n;
	e.x=x; e.y=y; e.z=z;
	e.tag=1;
	st.push(e);					//��ֵ��ջ
	while (!st.empty())				//ջ����ѭ��
	{
		if (st.top().tag==1)	//������ֱ�Ӳ���ʱ
		{
			e=st.top();
			st.pop();			//��ջhanoi(n,x,y,z)
			e1.n=e.n-1;
			e1.x=e.y; e1.y=e.x; e1.z=e.z;
			if (e1.n==1)		//ֻ��һ����Ƭʱֱ�Ӳ���
				e1.tag=0;
			else				//������Ҫ�����ֽ�
				e1.tag=1;
			st.push(e1);		//������3��Hanoi(n-1,y,x,z)��ջ
			e2.n=e.n;
			e2.x=e.x; e2.z=e.z;
			e2.tag=0;
			st.push(e2);		//������2��move(n,x,z)��ջ
			e3.n=e.n-1;
			e3.x=e.x; e3.y=e.z; e3.z=e.y;
			if (e3.n==1)		//ֻ��һ����Ƭʱֱ�Ӳ���
				e3.tag=0;
			else				//������Ҫ�����ֽ�
				e3.tag=1;
			st.push(e3);		//������1��Hanoi(n-1,x,z,y)��ջ
		}
		else if	(st.top().tag==0)		//������ֱ�Ӳ���ʱ
		{
			printf("\t����%d����Ƭ��%c�ƶ���%c\n",st.top().n,st.top().x,st.top().z);
			st.pop();				//�ƶ���Ƭ����ջ
		}
	}
}
void main()
{
	int n=3;
	printf("n=%dʱHanoi(�ݹ�)�Ĳ�������:\n",n);
	Hanoi(3,'x','y','z');
	printf("n=%dʱHanoi(�ǵݹ�)�Ĳ�������:\n",n);
	Hanoi1(3,'x','y','z');
}