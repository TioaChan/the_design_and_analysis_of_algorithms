//����ͷ���ĵ�����Ļ��������㷨
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;
typedef struct Node
{	ElemType data;
	struct Node *next;
} LinkNode;					//������������

void CreateList(LinkNode *&L,ElemType a[],int n)	//��a[0..n-1]����������L
{
	LinkNode *p, *r;
	L=(LinkNode *)malloc(sizeof(LinkNode));
	L->data=a[0];
	r=L;					//rָ��ǰβ���
	for (int i=1;i<n;i++)
	{
		p=(LinkNode *)malloc(sizeof(LinkNode));
		p->data=a[i];
		r->next=p;
		r=p;
	}
	r->next=NULL;			//β���next����Ϊ��
}
void DispList(LinkNode *L)	//���������L
{
	LinkNode *p=L;
	while (p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void Release(LinkNode *&L)	//���ٵ�����L:��Ӧ��2.6���㷨
{
	if (L!=NULL)
	{
		Release(L->next);
		free(L);
	}
}
