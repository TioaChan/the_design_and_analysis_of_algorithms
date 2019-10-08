#include <stdio.h>
int BinSearch(int a[],int n,int x,int &i,int &j) 
{
	int mid,low,high;
	low=0; high=n-1;
	while(low<=high)		//��ǰ���京��һ���������ϵ�Ԫ��ʱ
	{
		mid=(high+low)/2;
		if(x==a[mid])		//�ҵ�Ϊx��Ԫ��a[mid]
		{
			i=j=mid;
			return mid; 
		}
		
		if(x<a[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	i=high; j=low;			//��Ӧʧ�ܽ��Ϊa[high..low](��low>high)
	return -1;
}
int BinSearch1(int a[],int n,int x)
{
	int mid,low=0,high=n-1;
	while (low<high)		//�������һ�����ϵ�Ԫ��
	{
		mid=(low+high)/2;
		if (x<=a[mid])
			high=mid;
		else
			low=mid+1;
	}
	if (low>high)			//����Ϊ�գ�û���ҵ�x
		return -1;
	else if(a[low]!=x)		//���䲻�գ�һ��Ԫ�ز�Ϊx
		return -1;
	else					//���䲻�գ�һ��Ԫ��ǡ��Ϊx
		return low;
}
int BinSearch2(int a[],int n,int x)
{
	int mid,low=0,high=n-1;
	while (low<high)		//�������һ�����ϵ�Ԫ��
	{
		mid=(low+high+1)/2;
		if (x>=a[mid])
			low=mid;
		else
			high=mid-1;
	}
	printf("low=%d,high=%d\n",low,high);
	if (low>high) return -1;
	else if(a[low]!=x)
		return -1;
	else
		return low;
}
int main() 
{
	int i,j,ret;
	int x=2 ;
	int a[]={1,2,2,4,5,5};
	int n=sizeof(a)/sizeof(a[0]);
	ret=BinSearch2(a,n,x);
	printf("ret=%d\n",ret);
	return 0;
} 