//��5.2���㷨
#include <stdio.h>
#include <string.h>
void fun()
{	bool dig[10];
	int a,b,c,d,e,m,n,s;
	memset(dig,0,sizeof(dig));;	//�ó�ֵ0��ʾ�������־�û��ʹ��
	for (a=1;a<=9;a++)
	{	dig[a]=1;					//��̽��ȡֵa
		for (b=0;b<=9;b++)
			if (!dig[b])
			{	dig[b]=1;				//��̽��ȡֵb
				for (c=0;c<=9;c++)
					if (!dig[c])
					{	dig[c]=1;			//��̽��ȡֵc
						for (d=0;d<=9;d++)
							if (!dig[d])
							{	dig[d]=1;		//��̽��ȡֵd
								for (e=0;e<=9;e++)
									if (!dig[e]) 
									{	dig[e]=1;		//��̽��ȡֵe
										m=a*1000+b*100+c*10+d;
										n=a*1000+b*100+e*10+d;
										s=e*10000+d*1000+c*100+a*10+d;
										if (m+n==s)
											printf("��:%d ��:%d ��:%d ��:%d ��:%d\n",a,b,c,d,e);
										dig[e]=0;		//���ݳ���ȡֵ
									}
									dig[d]=0;	//�������ȡֵ
							}
							dig[c]=0;		//�������ȡֵ
					}
					dig[b]=0;		//�����ڵ�ȡֵ
			}
			dig[a]=0;	//���ݱ���ȡֵ
	}
}
void main()
{
	fun();
}
