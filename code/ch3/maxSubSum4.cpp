//���������������к͵��㷨
#include <stdio.h>
long max3(long a,long b,long c)				//�������long�е����ֵ
{	if (a<b) a=b;							//��a����a��b�е����ֵ
	if (a>c) return a;						//�ȽϷ���a��c�е����ֵ
	else return c;  
} 
long maxSubSum4(int a[],int left,int right)	//��a[left..high]������������������к�
{	int i,j;
	long maxLeftSum,maxRightSum;
	long maxLeftBorderSum,leftBorderSum;
	long maxRightBorderSum,rightBorderSum;
	if (left==right)						//������ֻ��һ��Ԫ��ʱ
	{	if (a[left]>0) 					//��Ԫ�ش���0ʱ������
			return a[left];
		else								//��Ԫ��С�ڻ����0ʱ����0
			return 0; 
	} 
	int mid=(left+right)/2;					//���м�λ��
	maxLeftSum=maxSubSum4(a,left,mid);		//����ߵ��������������֮��
	maxRightSum=maxSubSum4(a,mid+1,right);	//���ұߵ��������������֮��
	maxLeftBorderSum=0,leftBorderSum=0;
	for (i=mid;i>=left;i--)		//�������߼���a[mid]Ԫ�ع��ɵ����е�����
	{	leftBorderSum+=a[i];
		if (leftBorderSum>maxLeftBorderSum)
			maxLeftBorderSum=leftBorderSum;
	}
	maxRightBorderSum=0,rightBorderSum=0;
	for (j=mid+1;j<=right;j++)	//������ұ߼���a[mid]Ԫ�ع��ɵ����е�����
	{	rightBorderSum+=a[j];
		if (rightBorderSum>maxRightBorderSum)
			maxRightBorderSum=rightBorderSum;
	}
	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum); 
} 
void main()
{	int a[]={-2,11,-4,13,-5,-2},n=6;
	int b[]={-6,2,4,-7,5,3,2,-1,6,-9,10,-2},m=12;
	printf("a���е�������������еĺ�:%ld\n",maxSubSum4(a,0,n-1));
	printf("b���е�������������еĺ�:%ld\n",maxSubSum4(b,0,m-1));
}
