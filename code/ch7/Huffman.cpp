#pragma warning(disable:4786)
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
using namespace std; 
#define MAX 101
int n;
struct HTreeNode				//���������������
{
	char data;					//�ַ�
	int weight;					//Ȩֵ
	int parent;					//˫�׵�λ��
	int lchild;					//���ӵ�λ��
	int rchild;					//�Һ��ӵ�λ��
};
HTreeNode ht[MAX];				//��������
map<char,string> htcode;			//����������

struct NodeType		//���ȶ��н������
{
	int no;				//��Ӧ��������ht�е�λ��
	char data;			//�ַ�
	int  weight;		//Ȩֵ
	bool operator<(const NodeType &s) const
	{					//���ڴ���С����
		return s.weight<weight;
	}
};
void CreateHTree()						//�����������
{
	NodeType e,e1,e2;
	priority_queue<NodeType> qu;
	for (int k=0;k<2*n-1;k++)	//�������н���ָ����
		ht[k].lchild=ht[k].rchild=ht[k].parent=-1;
	for (int i=0;i<n;i++)				//��n��������qu
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
		while (f!=-1)				//ѭ���������
		{
			if (ht[f].lchild==curno)	//curnoΪ˫��f������
				code='0'+code;
			else					//curnoΪ˫��f���Һ���
				code='1'+code;
			curno=f; f=ht[curno].parent;
		}
		htcode[ht[i].data]=code;	//�õ�ht[i].data�ַ��Ĺ���������
	}
}
void DispHCode()					//�������������
{
	map<char,string>::iterator it;
	for (it=htcode.begin();it!=htcode.end();++it)
		cout << "    " << it->first << ": " << it->second <<	endl;
}
void DispHTree()					//�����������
{
	for (int i=0;i<2*n-1;i++)
	{
		printf("    data=%c, weight=%d, lchild=%d, rchild=%d, parent=%d\n",
			ht[i].data,ht[i].weight,ht[i].lchild,ht[i].rchild,ht[i].parent);
	}
}
int WPL()				//��WPL
{
	int wps=0;
	for (int i=0;i<n;i++)
		wps+=ht[i].weight*htcode[ht[i].data].size();
	return wps;
}

void main()
{
	n=5;
	ht[0].data='a'; ht[0].weight=4;		//�ó�ֵ��n��Ҷ�ӽ��
	ht[1].data='b'; ht[1].weight=2;  
	ht[2].data='c'; ht[2].weight=1;  
	ht[3].data='d'; ht[3].weight=7;  
	ht[4].data='e'; ht[4].weight=3;  
	CreateHTree();					//������������
	printf("����Ĺ�������:\n");
	DispHTree();
	CreateHCode();					//�����������
	printf("�����Ĺ�������������:\n");
	DispHCode();					//�������������
	printf("WPL=%d\n",WPL());
}
