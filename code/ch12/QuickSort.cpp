//���������㷨
#include <stdio.h>
#include <stdlib.h>				//��������������Ŀ⺯��
#include <time.h>
void disp(int a[],int n)		//���a������Ԫ��
{
	for (int i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int Partition(int a[],int s,int t)	//�����㷨
{
	int i=s,j=t;
	int tmp=a[s];				//�����еĵ�1����¼��Ϊ��׼
	while (i!=j)				//���������˽������м�ɨ��,ֱ��i=jΪֹ
	{
		while (j>i && a[j]>=tmp) 
			j--;				//��������ɨ��,�ҵ�1���ؼ���С��tmp��a[j]
		a[i]=a[j];				//��a[j]ǰ�Ƶ�a[i]��λ��
		while (i<j && a[i]<=tmp) 
			i++;				//��������ɨ��,�ҵ�1���ؼ��ִ���tmp��a[i]
		a[j]=a[i];				//��a[i]���Ƶ�a[j]��λ��
	}
	a[i]=tmp;
	return i;
}
int randa(int a,int b)	//����n��[a,b]�������
{
	return rand()%(b-a+1)+a;
}
void swap(int &x,int &y)		//����x��y
{
	int tmp=x;
	x=y; y=tmp;
}
void QuickSort(int a[],int s,int t)	//��a[s..t]Ԫ�����н��е�������
{
	if (s<t) 					//���������ٴ���2��Ԫ�ص����
	{
		int j=randa(s,t);		//����[s,t]�������j
		swap(a[j],a[s]);		//��a[j]��Ϊ��׼
		int i=Partition(a,s,t);
		QuickSort(a,s,i-1);		//���������еݹ�����
		QuickSort(a,i+1,t);		//���������еݹ�����
	}
}
void main()
{
	int n=10;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	printf("����ǰ:"); disp(a,n);
	srand((unsigned)time(NULL));		//�������
	QuickSort(a,0,n-1);
	printf("�����:"); disp(a,n);
}
