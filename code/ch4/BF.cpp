#include <stdio.h>
#include <string>
using namespace std;
int BF(string s,string t)	//�ַ���ƥ��
{
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
	}
	if (j==t.length())		//t���ַ��Ƚ����
		return i-j;			//t��s���Ӵ�,����λ��
	else					//t����s���Ӵ�
		return -1;			//����-1
}

void main()
{
	string s="aababcabcde";
	string t="abcd";
	printf("index=%d\n",BF(s,t));
}

