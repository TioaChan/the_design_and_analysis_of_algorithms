//����װ������
#include <stdio.h>
bool Loading(int W,int w[],int i)
{	int r;
	r=W-w[i];					//ȡw[i]�����µ�����
	if (r==0)					//�ҵ��󷵻�true
		return true;
	else if (r>0)				//������������0
	{	if (i>0)				//������û���ҹ��ļ�װ��ʱ
		{	if (Loading(r,w,i-1))	//��w[0..i-1]���ҵ��ⷵ��true
				return true;
			else				//��������w[i],��w[0..i-1]���ҽ�
				return Loading(W,w,i-1);
		}
		else					//���м�װ�䶼�ҹ�����δ�ҵ��ⷵ��false
			return false;
	}
	else						//��������С��0
	{	if (i>0)				//������û���ҹ��ļ�װ��ʱ,����w[i],��w[0..i-1]���ҽ�
			return Loading(W,w,i-1);
		else					//���м�װ�䶼�ҹ�����δ�ҵ��ⷵ��false
			return false;
	}
}
void main()
{	int w[]={2,9,5,6,3};
	int n=5,W;
	W=4;
	printf("W=%dʱ%s\n",W,(Loading(W,w,n-1)?"���ڽ�":"û�н�"));
	W=10;
	printf("W=%dʱ%s\n",W,(Loading(W,w,n-1)?"���ڽ�":"û�н�"));
	W=12;
	printf("W=%dʱ%s\n",W,(Loading(W,w,n-1)?"���ڽ�":"û�н�"));
	W=21;
	printf("W=%dʱ%s\n",W,(Loading(W,w,n-1)?"���ڽ�":"û�н�"));
}
