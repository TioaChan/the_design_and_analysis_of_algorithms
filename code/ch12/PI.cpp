#include <stdio.h>
#include <stdlib.h>				//��������������Ŀ⺯��
#include <time.h>
int randa(int a,int b)			//����һ��[a,b]�������
{
	return rand()%(b-a+1)+a;
}
double rand01()					//����һ��[0,1]�������
{
	return randa(0,100)*1.0/100;
}
double solve()						//��е����ؿ����㷨
{
	int n=10000;
	int m=0;
	double x,y;
	for (int i=1;i<=n;i++)
	{
		x=rand01();
		y=rand01();
		if (x*x+y*y<=1.0)
			m++;
	}
	return 4.0*m/n;
}
void main()
{
	srand((unsigned)time(NULL));	//�������
	printf("PI=%g\n",solve());		//�����
}

