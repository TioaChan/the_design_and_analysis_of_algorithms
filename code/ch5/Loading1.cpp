#include <stdio.h>
#include <string.h>
#define MAXN 20						//��༯װ�����
//�����ʾ
int w[]={0,10,40,40};				//����װ������,�����±�0��Ԫ��
int	n=3;
int c1=50,c2=50;
int maxw=0;							//��ŵ�һ���ִ����Ž��������
int x[MAXN];						//��ŵ�һ���ִ����Ž�����
void dfs(int tw,int rw,int op[],int i) //���һ���ִ������Ž�
{
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{
		if (tw<=c1 && tw>maxw)
		{
			maxw=tw;				//�ҵ�һ�����������ĸ��Ž�,������
			for (int j=1;j<=n;j++)	//�������Ž�
				x[j]=op[j];
		}
	}
	else						//��δ�������м�װ��
	{	op[i]=1;				//ѡȡ��i����װ��
		if (tw+w[i]<=c1)		//���ӽ���֦��װ�����������ļ�װ��
			dfs(tw+w[i],rw-w[i],op,i+1);
		op[i]=0;				//��ѡȡ��i����װ��,����
		if (tw+rw>c1)			//�Һ��ӽ���֦
			dfs(tw,rw-w[i],op,i+1);
	}
}
void dispasolution(int n)		//���һ����
{
	for (int j=1;j<=n;j++)
		if (x[j]==1)
			printf("\t����%d����װ��װ�ϵ�һ���ִ�\n",j);
		else
			printf("\t����%d����װ��װ�ϵڶ����ִ�\n",j);

}
bool solve()			//��⸴��װ������
{
	int sum=0;			//�ۼƵ�һ���ִ�װ���ʣ��ļ�װ������
	for (int j=1;j<=n;j++)
		if (x[j]==0)
			sum+=w[j];
	if (sum<=c2)			//�ڶ����ִ�����װ��
		return true;
	else				//�ڶ����ִ�����װ��
		return false;
}

void main()
{
	int op[MAXN];				//�����ʱ��
	memset(op,0,sizeof(op));
	int rw=0;
	for (int i=1;i<=n;i++)
		rw+=w[i];
	dfs(0,rw,op,1);				//���һ���ִ������Ž�
	printf("�����\n");
	if (solve())				//������
	{
		printf("    ���ŷ���\n");
		dispasolution(n);
	}
	else
		printf("    û�к��ʵ�װ�ط���\n");
}
