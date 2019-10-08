#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAX 1001
//�����ʾ
int n;
int a[MAX];
int b[MAX];
//�������ʾ
int ans;
void solve()					//����㷨
{
	sort(a,a+n);				//��a��������
	sort(b,b+n);				//��b��������
	ans=0;
	int lefta=0,leftb=0;
	int righta=n-1,rightb=n-1;
	while (lefta<=righta)		//����ֱ������
	{
		if (a[righta]>b[rightb])	//����������������������죬���߱���
		{
			ans+=200;
			righta--;
			rightb--;
		}
		else if (a[righta]<b[rightb])	//��������������������������ѡ�������������������������������
		{
			ans-=200;
			lefta++;
			rightb--;
		}
		else						//�������������������������ٶ���ͬ
		{
			if (a[lefta]>b[leftb])	//��������������������������죬���߱���
			{
				ans+=200;
				lefta++;
				leftb++;
			}
			else
			{
				if (a[lefta]<b[rightb])	//����������������������������������
					ans-=200;
				lefta++;
				rightb--;
			}
		}
	}
}
int main()
{
	while (true)
	{
		scanf("%d",&n);
		if (n==0) break;
		for (int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for (int j=0;j<n;j++)
			scanf("%d",&b[j]);
		solve();
		printf("%d\n",ans);
	}
	return 0;
}
