//���n�ʺ�����
#include <stdio.h>
#include <stdlib.h>
#define N 20					//���ʺ����
int q[N];						//��Ÿ��ʺ����ڵ��к�,��(i,q[i])Ϊһ���ʺ�λ��
int count=0;					//�ۼƽ����
void dispasolution(int n)		//���n�ʺ������һ����
{
	printf("    ��%d���⣺",++count);
	for (int i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
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
void queen(int i,int n)			//����1��i�Ļʺ�
{	if (i>n) 
		dispasolution(n);		//���лʺ���ý���
	else
	{
		for (int j=1;j<=n;j++)		//�ڵ�i������̽ÿһ����j
			if (place(i,j))			//�ڵ�i�����ҵ�һ������λ��(i,j)
			{	q[i]=j;
				queen(i+1,n);
			}
	}
}
void main()
{	int n;					//nΪ���ʵ�ʻʺ����
	printf(" �ʺ�����(n<20) n=");
	scanf("%d",&n);
	if (n>20)
		printf("nֵ̫��,�������\n");
	else
	{	printf("%d�ʺ�����������£�\n",n);
		queen(1,n);					//����1��i�Ļʺ�
	}
}
