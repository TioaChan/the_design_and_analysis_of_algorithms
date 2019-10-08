#include <stdio.h>
#include <stdlib.h>				//��������������Ŀ⺯��
#include <time.h>
#define N 20					//���ʺ����
int q[N];						//��Ÿ��ʺ����ڵ��к�,��(i,q[i])Ϊһ���ʺ�λ��
int num=0;						//�ۼ����д���
void dispasolution(int n)		//���n�ʺ������һ����
{
	printf("  ��%d�������ҵ�һ����: ",num);
	for (int i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
int randa(int a,int b)	//����n��[a,b]�������
{
	return rand()%(b-a+1)+a;
}
bool place(int i,int j)			//����(i,j)λ���ܷ�ڷŻʺ�
{
	if (i==1) return true;		//��һ���ʺ����ǿ��Է���
	int k=1;
	while (k<i)					//k=1��i-1���ѷ����˻ʺ����
	{	if ((q[k]==j) || (abs(q[k]-j)==abs(i-k)))
			return false;
		k++;
	}
	return true;
}
bool queen(int i,int n)			//����1��i�Ļʺ�
{
	int count,j;
	if (i>n)
	{
		dispasolution(n);		//���лʺ���ý���
		return true;
	}
	else
	{
		count=0;				//��̽�����ۼ�
		while (count<=n)		//�����̽n��
		{
			j=randa(1,n);			//������i����1��n�е�һ�������j
			count++;
			if (place(i,j))	break;	//�ڵ�i�����ҵ�һ������λ��(i,j)
		}
		if (count>n) return false;
		q[i]=j;
		queen(i+1,n);
	}
}
void main()
{
	int n=6;						//nΪ���ʵ�ʻʺ����
	printf("%d�ʺ�����������£�\n",n);
	srand((unsigned)time(NULL));	//�������
	while (num<10)
	{
		if (queen(1,n))				//�ҵ�һ�����˳�
			break;
		num++;
		printf("  ��%d������û���ҵ���\n",num);
	}
}
