//Ѱ�������ȳ��������е���λ�����㷨
#include <stdio.h>
void prepart(int &s,int &t)			//��a[s..t]���е�ǰ��������
{	int m=(s+t)/2;
	t=m;
}
void postpart(int &s,int &t)		//��a[s..t]���еĺ��������
{	int m=(s+t)/2;
	if ((s+t)%2==0)					//��������������Ԫ��
		s=m;
	else							//��������ż����Ԫ��
		s=m+1;
}
void display(int a[],int s,int t)
{
	for (int i=s;i<=t;i++)
		printf("%d ",a[i]);
	printf("\t");
}
int midnum(int a[],int s1,int t1,int b[],int s2,int t2)
{	//��������������a[s1..t1]��b[s2..t2]����λ��
	int m1,m2;
	if (s1==t1 && s2==t2)	//������ֻ��һ��Ԫ��ʱ���ؽ�С��
		return a[s1]<b[s2]?a[s1]:b[s2];
	else
	{	m1=(s1+t1)/2;				//��a����λ��
		m2=(s2+t2)/2;				//��b����λ��
		if (a[m1]==b[m2])			//����λ�����ʱ���ظ���λ��
			return a[m1];
		if (a[m1]<b[m2])			//��a[m1]<b[m2]ʱ
		{	postpart(s1,t1);		//aȡ��벿��
			prepart(s2,t2);			//bȡǰ�벿��
			printf("a:"); display(a,s1,t1);
			printf("b:"); display(b,s2,t2);
			printf("\n");
			return midnum(a,s1,t1,b,s2,t2);
		}
		else						//��a[m1]>b[m2]ʱ
		{	prepart(s1,t1);			//aȡǰ�벿��
			postpart(s2,t2);		//bȡ��벿��
			printf("a:"); display(a,s1,t1);
			printf("b:"); display(b,s2,t2);
			printf("\n");
			return midnum(a,s1,t1,b,s2,t2);
		}
	}
}
void main()
{
	int a[]={1,3,5,7};
	int b[]={2,4,6,8};
	//int a[]={1,3,4,6,9};
	//int b[]={2,3,5,8,10};
	int n=sizeof(a)/sizeof(a[0]);
	printf("��λ��:%d\n",midnum(a,0,n-1,b,0,n-1));
}
