#include <stdio.h>
#include <string.h>
#define INF 0x3f3f3f3f					//���������
#define MAX 1001						//������ҵ��
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
int n=4;								//��ҵ��
int a[MAX]={0,5,12,4,8};				//M1�ϵ�ִ��ʱ��,�����±�0��Ԫ��
int b[MAX]={0,6,2,14,7};				//M2�ϵ�ִ��ʱ��,�����±�0��Ԫ��
//�������ʾ
int bestf;							//������ŵ���ʱ��
int f1;								//M1��ִ��ʱ��
int f2[MAX];							//M2��ִ��ʱ��
int x[MAX];							//��ǰ���ȷ���
int bestx[MAX];						//��ŵ�ǰ��ҵ��ѵ���
void swap(int &x,int &y)				//����x��y
{	int tmp=x;
	x=y; y=tmp;
}
void disparr(int x[])					//���һ�������Ԫ��
{	for (int i=1;i<=n;i++)
		printf("%d ",x[i]);
}
void dfs(int i)						//�ӵ�i�㿪ʼ����
{	if (i>n)							//����Ҷ���,����һ�ֵ��ȷ���
    {	if (f2[n]<bestf)				//�ҵ����Ž�
		{	bestf=f2[n];
			printf("   һ����: bestf=%d",bestf);
			printf(", ���ȷ���: "); disparr(x);
			printf(", f2: "); disparr(f2);
			printf("\n");
			for(int j=1; j<=n; j++)		//���ƽ�����
				bestx[j] = x[j];  
		}
	}
	else
	{	for(int j=i; j<=n; j++)			//û�е���Ҷ���,����i��n����ҵ
		{	f1 += a[x[j]];				//�ڵ�i��ѡ��ִ����ҵx[j],��M1��ִ�����ʱ��
			f2[i]=max(f1,f2[i-1])+b[x[j]];
			if (f2[i]<bestf)			//��֦:������չ��ǰ��ʱ��С��bestf�Ľ��
			{	swap(x[i],x[j]);
				dfs(i+1);
				swap(x[i],x[j]);
			}
			f1 -= a[x[j]];	//���ݣ���������i�����ҵx[j]��ѡ��,�Ա���ѡ��������ҵ
		}
	}
}
int main()
{	f1=0;
	bestf=INF;
	memset(f2,0,sizeof(f2));
	for(int k=1; k<=n; k++)  	//���ó�ʼ����Ϊ��ҵ1,2,��,n��˳��
		x[k]=k;
	printf("������:\n");
	dfs(1);					//����ҵ1��ʼ����
	printf("�����:\n");
	printf("    ����ʱ��: %d",bestf);
	printf(", ���ŵ��ȷ���: ");
	disparr(bestx); printf("\n");
	return 0;
}
