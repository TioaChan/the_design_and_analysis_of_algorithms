#include <stdio.h>
#include <string.h>
#define MAXN 20						//��༯װ�����
//�����ʾ
int w[]={0,5,2,6,4,3};				//����װ������,�����±�0��Ԫ��
int	n=5,W=10;
int maxw;							//������Ž��������
int x[MAXN];						//������Ž�����
int minnum=999999;					//������Ž�ļ�װ�����,��ֵΪ���ֵ
void dfs(int num,int tw,int rw,int op[],int i) //���ǵ�i����װ��
{
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{
		if (tw==W && num<minnum)
		{	maxw=tw;				//�ҵ�һ�����������ĸ��Ž�,������
			minnum=num;
			for (int j=1;j<=n;j++)	//�������Ž�
				x[j]=op[j];
		}
	}
	else						//��δ�������м�װ��
	{	op[i]=1;				//ѡȡ��i����װ��
		if (tw+w[i]<=W)			//���ӽ���֦��װ�����������ļ�װ��
			dfs(num+1,tw+w[i],rw-w[i],op,i+1);
		op[i]=0;				//��ѡȡ��i����װ��,����
		if (tw+rw>W)			//�Һ��ӽ���֦
			dfs(num,tw,rw-w[i],op,i+1);
	}
}
void dispasolution(int n)		//���һ����
{
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ��%d����װ��\n",i);
	printf("������=%d\n",maxw);
}
void main()
{
	int op[MAXN];				//�����ʱ��
	memset(op,0,sizeof(op));
	int rw=0;
	for (int i=1;i<=n;i++)
		rw+=w[i];
	dfs(0,0,rw,op,1);
	printf("���ŷ���\n");
	dispasolution(n);
}
