//�ж��Ӽ��������Ƿ���ڽ�:�ڶ��ַ���
#include <stdio.h>
#define MAXN 20						//�����������
//�����ʾ
int n=4,W;
int w[]={0,11,13,24,7};				//�����������,�����±�0��Ԫ��
int count;							//ȫ�ֱ������ۼƽ����
void dfs(int tw,int rw,int i)		//����Ӽ���
{
	if (i>n)						//�ҵ�һ��Ҷ�ӽ��
	{	if (tw==W)					//�ҵ�һ�����������Ľ�,�������1
			count++;
	}
	else							//��δ����������Ʒ
	{
		if (tw+w[i]<=W)				//���ӽ���֦��ѡȡ��������������w[i]
			dfs(tw+w[i],rw-w[i],i+1);	//ѡȡ��i������
		if (tw+rw>W)				//�Һ��ӽ���֦�����������ܴ��ڽ�Ľ��
			dfs(tw,rw-w[i],i+1);			//��ѡȡ��i������,����
	}
}
bool solve()						//�ж��Ӽ��������Ƿ���ڽ�
{
	count=0;
	int rw=0;
	for (int j=1;j<=n;j++)			//������������rw
		rw+=w[j];
	dfs(0,rw,1);					//i��1��ʼ
	if (count>0)
		return true;
	else
		return false;
}
void main()
{
	W=7;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
	W=15;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
	W=21;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
	W=24;
	printf("W=%dʱ%s\n",W,(solve()?"���ڽ�":"û�н�"));
}
