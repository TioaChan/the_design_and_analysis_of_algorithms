#include <stdio.h>
#include <string.h>
#define MAX 51
//�����ʾ
struct Action
{
	int b;					//���ʼʱ��
	int e;					//�����ʱ��
};
int n=4;
Action A[]={{0,0},{1,3},{2,5},{4,8},{6,10}};	//�±�0����
//�������ʾ
int x[MAX];					//������
int bestx[MAX];				//���Ž�����
int laste=0;				//һ�������������ݻ�Ľ���ʱ��
int sum=0;					//һ�����������м��ݻ����
int maxsum=0;				//���ŷ��������м��ݻ����
void swap(int &x,int &y)	//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
void dispasolution()					//���һ����
{
	printf("���ŵ��ȷ���\n");
	int laste=0;
	for (int j=1;j<=n;j++)
	{
		if (A[bestx[j]].b>=laste)		//ѡȡ�bestx[j]
		{
			printf("    ѡȡ�%d: [%d,%d)\n",bestx[j],A[bestx[j]].b,A[bestx[j]].e);
			laste=A[bestx[j]].e;
		}
	}
	printf("  ���Ż�ĸ���=%d\n",maxsum);
}
void dfs(int i)							//������������Ž�
{
	if (i>n)							//����Ҷ���,����һ�ֵ��ȷ���
    {
		if (sum>maxsum)
		{
			maxsum=sum;
			for (int k=1;k<=n;k++)
				bestx[k]=x[k];
		}
	}
	else
	{
		for(int j=i; j<=n; j++)				//û�е���Ҷ���,����i��n�Ļ
		{	//��i����ѡ��x[j]
			int sum1=sum;					//����sum��laste�Ա����
			int laste1=laste;
			if (A[x[j]].b>=laste)			//�x[j]��ǰ�����
			{
				sum++;						//���ݻ������1
				laste=A[x[j]].e;			//�޸ı�������������ʱ��
			}
			swap(x[i],x[j]);				//����������ݹ���:����x[i],x[j]
			dfs(i+1);						//����������ݹ���:������һ��
			swap(x[i],x[j]);				//����������ݹ���:����x[i],x[j]
			sum=sum1;						//����
			laste=laste1;					//��������i����Իx[j]��ѡ��,�Ա���ѡ�������
		}
	}
}
void main()
{
	for (int i=1;i<=n;i++)
		x[i]=i;
	dfs(1);								//i��1��ʼ����
	dispasolution();					//������
}



