//��5.3���㷨2
#include <stdio.h>
#include <vector>
using namespace std;
void dispasolution(vector<int> path)		//���һ����
{
	printf("   {");
	for (int i=0;i<path.size();i++)
			printf("%d",path[i]);
	printf("}");
}
void dfs(int a[],int n,int i,vector<int> path)	//�����㷨���Ӽ�path
{
	if (i>=n)
		dispasolution(path);
	else
	{
		dfs(a,n,i+1,path);			//��ѡ��a[i]
		path.push_back(a[i]);
		dfs(a,n,i+1,path);			//ѡ��a[i]
	}
}
void main()
{
	int a[]={1,2,3};				//s[0..n-1]Ϊ�������ַ���,����Ϊȫ�ֱ���
	int n=sizeof(a)/sizeof(a[0]);
	vector<int> path;
	printf("�����\n");
	dfs(a,n,0,path);
	printf("\n");
}
