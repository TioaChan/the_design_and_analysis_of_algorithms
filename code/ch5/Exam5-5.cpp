//��5.5���㷨
#include <stdio.h>
void swap(int &x,int &y)			//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
void dispasolution(int a[],int n)	//���һ����
{
	printf("  (");
	for (int i=0;i<n-1;i++)
		printf("%d,",a[i]);
	printf("%d)",a[n-1]);
}
void dfs(int a[],int n,int i)		//��a[0..n-1]��ȫ����
{
	if (i>=n)							//�ݹ����
		dispasolution(a,n);
	else
	{	for (int j=i;j<n;j++)
		{	swap(a[i],a[j]);			//����a[i]��a[j]
			dfs(a,n,i+1);
			swap(a[i],a[j]);			//����a[i]��a[j]���ָ�
		}
	}
}
void main()
{
	int a[]={1,2,3,4};
	int n=sizeof(a)/sizeof(a[0]);
	printf("a��ȫ����\n");
	dfs(a,n,0);
	printf("\n");
}
