//�ҵ�kСԪ�ص��㷨
#include <stdio.h>
int QuickSelect(int a[],int s,int t,int k)	//��a[s..t]�������ҵ�kС��Ԫ��
{	int i=s,j=t;
	int tmp;
	if (s<t) 					//���������ٴ���2��Ԫ�ص����
	{	tmp=a[s];				//������ĵ�1����¼��Ϊ��׼
		while (i!=j)			//���������˽������м�ɨ��,ֱ��i=jΪֹ
		{	while (j>i && a[j]>=tmp) 
				j--;			//��������ɨ��,�ҵ�1���ؼ���С��tmp��a[j]
			a[i]=a[j];			//��a[j]ǰ�Ƶ�a[i]��λ��
			while (i<j && a[i]<=tmp) 
				i++;			//��������ɨ��,�ҵ�1���ؼ��ִ���tmp��a[i]
			a[j]=a[i];			//��a[i]���Ƶ�a[j]��λ��
		}
		a[i]=tmp;
		if (k-1==i) return a[i];
		else if (k-1<i) return QuickSelect(a,s,i-1,k);	//���������еݹ����
		else return QuickSelect(a,i+1,t,k);				//���������еݹ����
	}
	else if (s==t && s==k-1)	//������ֻ��һ��Ԫ����Ϊa[k-1]
		return a[k-1];
}
void main()
{	int n=10,k;
	int e;
	int a[]={2,5,1,7,10,6,9,4,3,8};
	for (k=1;k<=n;k++)
	{	e=QuickSelect(a,0,n-1,k);
		printf("��%dС��Ԫ��:%d\n",k,e);
	}
}
