//���������������㷨(���԰汾)
#include "Fundament.cpp"
//����Ϊ�������Ե������㷨��������
double ClosestPoints(vector<Point> a,int leftindex,int rightindex,int &minindex1,int &minindex2)
//��ٷ���a[leftindex..rightindex]�е�������
{
	int i,j;
	double d,mindist =INF;
    for (i=leftindex;i<=rightindex;i++)
        for (j=i+1;j<=rightindex;j++)
        {
			d=Distance(a[i],a[j]);
			if (d<mindist)
			{
				mindist=d;
				minindex1=i;
				minindex2=j;
			}
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
double ClosestPoints11(vector<Point> &a,vector<Point> b,int leftindex,int rightindex,int &minindex1,int &minindex2)
//�ݹ���a[leftindex..rightindex]�е�������
{
	vector<Point> leftb,rightb,b1;
	int i,j,midindex;
	int leftminindex1,leftminindex2;		//��ߵ�������
	int rightminindex1,rightminindex2;		//�ұߵ�������
	double d1,d2,d3,d;
	if ((rightindex-leftindex+1)<=3)		//����4����,ֱ������ٷ����
	{
		d=ClosestPoints(a,leftindex,rightindex,minindex1,minindex2);
		printf("  ��������4:����������=%g: ",d); a[minindex1].disp(); a[minindex2].disp(); printf("\n");
		return d;
	}
    midindex=(leftindex+rightindex)/2;	//���м�λ��
	printf("midindex=%d ",midindex); a[midindex].disp(); printf("\n");
	for (i=0;i<b.size();i++)			//��b�е㼯��Ϊ����������
		if (b[i].x<a[midindex].x)
			leftb.push_back(b[i]);
		else
			rightb.push_back(b[i]);
	printf("Left:"); display(a,leftindex,midindex);
    d1=ClosestPoints11(a,leftb,leftindex,midindex,leftminindex1,leftminindex2);
	printf("  d1=%g ",d1); a[leftminindex1].disp(); a[leftminindex2].disp(); printf("\n");

	printf("Right:"); display(a,midindex+1,rightindex);
	d2=ClosestPoints11(a,rightb,midindex+1,rightindex,rightminindex1,rightminindex2);
	printf("  d2=%g ",d2); a[rightminindex1].disp();a[rightminindex2].disp();printf("\n");

	d=INF;		//��ǰ��С����d=MIN(d1,d2)
    if (d1<d2)
    {
        minindex1=leftminindex1;
        minindex2=leftminindex2;
        d=d1;
    }
    else
	{
        minindex1=rightminindex1;
        minindex2=rightminindex2;
        d=d2;
    }
	printf("  ���Ҳ������d=%g\n",d);
    //���м䲿�ֵ�Ե���С����
	for (i=0;i<b.size();i++)	//��b�м���Ϊ2*d�Ĵ�״�����ڵ��Ӽ����Ƶ�b1��
		if (fabs(b[i].x-a[midindex].x)<=d)
			b1.push_back(b[i]);
	printf("  �м䲿�ֵ㼯:"); display(b1,0,b1.size()-1);
	d3=INF;
	double tmpd3;
	int midminindex1,midminindex2;
	for (i=0;i<b1.size();i++)	//��b1��������
		for (j=i+1;j<b1.size();j++)
		{
			if (b1[j].y-b1[i].y>=d) break;
			tmpd3=Distance(b1[i],b1[j]);
			printf("  Mid��");b1[i].disp(); b1[j].disp(); printf("tmpd3=%g\n",tmpd3);
			if (tmpd3<d3)
			{
				midminindex1=i;
				midminindex2=j;
				d3=tmpd3;
			}
		}
	printf("�м䲿�ֽ��:d3=%g,��Ӧ�ĵ��:",d3); b1[midminindex1].disp(); b1[midminindex2].disp(); printf("\n");
	if (d<d3)
	{
		printf("�ϲ������d=%g ",d); a[minindex1].disp(); a[minindex2].disp(); printf("\n");
	}
	else
	{
		d=d3;
		printf("�ϲ����m��d=%g ",d); b1[midminindex1].disp(); b1[midminindex2].disp(); printf("\n");
	}
	return d;
}
double ClosestPoints1(vector<Point> &a,int leftindex,int rightindex,int &minindex1,int &minindex2)
//��a[leftindex..rightindex]�е�������
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
	return ClosestPoints11(a,b,0,a.size()-1,minindex1,minindex2);
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
	int index1,index2;
	double mindist=ClosestPoints1(a,0,a.size()-1,index1,index2);
}