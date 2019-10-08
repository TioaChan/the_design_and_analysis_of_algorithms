//�����Զ���������㷨
#include "Fundament.cpp"
//����Ϊ����Զ��Ե������㷨��������
double Mostdistp(vector<Point> a,int &maxindex1,int &maxindex2)
//��ٷ���a�е���Զ���,��vector��ŵ㼯
{
	int i,j;
	double d,maxdist=0.0;
    for (i=0;i<a.size();i++)
        for (j=i+1;j<a.size();j++)
        {
			d=Distance(a[i],a[j]);
			if (d>maxdist)
			{
				maxdist=d;
				maxindex1=i;
				maxindex2=j;
			}
		}
	return maxdist;
}
double Mostdistp1(Point a[],int n,int &maxindex1,int &maxindex2)
//��ٷ���a�е���Զ���,�������ŵ㼯
{
	int i,j;
	double d,maxdist=0.0;
    for (i=0;i<n;i++)
        for (j=i+1;j<n;j++)
        {
			d=Distance(a[i],a[j]);
			if (d>maxdist)
			{
				maxdist=d;
				maxindex1=i;
				maxindex2=j;
			}
		}
	return maxdist;
}
double RotatingCalipers1(Point ch[],int m,int &maxindex1,int &maxindex2)
{	//��RotatingCalipers����
	int i,j;
	double maxdist=0.0,d1,d2;
	ch[m]=ch[0];
	j=1;
	for (i=0;i<m;i++)
	{
		printf("�����i=%d:",i); ch[i].disp(); printf("\n");
		while (fabs(Det(ch[i]-ch[i+1],ch[j+1]-ch[i+1]))>fabs(Det(ch[i]-ch[i+1],ch[j]-ch[i+1])))
		//while (Cross(ch[i+1],ch[j+1],ch[i])>=Cross(ch[i+1],ch[j],ch[i]))
		{
			printf("j=%d:\t",j);
			printf("(%d,%d,%d):%g\t(%d,%d,%d):%g\n",i,i+1,j+1,fabs(Det(ch[i]-ch[i+1],ch[j+1]-ch[i+1])),i,i+1,j,fabs(Det(ch[i]-ch[i+1],ch[j]-ch[i+1])));
			j=(j+1)%m;		//��������жϣ���Ϊ�ױ���һ���ģ�����������˵��Ҫ��ƽ����ԶЩ
		}
		printf("�ҵ�j=%d:",j); ch[j].disp(); printf("\n");
		d1=Distance(ch[i],ch[j]);
		printf("(%g,%g),(%g,%g)=%g\n",ch[i].x,ch[i].y,ch[j].x,ch[j].y,d1);
		if (d1>maxdist)
		{
			maxdist=d1;
			maxindex1=i;
			maxindex2=j;
		}
		d2=Distance(ch[i+1],ch[j]);
		printf("(%g,%g),(%g,%g)=%g\n",ch[i+1].x,ch[i+1].y,ch[j].x,ch[j].y,d2);
		if (d2>maxdist)
		{
			maxdist=d2;
			maxindex1=i+1;
			maxindex2=j;
		}
	}
	return maxdist;
}
//---------Graham�㷨--------------
Point p0;		//���,ȫ�ֱ���
bool pointcmp(Point &a,Point &b)
{
	if (Direction(p0,a,b)>0)
		return true;
	else
		return false;
}
int Graham(vector<Point> &a,Point ch[])
{
    int top=-1,i,k;
	Point tmp; 
	k=0;
	for (i=1;i<a.size();i++)	//��������ƫ��ĵ�a[k]
		if ((a[i].y<a[k].y) || (a[i].y==a[k].y && a[i].x<a[k].x))
			k=i;
    tmp=a[0];					//ͨ��������a[k]��ָ��Ϊ���a[0] 
    a[0]=a[k];	a[k]=tmp; 
	p0=a[0];					//�����a[0]����p0��
	printf("���a0:"); p0.disp();
    sort(a.begin(),a.end(),pointcmp);	//�����Ǵ�С��������
	printf("�����:\n");
	for (vector<Point>::iterator it=a.begin();it!=a.end();it++)
		(*it).disp();
	printf("\n");
	top++;ch[0]=a[0];			//ǰ�������Ƚ�ջ 
	top++;ch[1]=a[1]; 
	top++;ch[2]=a[2];
	a[0].disp(); printf("��ջ\n");
	a[1].disp(); printf("��ջ\n");
	a[2].disp(); printf("��ջ\n");
	for (i=3;i<a.size();i++)	//�ж����������е�Ĺ�ϵ
	{ 
		printf("�����");a[i].disp(); printf("\n");
		while (top>0 && Direction(ch[top-1],a[i],ch[top])>0)
		{
			ch[top].disp(); printf("�����ҹչ�ϵ����ջ\n");
			top--;				//�����ҹչ�ϵ,ջ��Ԫ�س�ջ
		}
		top++; ch[top]=a[i];	//��ǰ����ջ�����е����������ϵ,��˽�ջ
		a[i].disp(); printf("��ջ\n");
	}
    return top+1;				//����ջ��Ԫ�ظ���
}
//-----------------------------------
void RotatingCalipers(vector<Point> &a)	//��ת�����㷨
{
	int m,index1,index2;
	Point ch[MAXN];
	m=Graham(a,ch);
	printf("͹��:");
	for (int i=0;i<m;i++)		//���͹��
		ch[i].disp();
	printf("\n");
	double maxdist=RotatingCalipers1(ch,m,index1,index2);
	//double maxdist=Mostdistp1(ch,m,index1,index2);
	printf("��Զ���:(%g,%g)��(%g,%g),��Զ����=%g\n",ch[index1].x,ch[index1].y,ch[index2].x,ch[index2].y,maxdist);
}
//����Զ��Ե�������
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
	RotatingCalipers(a);
}
