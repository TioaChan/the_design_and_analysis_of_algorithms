#include <stdio.h>
int Findk(int a[],int n,int b[],int m, int k) //����������������������ҵ���k���Ԫ��
{	if (k<0) return -1;
	if (n>m)					//���ڱ�֤n<=m,����֤ǰһ������Ԫ�ؽ���
		return Findk(b,m,a,n,k);
	if (n==0)
		return b[k-1];
	if (k==1)
		return ((a[0]>=b[0]) ? b[0]:a[0]);
	int numa=(n>=k/2)?k/2:n;  		//������û��k/2��Ԫ��ʱȡn
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
	printf("�����:\n");
	for(i=1;i<=n+m;i++)
	{
		result=Findk(a,n,b,m,i);
		printf("  ��%d���Ԫ����:%d\n",i,result);
	}
}