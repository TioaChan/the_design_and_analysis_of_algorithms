#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))
//�����ʾ
//int n=6;									//��ҵ��
//int a[]={2,5,7,10,5,2};
//int b[]={3,8,4,11,3,4};

int n=3;											//������
int a[]={1,2,3};
int b[]={4,3,1};

//int a[]={1,3,2};
//int b[]={4,1,3};

//int a[]={2,1,3};
//int b[]={3,4,1};

//int a[]={2,3,1};
//int b[]={3,1,4};

//int a[]={3,1,2};
//int b[]={1,4,3};

//int a[]={3,2,1};
//int b[]={1,3,4};

//���ṹ��ʾ
int ans;
void solve()							//����㷨
{
	int k,sumA=0,sumB=0;
	for (k=1; k<=n; k++) 
	{
		sumA+=a[k-1];					//���ڻ���A�д���
		sumB+=b[k-1];					//���ڻ���B�д���
		if (sumA>sumB)
			sumA-=a[k-1];				//��Ϊ�ڻ���B�д���
		else
			sumB-=b[k-1];				//��Ϊ�ڻ���A�д���
	}
	ans=max(sumA,sumB);
} 
int main()
{
	solve();
	printf("%d\n",ans);
	return 0;
}
