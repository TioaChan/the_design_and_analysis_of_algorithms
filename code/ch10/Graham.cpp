//���͹������-Grahamɨ���㷨
#include "Fundament.cpp"
Point p0;		//���,ȫ�ֱ���
void swap(Point &x,Point &y)		//����x��y������
{
	Point tmp=x;
	x=y; y=x;
}
bool cmp(Point &a,Point &b)			//����ȽϺ���
{
	if (Direction(p0,a,b)>0)
		return true;
	else
		return false;
}
int Graham(vector<Point> &a,Point ch[])		//��͹����Graham�㷨
{
    int top=-1,i,k=0;
	Point tmp; 
	for (i=1;i<a.size();i++)	//��������ƫ��ĵ�a[k]
		if ((a[i].y<a[k].y) || (a[i].y==a[k].y && a[i].x<a[k].x))
			k=i;
    swap(a[0],a[k]);			//ͨ��������a[k]��ָ��Ϊ���a[0] 
	p0=a[0];					//�����a[0]����p0��
    sort(a.begin()+1,a.end(),cmp);	//�����Ǵ�С��������
	top++;ch[0]=a[0];			//ǰ3�����Ƚ�ջ 
	top++;ch[1]=a[1]; 
	top++;ch[2]=a[2];
	for (i=3;i<a.size();i++)	//�ж����������е�Ĺ�ϵ
	{ 
		while (top>=0 && (Direction(ch[top-1],a[i],ch[top])>0 || 
			Direction(ch[top-1],a[i],ch[top])==0 && Distance(ch[top-1],a[i])>Distance(ch[top-1],ch[top])))
		{
			top--;				//�����ҹչ�ϵ,ջ��Ԫ�س�ջ
		}
		top++; ch[top]=a[i];	//��ǰ����ջ�����е����������ϵ,��˽�ջ
	}
    return top+1;				//����ջ��Ԫ�ظ���
}
//Graham�㷨��������
void main()
{
	vector<Point> a;
	a.push_back(Point(4,10));
	a.push_back(Point(3,7));
	a.push_back(Point(9,7));
	a.push_back(Point(3,4));
	a.push_back(Point(5,6));
	a.push_back(Point(5,4));
	a.push_back(Point(6,3));
	a.push_back(Point(8,1));
	a.push_back(Point(3,0));
	a.push_back(Point(1,6));
	Point st[MAXN];					//����ջ
	int n;
	n=Graham(a,st);
	printf("�����\n");
	printf("   ͹���Ķ���: ");
	for (int i=0;i<n;i++)			//ջ������Ԫ��Ϊ͹��
		st[i].disp();
	printf("\n");
}