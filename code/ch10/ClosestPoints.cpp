//���������������㷨
#include "Fundament.cpp"
#define min(x,y) ((x)<(y)?(x):(y))
//����Ϊ�������Ե������㷨��������
double ClosestPoints(vector<Point> a,int leftindex,int rightindex)
//��������a[leftindex..rightindex]�е������Ծ���
{
	int i,j;
	double d,mindist=INF;
    for (i=leftindex;i<=rightindex;i++)
        for (j=i+1;j<=rightindex;j++)
        {
			d=Distance(a[i],a[j]);
			if (d<mindist)
				mindist=d;
		}
	return mindist;
}
void display(vector<Point> a,int leftindex,int rightindex)	//���a�еĲ���Ԫ�أ����ڵ���
{
	int i;
	for (i=leftindex;i<=rightindex;i++)
		a[i].disp();
	printf("\n");
}
//���εݹ����Ծ���
bool pointxcmp(Point &p1,Point &p2)		//���ڵ㰴x�����������
{
	return p1.x<p2.x;
}
bool pointycmp(Point &p1,Point &p2)		//���ڵ㰴y�����������
{
	return p1.y<p2.y;
}
double ClosestPoints11(vector<Point> &a,vector<Point> b,int leftindex,int rightindex)
//�ݹ���a[leftindex..rightindex]�������Եľ���
{
	vector<Point> leftb,rightb,b1;
	int i,j,midindex;
	double d1,d2,d3=INF,d;
	if ((rightindex-leftindex+1)<=3)		//����4����,ֱ�������������
	{
		d=ClosestPoints(a,leftindex,rightindex);
		return d;
	}
    midindex=(leftindex+rightindex)/2;	//���м�λ��
	for (i=0;i<b.size();i++)			//��b�е㼯��Ϊ����������
		if (b[i].x<a[midindex].x)
			leftb.push_back(b[i]);
		else
			rightb.push_back(b[i]);
    d1=ClosestPoints11(a,leftb,leftindex,midindex);
	d2=ClosestPoints11(a,rightb,midindex+1,rightindex);
	d=min(d1,d2);	//��ǰ��С����d=MIN(d1,d2)
    //���м䲿�ֵ�Ե���С����
	for (i=0;i<b.size();i++)	//��b�м���Ϊ2*d�Ĵ�״�����ڵ��Ӽ����Ƶ�b1��
		if (fabs(b[i].x-a[midindex].x)<=d)
			b1.push_back(b[i]);
	double tmpd3;
	for (i=0;i<b1.size();i++)	//��b1��������
		for (j=i+1;j<b1.size();j++)
		{
			if (b1[j].y-b1[i].y>=d) break;
			tmpd3=Distance(b1[i],b1[j]);
			if (tmpd3<d3)
				d3=tmpd3;
		}
	d=min(d,d3);
	return d;
}
double ClosestPoints1(vector<Point> &a,int leftindex,int rightindex)
//��a[leftindex..rightindex]�������Եľ���
{
	int i;
	vector<Point> b;
	vector<Point>::iterator it;
	printf("����ǰ:\n");
	for (it=a.begin();it!=a.end();it++)
		(*it).disp();
	printf("\n");
    sort(a.begin(),a.end(),pointxcmp);	//��x�����С��������
	printf("��x���������:\n");
	for (it=a.begin();it!=a.end();it++)
		(*it).disp();
	printf("\n");

	for (i=0;i<a.size();i++)			//��a�е㼯���Ƶ�b��
		b.push_back(a[i]);

    sort(b.begin(),b.end(),pointycmp);	//��y�����С��������
	printf("��y���������:\n");
	for (it=b.begin();it!=b.end();it++)
		(*it).disp();
	printf("\n");
	return ClosestPoints11(a,b,0,a.size()-1);
}
//�������Ե�������
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
	double mindist=ClosestPoints1(a,0,a.size()-1);
	printf("�������=%g\n",mindist);
}