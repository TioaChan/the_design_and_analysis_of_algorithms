//�ǵݹ�����㷨
#include <stdio.h>
#include <stdlib.h>
#define MAXN 20					//���ʺ����
int q[MAXN];					//��Ÿ��ʺ����ڵ��к�,Ϊȫ�ֱ���
int count=0;					//�ۼƽ����
void dispasolution(int n)   	//���һ����
{
	printf("  ��%d����:",++count);
	for (int i=1;i<=n;i++)
		printf("(%d,%d) ",i,q[i]);
	printf("\n");
}
bool place(int i)				//���Ե�i�е�q[i]�����ܷ�ڷŻʺ�
{
	int j=1;
	if (i==1) return true;
	while (j<i)					//j=1��i-1���ѷ����˻ʺ����
	{	if ((q[j]==q[i]) || (abs(q[j]-q[i])==abs(j-i))) 
			//�ûʺ��Ƿ�����ǰ�ʺ�ͬ�У�λ��(j,q[j])��(i,q[i])�Ƿ�ͬ�Խ���
			return false;
		j++;
	}
	return true;
}
void Queens(int n)						//���n�ʺ�����
{
	int i=1;							//i��ʾ��ǰ��,Ҳ��ʾ���õ�i���ʺ�
	q[i]=0;								//q[i]�ǵ�ǰ��,��0�м���ͷ��̽
	while (i>=1)						//�ظ���̽
	{
		q[i]++;
		while (q[i]<=n && !place(i))	//��̽һ��λ��(i,q[i])
			q[i]++;
		if (q[i]<=n)					//Ϊ��i���ʺ��ҵ���һ������λ��(i,q[i])
		{
			if (i==n)					//�����������лʺ�,���һ����
				dispasolution(n);
			else						//�ʺ�û�з�����
			{
				i++;					//ת����һ��,����ʼ��һ���ʺ�ķ���
				q[i]=0;					//ÿ�η�һ���»ʺ�,���Ӹ��е���ͷ������̽
			}
		}
		else i--;						//����i���ʺ��Ҳ������ʵ�λ��,����ݵ���һ���ʺ�
	}
}

void main()
{	int n;								//n���ʵ�ʻʺ����
	scanf("%d",&n);
	printf("%d�ʺ������������:\n",n);
	Queens(n);
}
