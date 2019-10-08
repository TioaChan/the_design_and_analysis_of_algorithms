#include <stdio.h>
#include <string.h>
#define MAXN 20				//ͼ���Ķ������
//�����ʾ
int n,k,m;
int a[MAXN][MAXN];
//�������ʾ
int count=0;				//ȫ�ֱ������ۼƽ����
int x[MAXN];				//ȫ�ֱ�����x[i]��ʾ����i����ɫ
bool Same(int i)			//�ж϶���i�Ƿ������ڶ��������ͬ����ɫ
{
	for (int j=1;j<=n;j++)
		if (a[i][j]==1 && x[i]==x[j])
			return false;
	return true;
}
void dispasolution()			//���һ����ɫ����
{
	printf("��%d����ɫ����: ",count);
	for (int j=1;j<=n;j++)
		printf("%d ",x[j]);
	printf("\n");
}
void dfs(int i)					//���ͼ��m��ɫ����
{
	if (i>n)					//�ﵽҶ�ӽ��
	{
		count++;				//��ɫ��������1
		dispasolution();
	}
	else
	{
		for (int j=1;j<=m;j++)	//��̽ÿһ����ɫ
		{
			x[i]=j;
			if (Same(i))		//������ɫj��������һ��������ɫ
				dfs(i+1);
			x[i]=0;				//����
		}
	}
}
int main()
{
	memset(a,0,sizeof(a));		//a��ʼ��
	memset(x,0,sizeof(x));		//x��ʼ��
	int x,y;
	scanf("%d%d%d",&n,&k,&m);	//����n,k,m
	for (int j=1;j<=k;j++)
	{
		scanf("%d%d",&x,&y);	//����һ���ߵ���������
		a[x][y]=1;				//����ͼ�ı߶Գ�
		a[y][x]=1;
	}
	dfs(1);						//�Ӷ���1��ʼ����
	if (count>0)				//������
		printf("%d\n",count);
	else
		printf("-1\n");
	return 0;
}


