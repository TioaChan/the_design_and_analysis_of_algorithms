//��ѡ�������㷨
#include <stdio.h>
void disp(int a[],int n)		//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void SelectSort(int a[],int n,int i)
{	int j,k,tmp;
	if (i==n-1) return;			//����ݹ��������
	else
	{	k=i;					//k��¼a[i..n-1]����СԪ�ص��±�
		for (j=i+1;j<n;j++)		//��a[i..n-1]������СԪ��
			if (a[j]<a[k])
				k=j;
		if (k!=i)				//����СԪ�ز���a[i]
		{	tmp=a[i];			//a[i]��a[k]����
			a[i]=a[k]; a[k]=tmp;
		}
		SelectSort(a,n,i+1);
	}
}
void main()
{	int n=10;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	printf("����ǰ:"); disp(a,n);
	SelectSort(a,n,0);
	printf("�����:"); disp(a,n);
}
