//�ݹ�ͷǵݹ��۰�����㷨
#include <stdio.h>
int BinSearch(int a[],int low,int high,int k) //�������㷨
{	int mid;
	if (low<=high)				//��ǰ�������Ԫ��ʱ
	{	mid=(low+high)/2;		//�����������м�λ��
		if (a[mid]==k)			//�ҵ��󷵻��������±�mid
			return mid;
		if (a[mid]>k)			//��a[mid]>kʱ,��a[low..mid-1]�еݹ����
			return BinSearch(a,low,mid-1,k);
		else					//��a[mid]<kʱ,��a[mid+1..high]�еݹ����
			return BinSearch(a,mid+1,high,k);
	}
	else	return -1;			//����ǰ��������û��Ԫ��ʱ����-1
}
int BinSearch1(int a[],int n,int k)	//�ǵݹ�������㷨
{	int low=0,high=n-1,mid;
	while (low<=high)			//��ǰ�������Ԫ��ʱѭ��
	{	mid=(low+high)/2;		//�����������м�λ��
		if (a[mid]==k)			//�ҵ��󷵻��������±�mid
			return mid;
		if (a[mid]>k)			//������a[low..mid-1]�в���
			high=mid-1;
		else					//a[mid]<k
			low=mid+1;			//������a[mid+1..high]�в���
	}
	return -1;					//����ǰ��������û��Ԫ��ʱ����-1
}
void main()
{	int n=10,i;
	int k=6;
	int a[]={1,2,3,4,5,6,7,8,9,10};
	i=BinSearch(a,0,n-1,k);
	if (i>=0)	printf("a[%d]=%d\n",i,k);
	else printf("δ�ҵ�%dԪ��\n",k);
}
