#include <stdio.h>
#define MAX 101
//�����ʾ
int k;
//�������ʾ
int a[MAX][MAX];						//��ű����ճ̱������±�Ϊ0��Ԫ�ز��ã�
void Plan(int k)
{
	int i,j,n,t,temp;
	n=2;								//n��2^1=2��ʼ
	a[1][1]=1; a[1][2]=2;   			//���2��ѡ�ֱ����ճ�,�õ����Ͻ�Ԫ��
	a[2][1]=2; a[2][2]=1;
	for (t=1;t<k;t++)						//��������,���δ���2^2(t=1)��,2^k(t=k-1)��ѡ��
	{
		temp=n;								//temp=2^t
		n=n*2; 								//n=2^(t+1)
		for (i=temp+1;i<=n;i++ )			//�����½�Ԫ��
			for (j=1; j<=temp; j++)
				a[i][j]=a[i-temp][j]+temp; 	//���½�Ԫ�غ����Ͻ�Ԫ�صĶ�Ӧ��ϵ
		for (i=1; i<=temp; i++)				//�����Ͻ�Ԫ��
			for (j=temp+1; j<=n; j++)
				a[i][j]=a[i+temp][(j+temp)% n];
		for (i=temp+1; i<=n; i++)			//�����½�Ԫ��
			for (j=temp+1; j<=n; j++)
				a[i][j]=a[i-temp][j-temp];
    }
}
void main()
{
	k=3;
	int n=1<<k;							//n����2��k�η���n=2^k
	Plan(k);							//����n��ѡ�ֵı����ճ̱�
	for(int i=1; i<=n; i++)				//��������ճ̱�
	{	for(int j=1; j<=n; j++)
			printf("%4d",a[i][j]);
		printf("\n");
	}
}
