#include <stdio.h>
int Findk(int a[],int n,int b[],int m, int k) //在两个升序排序的数组中找到第k大的元素
{	if (k<0) return -1;
	if (n>m)					//用于保证n<=m,即保证前一个数组元素较少
		return Findk(b,m,a,n,k);
	if (n==0)
		return b[k-1];
	if (k==1)
		return ((a[0]>=b[0]) ? b[0]:a[0]);
	int numa=(n>=k/2)?k/2:n;  		//当数组没有k/2个元素时取n
	int numb=k-numa; 
	if (a[numa-1]==b[numb-1])
		return a[numa-1];
	else if (a[numa-1]>b[numb-1])
		return Findk(a,n,&b[numb],m-numb,k-numb);
	else if(a[numa-1]<b[numb-1])
		return Findk(&a[numa],n-numa,b,m,k-numa);
}
void main() 
{
	int i,result;
    int a[]={1,5,8}; 
    int b[]={2,3,4,6,7};
	int n=sizeof(a)/sizeof(a[0]);
	int m=sizeof(b)/sizeof(b[0]);
	printf("求解结果:\n");
	for(i=1;i<=n+m;i++)
	{
		result=Findk(a,n,b,m,i);
		printf("  第%d大的元素是:%d\n",i,result);
	}
}