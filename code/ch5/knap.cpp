//���0/1����������㷨
#include <stdio.h>
#define MAXN 20					//�����Ʒ��
//�����ʾ
int n=4;						//4����Ʒ
int W=6;						//��������Ϊ6
int w[]={0,5,3,2,1};			//���4����Ʒ����,�����±�0Ԫ��
int v[]={0,4,4,3,1};			//���4����Ʒ��ֵ,�����±�0Ԫ��
//�������ʾ
int x[MAXN];					//������ս�
int maxv; 						//������Ž���ܼ�ֵ
void dfs(int i,int tw,int tv,int op[]) //���ǵ�i����Ʒ
{	if (i>n)					//�ҵ�һ��Ҷ�ӽ��
	{	if (tw<=W && tv>maxv)	//�ҵ�һ�����������ĸ��Ž�,������
		{	maxv=tv;
			for (int j=1;j<=n;j++)
				x[j]=op[j];
		}
	}
	else						//��δ����������Ʒ
	{	op[i]=1;				//ѡȡ��i����Ʒ
		dfs(i+1,tw+w[i],tv+v[i],op);
		op[i]=0;				//��ѡȡ��i����Ʒ,����
		dfs(i+1,tw,tv,op);
	}
}
void dispasolution()			//������Ž�
{	int i;
	printf("���װ�����:\n");
	for (i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",i);
	printf("������=%d,�ܼ�ֵ=%d\n",W,maxv);
}
void main()
{
	int op[MAXN];				//�����ʱ��
	dfs(1,0,0,op);				//i��1��ʼ
	dispasolution();
}
