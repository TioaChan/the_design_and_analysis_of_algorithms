#pragma warning(disable:4786)
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std; 
#define MAX 101
//�����ʾ
int n;					//Ҷ������
string str;				//�ַ���
//�������ʾ
struct HTreeNode		//���������������
{
	char data;			//�ַ�
	int weight;			//Ȩֵ
	int parent;			//˫�׵�λ��
	int lchild;			//���ӵ�λ��
	int rchild;			//�Һ��ӵ�λ��
};
HTreeNode ht[MAX];				//��������
map<char,string> htcode;			//����������

struct NodeType				//���ȶ��н������
{
	int no;					//��Ӧ��������A�е�λ��
	char data;				//�ַ�
	int  weight;			//Ȩֵ
	bool operator<(const NodeType &s) const
	{						//���ڴ���С����
		return s.weight<weight;
	}
};
void Init()							//��ʼ����������
{
	int i;
	map<char,int> mp;
	for (i=0;i<str.length();i++)	//�ۼ�str�и����ַ��ĳ��ִ���
		mp[str[i]]++;
	n=mp.size();
	map<char,int>::iterator it;
	i=0;
	for (it=mp.begin();it!=mp.end();++it)	//����Ҷ����data��weight
	{
		ht[i].data=it->first;
		ht[i].weight=it->second;
		i++;
	}
	for (int j=0;j<2*n-1;j++)	//�������н���ָ����
		ht[j].lchild=ht[j].rchild=ht[j].parent=-1;

}
void CreateHTree()				//�����������
{
	NodeType e,e1,e2;
	priority_queue<NodeType> qu;
	for (int i=0;i<n;i++)		//��n��������qu
	{
		e.no=i;
		e.data=ht[i].data;
		e.weight=ht[i].weight;
		qu.push(e);
	}
	for (int j=n;j<2*n-1;j++)			//�������������n-1����Ҷ���
	{
		e1=qu.top();  qu.pop();		//����Ȩֵ��С�Ľ��e1
		e2=qu.top();  qu.pop();		//����Ȩֵ��С�Ľ��e2
		ht[j].weight=e1.weight+e2.weight; //������������ķ�Ҷ���j	
		ht[j].lchild=e1.no;
		ht[j].rchild=e2.no;
		ht[e1.no].parent=j;			//�޸�e1.no��˫��Ϊ���j
		ht[e2.no].parent=j;			//�޸�e2.no��˫��Ϊ���j
		e.no=j;						//������н��e
		e.weight=e1.weight+e2.weight;
		qu.push(e);
	}
}
void CreateHCode()			//�������������
{
	string code;
	code.reserve(MAX);
	for (int i=0;i<n;i++)	//����Ҷ���i�Ĺ���������
	{
		code="";
		int curno=i;
		int f=ht[curno].parent;
		while (f!=-1)
		{
			if (ht[f].lchild==curno)	//curnoΪ˫��f������
				code='0'+code;
			else					//curnoΪ˫��f���Һ���
				code='1'+code;
			curno=f; f=ht[curno].parent;
		}
		htcode[ht[i].data]=code;		
	}
}
void DispHCode()					//�������������
{
	map<char,string>::iterator it;
	for (it=htcode.begin();it!=htcode.end();++it)
		cout << "\t" << it->first << ": " << it->second <<	endl;
}
void EnCode(string str,string &enstr)			//�����ַ���str�õ�enstr
{
	for (int i=0;i<str.length();i++)
		enstr = enstr+htcode[str[i]];
}
void DeCode(string enstr,string &destr)			//�����ַ���enstr�õ�destr
{
	int r=2*n-2,p;								//���������ĸ����Ϊht[2*n-2]���
	int i=0;
	while (i<enstr.length())
	{
		p=r;
		while (true)
		{
			if (enstr[i]=='0')
				p=ht[p].lchild;
			else
				p=ht[p].rchild;
			if (ht[p].lchild==-1 && ht[p].rchild==-1)	//pΪҶ���
				break;							//�ҵ���Ӧ���ַ�
			i++;
		}
		destr=destr+ht[p].data;					//�ڽ����ַ��������ht[p].data
		i++;
	}
}
void main()
{
	str="The following code computes the intersection of two arrays.";
	Init();
	CreateHTree();
	CreateHCode();
	cout << "����������:" << endl;
	DispHCode();
	string enstr="";
	EnCode(str,enstr);
	cout << "������:" << endl;
	cout << enstr << endl;
	string destr="";
	DeCode(enstr,destr);
	cout << "������:" << endl;
	cout << destr << endl;
}
