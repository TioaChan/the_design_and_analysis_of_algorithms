//��ѡ������
#include <stdio.h>
void swap(int &x,int &y)		//����x��y
{
	int tmp=x;
	x=y; y=tmp;
}
void SelectSort(int a[],int n)	//��a[0..n-1]Ԫ�ؽ��е�����ѡ������
{	int i,j,k;
	for (i=0;i<n-1;i++)			//����n-1������
	{	k=i;					//��k��¼ÿ������������СԪ�ص�λ��
		for (j=i+1;j<n;j++)		//��a[i+1..n-1]�в�����ٷ�����СԪ��a[k]
			if (a[j]<a[k]) 
				k=j;	
		if (k!=i)				//��a[k]������СԪ��,��a[k]��a[i]����
			swap(a[i],a[k]);
	}
}
void disp(int a[],int n)		//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{	int n=10;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	printf("����ǰ:"); disp(a,n);
	SelectSort(a,n);
	printf("�����:"); disp(a,n);
}
