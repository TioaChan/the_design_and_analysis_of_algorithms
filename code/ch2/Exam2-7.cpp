//����ͷ���ĵ�����Ļ��������㷨
#include "LinkList.cpp"		//��������ͷ���ĵ�����Ļ��������㷨
void Delallx(LinkNode *&L,ElemType x)	//ɾ��L�����н��ֵΪx�Ľ��
{
	LinkNode *p;
	if (L==NULL) return;
	if (L->data==x)
	{
		p=L;
		L=L->next;
		free(p);			//ɾ�����ֵΪx�Ľ��
		Delallx(L,x);		//��ʱL�м�����һ�����
	}
	else Delallx(L->next,x);
}
void main()
{
	LinkNode *L;
	int a[]={1,2,2,3,4,5,2};
	int n=sizeof(a)/sizeof(a[0]);
	CreateList(L,a,n);
	printf("L: "); DispList(L);
	int x=2;
	printf("ɾ������ֵΪ%d�Ľ��\n",x);
	Delallx(L,x);
	printf("L: "); DispList(L);
	printf("����L\n");
	Release(L);
}
