//��������������������㷨
#include <iostream>
#include <string.h>
#include <vector>
#include <string>
using namespace std;
#define max(x,y) ((x)>(y)?(x):(y))
#define MAX 51							//�����������ַ�����
//�����ʾ
int m,n;
string a,b;
//�������ʾ
int dp[MAX][MAX];						//��̬�滮����
vector<char> subs;						//���LCS
void LCSlength()						//��dp
{
	int i,j;
	for (i=0;i<=m;i++)					//��dp[i][0]��Ϊ0,�߽�����
		dp[i][0]=0;
	for (j=0;j<=n;j++)					//��dp[0][j]��Ϊ0,�߽�����
		dp[0][j]=0;
	for (i=1;i<=m;i++)
		for (j=1;j<=n;j++)				//����forѭ������a��b�������ַ�
		{	if (a[i-1]==b[j-1])			//���(1)
				dp[i][j]=dp[i-1][j-1]+1;
			else						//���(2)
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);

		}
}
void Buildsubs()					//��dp�����subs
{
	printf("��LCS\n");
	int k=dp[m][n];					//kΪa��b������������г���
	int i=m;
	int j=n;
	while (k>0)						//��subs�з��������������(����)
		if (dp[i][j]==dp[i-1][j])
			i--;
		else if (dp[i][j]==dp[i][j-1])
			j--;
		else
		{
			printf("i=%d,j=%d,���Ԫ��a[i-1]=%c\n",i,j,a[i-1]);
			subs.push_back(a[i-1]);	//subs�����a[i-1]
			i--; j--; k--;
		}
}
void main()
{
	a="abcbdb";
	b="acbbabdbb";
	m=a.length();			//mΪa�ĳ���
	n=b.length();			//nΪb�ĳ���
	LCSlength();			//���dp
	printf("���dp\n");
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=n;j++)
			printf("%3d",dp[i][j]);
		printf("\n");
	}
	Buildsubs();			//���LCS
	cout << "�����" << endl;
	cout << "    a: " << a << endl;
	cout << "    b: " << b << endl;
	cout << "    �����������: ";
	vector<char>::reverse_iterator rit;
	for (rit=subs.rbegin();rit!=subs.rend();++rit)
		cout << *rit;
	cout << endl;
	cout << "    ����: " << dp[m][n] << endl;
}
