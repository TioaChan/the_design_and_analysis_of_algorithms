//����ݼ�����-�ⷨ1
#include <stdio.h>
#include <math.h>
#define MaxN 10
void inc(int b[], int n)		//��b��ʾ�Ķ���������1
{	for(int i=0;i<n;i++)		//��������b
	{	if(b[i])				//��Ԫ��1��Ϊ0
			b[i]=0;
		else					//��Ԫ��0��Ϊ1���˳�forѭ��
		{	b[i]=1;
			break;
		}
	}
}
void PSet(int a[],int b[],int n)	//���ݼ�
{	int i,k;
	int pw=(int)pow(2,n);			//��2^n
	printf("1��%d���ݼ�:\n  ",n);
	for(i=0;i<pw;i++)			//ִ��2^n��
	{	printf("{ ");
		for (k=0;k<n;k++)		//ִ��n��
			if(b[k])
				printf("%d ",a[k]);
		printf("} ");
		inc(b,n);				//b��ʾ�Ķ���������1
	}
	printf("\n");
}
void main()
{	int n=3;
	int a[MaxN],b[MaxN];
	for (int i=0;i<n;i++)
	{	a[i]=i+1;			//a��ʼ��Ϊ{1,2,3}
		b[i]=0;				//b��ʼ��Ϊ{0,0,0}
	}
	PSet(a,b,n);
}
