//��5.3���㷨1
#include <stdio.h>
#include <string.h>
#define MAXN 100
void dispasolution(int a[],int n,int x[])	//���һ����
{
	printf("   {");
	for (int i=0;i<n;i++)
		if (x[i]==1)
			printf("%d",a[i]);
	printf("}");
}
void dfs(int a[],int n,int i,int x[])	//�����㷨
{
	if (i>=n)
		dispasolution(a,n,x);
	else
	{
		x[i]=0;
		dfs(a,n,i+1,x);			//��ѡ��a[i]
		x[i]=1;
		dfs(a,n,i+1,x);			//ѡ��a[i]
	}
}
void main()
{
	int a[]={1,2,3};				//s[0..n-1]Ϊ�������ַ���,����Ϊȫ�ֱ���
	int n=sizeof(a)/sizeof(a[0]);
	int x[MAXN];					//������
	memset(x,0,sizeof(x));			//��������ʼ��
	printf("�����\n");
	dfs(a,n,0,x);
	printf("\n");
}
