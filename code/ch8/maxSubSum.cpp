//���������������к�������㷨
#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
#define MAXN 20
//�����ʾ
int n=6;
int a[]={0,-2,11,-4,13,-5,-2};	//a���鲻���±�Ϊ0��Ԫ��
//�������ʾ
int dp[MAXN];
void maxSubSum()				//��dp����
{
	dp[0]=0;
	for (int j=1;j<=n;j++)
		dp[j]=max(dp[j-1]+a[j],a[j]);
}
void dispmaxSum()					//������
{
	int maxj=1;
	for (int j=2;j<=n;j++)			//��dp�����Ԫ��dp[maxj]
		if (dp[j]>dp[maxj]) maxj=j;

		
	for (int k=maxj;k>=1;k--)		//��ǰһ��ֵС�ڵ���0��
		if (dp[k]<=0) break;
	printf("    ������������к�: %d\n",dp[maxj]);
	printf("    ��ѡ������: ");
	for (int i=k+1;i<=maxj;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void main()
{
	maxSubSum();
	printf("�����\n");
	dispmaxSum();
}
