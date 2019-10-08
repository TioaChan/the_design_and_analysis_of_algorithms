//求解最大连续子序列和的算法
#include <stdio.h>
long max3(long a,long b,long c)				//求出三个long中的最大值
{	if (a<b) a=b;							//用a保存a、b中的最大值
	if (a>c) return a;						//比较返回a、c中的最大值
	else return c;  
} 
long maxSubSum4(int a[],int left,int right)	//求a[left..high]序列中最大连续子序列和
{	int i,j;
	long maxLeftSum,maxRightSum;
	long maxLeftBorderSum,leftBorderSum;
	long maxRightBorderSum,rightBorderSum;
	if (left==right)						//子序列只有一个元素时
	{	if (a[left]>0) 					//该元素大于0时返回它
			return a[left];
		else								//该元素小于或等于0时返回0
			return 0; 
	} 
	int mid=(left+right)/2;					//求中间位置
	maxLeftSum=maxSubSum4(a,left,mid);		//求左边的最大连续子序列之和
	maxRightSum=maxSubSum4(a,mid+1,right);	//求右边的最大连续子序列之和
	maxLeftBorderSum=0,leftBorderSum=0;
	for (i=mid;i>=left;i--)		//求出以左边加上a[mid]元素构成的序列的最大和
	{	leftBorderSum+=a[i];
		if (leftBorderSum>maxLeftBorderSum)
			maxLeftBorderSum=leftBorderSum;
	}
	maxRightBorderSum=0,rightBorderSum=0;
	for (j=mid+1;j<=right;j++)	//求出以右边加上a[mid]元素构成的序列的最大和
	{	rightBorderSum+=a[j];
		if (rightBorderSum>maxRightBorderSum)
			maxRightBorderSum=rightBorderSum;
	}
	return max3(maxLeftSum,maxRightSum,maxLeftBorderSum+maxRightBorderSum); 
} 
void main()
{	int a[]={-2,11,-4,13,-5,-2},n=6;
	int b[]={-6,2,4,-7,5,3,2,-1,6,-9,10,-2},m=12;
	printf("a序列的最大连续子序列的和:%ld\n",maxSubSum4(a,0,n-1));
	printf("b序列的最大连续子序列的和:%ld\n",maxSubSum4(b,0,m-1));
}
