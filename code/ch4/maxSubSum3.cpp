//���������������к�����-�ⷨ3
#include <stdio.h>
int maxSubSum3(int a[],int n)		//��a��������������к�
{	int i,maxSum=0,thisSum=0;
	for (i=0;i<n;i++)
	{	thisSum+=a[i];
		if (thisSum<0)		//����ǰ�����к�Ϊ�����������¿�ʼ��һ��������
			thisSum=0;
		if (maxSum<thisSum)	//�Ƚ���������������к�
			maxSum=thisSum;
	}
	return maxSum;
}
void main()
{
	int a[]={-2,11,-4,13,-5,-2};
	int n=sizeof(a)/sizeof(a[0]);
	int b[]={-6,2,4,-7,5,3,2,-1,6,-9,10,-2};
	int m=sizeof(b)/sizeof(b[0]);
	printf("a���е�������������еĺ�:%ld\n",maxSubSum3(a,n));	//���:20
	printf("b���е�������������еĺ�:%ld\n",maxSubSum3(b,m));	//���:16
}
