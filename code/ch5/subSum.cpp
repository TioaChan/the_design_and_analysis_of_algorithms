//����Ӽ���������㷨
#include <stdio.h>
#define MAXN 20						//�����������
//�����ʾ
int n=4,W=31;
int w[]={0,11,13,24,7};				//�����������,�����±�0��Ԫ��
int count=0;						//�ۼƽ����
void dispasolution(int x[])			//���һ����
{	int i;
	printf("��%d����:\n",++count);
	printf("  ѡȡ����Ϊ");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("%d ",w[i]);
	printf("\n");
}
void dfs(int tw,int rw,int x[],int i) //����Ӽ���
{	//twΪ���ǵ�i������ʱѡȡ�������ͣ�rwΪʣ�µ�������
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{	if (tw==W)					//�ҵ�һ�����������Ľ�,�����
			dispasolution(x);
	}
	else							//��δ����������Ʒ
	{
		if (tw+w[i]<=W)				//���ӽ���֦��ѡȡ��������������w[i]
		{	x[i]=1;					//ѡȡ��i������
			dfs(tw+w[i],rw-w[i],x,i+1);
		}
		if (tw+rw>W)				//�Һ��ӽ���֦�����������ܴ��ڽ�Ľ��
		{	x[i]=0;					//��ѡȡ��i������,����
			dfs(tw,rw-w[i],x,i+1);
		}
	}
}
void main()
{
	int x[MAXN];					//���һ��������
	int rw=0;
	for (int j=1;j<=n;j++)			//������������rw
		rw+=w[j];
	dfs(0,rw,x,1);				//i��1��ʼ
}
