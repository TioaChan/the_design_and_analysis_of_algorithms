//�ݹ�������������
#include <stdio.h>
#define MAXK 10
int a[MAXK];					//���һ�����
int n,k;						//ȫ�ֱ���
void dispacomb()				//���һ�����
{
	for (int i=0;i<k;i++)
		printf("%3d",a[i]);
	printf("\n");
}
void comb(int n,int k)	//��1..n��k�����������
{
	if (k==0)					//kΪ0ʱ���һ�����
		dispacomb();
	else
	{	for (int i=k;i<=n;i++)
		{	a[k-1]=i;			//a[k-1]λ��ȡk��n������
			comb(i-1,k-1); 	//a[k-1]���a[0..i-1]�е�k-1����������һ�����
		}
	}
}
void main()
{	
	n=5; k=3;
	printf("1..%d��%d�����������������:\n",n,k);
	comb(n,k);
}
