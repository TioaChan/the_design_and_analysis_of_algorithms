#include <stdio.h>
#include <string>
using namespace std;
int Count(string s,string t)	//�ַ���ƥ��
{
	int num=0;				//�ۼƳ��ִ���
	int i=0,j=0;
	while (i<s.length() && j<t.length())
	{
		if (s[i]==t[j])		//�Ƚϵ������ַ���ͬʱ
		{
			i++; j++;
		}
		else				//�Ƚϵ������ַ�����ͬʱ
		{
			i=i-j+1;		//i����
			j=0;			//j��0��ʼ
		}
		if(j==t.length())
		{
			num++;			//���ִ�����1
			j=0;			//j��0��ʼ����
		}
	}
	return num;
}
void main()
{
	string s="abababa";
	string t="aba";
	printf("t��s�г��ִ���: %d\n",Count(s,t));
}

