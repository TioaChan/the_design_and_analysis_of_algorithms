#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 20						//��༯װ�����
//�����ʾ
int w[]={0,5,2,6,4,3};				//����װ������,�����±�0��Ԫ��
int	n=5,W=10;
//�������ʾ
int maxw;							//������Ž��������
int x[MAXN];						//������Ž�����

void solve()						//�������װ������
{
	memset(x,0,sizeof(x));			//��ʼ��������
	sort(w+1,w+n+1);				//w[1..n]��������
	maxw=0;
	int restw=W;						//ʣ������
	for (int i=1;i<=n &&  w[i]<=restw;i++)
	{
		x[i]=1;						//ѡ��װ��i
		restw-=w[i];				//����ʣ������
		maxw+=w[i];					//�ۼ�װ��������
	}
}
void main()
{
	solve();
	printf("���ŷ���\n");
	for (int i=1;i<=n;i++)
		if (x[i]==1)
			printf("  ѡȡ����Ϊ%d�ļ�װ��\n",w[i]);
	printf("������=%d\n",maxw);
}
