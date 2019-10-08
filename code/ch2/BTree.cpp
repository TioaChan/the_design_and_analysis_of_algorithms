//�������Ļ��������㷨+��2.8����2.11
#include <malloc.h>
#include <stack>
#include <vector>
#include <string>
using namespace std;
typedef int ElemType;
typedef struct node 
{	ElemType data;				//����Ԫ��
	struct node *lchild;		//ָ�����ӽ��
	struct node *rchild;		//ָ���Һ��ӽ��
} BTNode;						//�������������

BTNode *CreateBTree(ElemType a[],ElemType b[],int n)	//��Ӧ��2.8���㷨
//����������a[0..n-1]����������b[0..n-1]����������
{
	int k;
	if (n<=0) return NULL;
	ElemType root=a[0];			//�����ֵ
	BTNode *bt=(BTNode *)malloc(sizeof(BTNode));
	bt->data=root;
	for (k=0;k<n;k++)			//��b�в���b[k]=root�ĸ����
		if (b[k]==root)
			break;
	bt->lchild=CreateBTree(a+1,b,k);			//�ݹ鴴��������
	bt->rchild=CreateBTree(a+k+1,b+k+1,n-k-1);	//�ݹ鴴��������
	return bt;
}
void DispBTree(BTNode *bt)				//�������ű�ʾ���������bt
{
	if (bt!=NULL)
	{	printf("%d",bt->data);
		if (bt->lchild!=NULL || bt->rchild!=NULL)
		{	printf("(");						//�к��ӽ��ʱ�����(
			DispBTree(bt->lchild);				//�ݹ鴦��������
			if (bt->rchild!=NULL) printf(",");	//���Һ��ӽ��ʱ�����,
			DispBTree(bt->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}
void DestroyBTree(BTNode *&bt)		//��Ӧ��2.9���㷨
//�ͷ���btΪ�����Ķ�����
{	if (bt!=NULL)
	{	DestroyBTree(bt->lchild);
		DestroyBTree(bt->rchild);
		free(bt);
	}
}
void CopyBTree(BTNode *bt,BTNode *&bt1)	//��Ӧ��2.10���㷨
//�ɶ�����bt���Ʋ���bt1
{
	if (bt==NULL)
		bt1=NULL;
	else
	{
		bt1=(BTNode *)malloc(sizeof(BTNode));
		bt1->data=bt->data;
		CopyBTree(bt->lchild,bt1->lchild);
		CopyBTree(bt->rchild,bt1->rchild);
	}
}
bool Findxpath1(BTNode *bt,int x,vector<int> &path)			//��Ӧ��2.11�Ľⷨ1
//�����㵽x���ģ�����·��
{
	if (bt==NULL)					//��������false
		return false;
	if (bt->data==x)				//�ҵ�ֵΪx�Ľ��
	{
		path.push_back(x);			//���ֵ����path�У�������true
		return true;
	}
	else if (Findxpath1(bt->lchild,x,path) || Findxpath1(bt->rchild,x,path))
	{
		path.push_back(bt->data);	//���ֵ����path�У�������true
		return true;
	}
}
bool Findxpath2(BTNode *bt,int x,vector<int> tmppath,vector<int> &path)	//��Ӧ��2.11�Ľⷨ2
//�����㵽x���ģ�����·��
{
	if (bt==NULL)							//��������false
		return false;
	tmppath.push_back(bt->data);			//��ǰ������path
	if (bt->data==x)						//��ǰ���ֵΪx������true
	{
		path=tmppath;
		return true;
	}
	bool find=Findxpath2(bt->lchild,x,tmppath,path);//���������в���
	if (find)								//�������гɹ��ҵ�
		return true;
	else									//��������û���ҵ������������в���
		return Findxpath2(bt->rchild,x,tmppath,path);
}
