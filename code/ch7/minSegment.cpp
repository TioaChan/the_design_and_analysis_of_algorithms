//������串��������㷨
#include <stdio.h>
#define MaxSize 10
#include "QuickSort.cpp"		//�������������㷨
int minSegment(int x[],int n,int k,int y[])	//��x����󸲸����伯��y
{	int i,m=0,tmp;			//mΪy���±꣬��0��ʼ
	QuickSort(x,0,n-1);		//���ÿ��������㷨��x���е�������
	tmp=x[0];					//�������ʼλ��
	y[0]=x[0];
	for(i=1;i<n;i++)
		if(x[i]-tmp>k)		//���x[i]��tmp�ľ������k
		{	tmp=x[i];			//��ʼ��һ����x[i]Ϊ���ĸ�������
			m++; y[m]=x[i];
		}
	return m+1;
}
void disp(int x[],int n)		//���x�е�Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void main()
{	int x[]={2,4,1,6,-2,5,3};
	int y[MaxSize];
	int n=7,k=3,m;
	printf("����ǰ:"); disp(x,n);
	QuickSort(x,0,n-1);
	printf("�����:"); disp(x,n);
	m=minSegment(x,n,k,y);
	printf("�����:\n");
	printf("ѡȡ������Ϊ%d��\n",m);
	printf("ѡȡ������:"); disp(y,m);
}
