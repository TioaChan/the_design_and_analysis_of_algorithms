//ð�������㷨
#include <stdio.h>
void disp(int a[],int n)			//���a������Ԫ��
{	int i;
	for (i=0;i<n;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void BubbleSort(int a[],int n,int i)
{	int j,tmp;
	bool exchange;
	if (i==n-1) return;			//����ݹ��������
	else
	{	exchange=false;			//��exchangeΪfalse
		for (j=n-1;j>i;j--)		//��a[i..n-1]����СԪ�ط���a[i]��
			if (a[j]<a[j-1])		//������Ԫ�ط���ʱ
			{	tmp=a[j];			//a[j]��a[j-1]���н���,3��Ԫ���ƶ�����СԪ��ǰ��
				a[j]=a[j-1]; a[j-1]=tmp;
				exchange=true;	//����������exchangeΪtrue
			}
		if (exchange==false)		//δ��������ʱֱ�ӷ���
			return;
		else						//��������ʱ�����ݹ����
			BubbleSort(a,n,i+1);
	}
}
void main()
{	int n=10;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	printf("����ǰ:"); disp(a,n);
	BubbleSort(a,n,0);
	printf("�����:"); disp(a,n);
}
