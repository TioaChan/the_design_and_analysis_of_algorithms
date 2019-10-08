//�����Ļ��������㷨
//#pragma warning( disable:4786) 
#include <algorithm>
#include <vector>
using namespace std;
#include <stdio.h>
#include <math.h>
#define INF 32767			//��
#define MAXN 20
int sign(double x)			//������ֵx�ķ���
{
	if (x>0) return 1;
	else if (x<0) return -1;
	else return 0;
}
double sqr(double x)		//��x��ƽ��
{
	return x*x;
}
//--����VC++6.0������bug�����԰�װ��������������������´�������
class Point;
bool operator ==(Point &p1,Point &p2);	//����==�����
Point operator +(Point &p1,Point &p2);	//����+�����
Point operator -(Point &p1,Point &p2);	//����-�����
double Dot(Point p1,Point p2);			//���������ĵ��
double Length(Point &p);	//����������
int Angle(Point p0,Point p1,Point p2);	//�����߶�p0p1��p0p2�ļн�
double Det(Point p1,Point p2);			//���������Ĳ��
int Direction(Point p0,Point p1,Point p2);	//�ж����߶�p0p1��p0p2�ķ���
double Distance(Point p1,Point p2);		//��������ľ���
double DistPtoSegment(Point p0,Point p1,Point p2);	//��p0��p1p2�߶εľ���

bool InRectAngle(Point p0,Point p1,Point p2);		//�жϵ�p0�Ƿ���p1��p2��ʾ�ľ�����
bool OnSegment(Point p0,Point p1,Point p2);			//�жϵ�p0�Ƿ���p1p2�߶���
bool Parallel(Point p1,Point p2,Point p3,Point p4);	//�ж�p1p2��p3p4�߶��Ƿ�ƽ��
bool SegIntersect(Point p1,Point p2,Point p3,Point p4);	//�ж�p1p2��p3p4���߶��Ƿ��ཻ
bool PointInPolygon(Point p0,vector<Point> a);	//�жϵ�p0�Ƿ��ڵ㼯a���γɵĶ������

double triangleArea(Point p1,Point p2,Point p3);	//�����������
double polyArea(vector<Point> p);	//���������

//
class Point					//����
{
public:
	double x;				//������
	double y; 				//������
	Point() {}						//Ĭ�Ϲ��캯��
	Point(double x1,double y1)		//���ع��캯��
	{	x=x1;
		y=y1;
	}
	void disp()
	{	printf("(%g,%g) ",x,y); }
	friend bool operator ==(Point &p1,Point &p2);		//����==�����
	friend Point operator +(Point &p1,Point &p2);		//����+�����
	friend Point operator -(Point &p1,Point &p2);		//����-�����
	friend double Dot(Point p1,Point p2);				//���������ĵ��
	friend double Length(Point &p);						//����������
	friend int Angle(Point p0,Point p1,Point p2);		//�����߶�p0p1��p0p2�ļн�
	friend double Det(Point p1,Point p2);				//���������Ĳ��
	friend int Direction(Point p0,Point p1,Point p2);	//�ж����߶�p0p1��p0p2�ķ���
	friend double Distance(Point p1,Point p2);			//��������ľ���
	friend double DistPtoSegment(Point p0,Point p1,Point p2);	//��p0��p1p2�߶εľ���

	friend bool InRectAngle(Point p0,Point p1,Point p2);		//�жϵ�p0�Ƿ���p1��p2��ʾ�ľ�����
	friend bool OnSegment(Point p0,Point p1,Point p2);			//�жϵ�p0�Ƿ���p1p2�߶���
	friend bool Parallel(Point p1,Point p2,Point p3,Point p4);	//�ж�p1p2��p3p4�߶��Ƿ�ƽ��
	friend bool SegIntersect(Point p1,Point p2,Point p3,Point p4);//�ж�p1p2��p3p4���߶��Ƿ��ཻ
	friend bool PointInPolygon(Point p0,vector<Point> a);	//�жϵ�p0�Ƿ��ڵ㼯a���γɵĶ������

	friend double triangleArea(Point p1,Point p2,Point p3);	//�����������
	friend double polyArea(vector<Point> p);	//���������
};
//--��������Ԫʵ�ִ���-----
bool operator ==(Point &p1,Point &p2)	//����==�����
{
	return p1.x==p2.x && p1.y==p2.y;
}
Point operator +(Point &p1,Point &p2)	//����+�����
{
	return Point(p1.x+p2.x,p1.y+p2.y);
}
Point operator -(Point &p1,Point &p2)	//����-�����
{
	return Point(p1.x-p2.x,p1.y-p2.y);
}
double Dot(Point p1,Point p2)			//���������ĵ��
{
	return p1.x*p2.x+p1.y*p2.y;
}
double Length(Point &p)					//����������
{
	return sqrt(Dot(p,p));
}
int Angle(Point p0,Point p1,Point p2)	//�����߶�p0p1��p0p2�ļн�
{
	double d=Dot((p1-p0),(p2-p0));
	if (d==0)
		return 0;		//���߶�p1p0��p2p0�н�Ϊֱ��
	else if (d>0)
		return 1;		//���߶�p1p0��p2p0�ļн�Ϊ�۽�
	else
		return -1;		//���߶�p1p0��p2p0�ļн�Ϊ���
}
double Det(Point p1,Point p2)			//���������Ĳ��
{
	return p1.x*p2.y-p1.y*p2.x;
}
int Direction(Point p0,Point p1,Point p2)	//�ж����߶�p0p1��p0p2�ķ���
{
	double d=Det((p1-p0),(p2-p0));
	if (d==0)
		return 0;		//3�㹲��
	else if (d>0)
		return 1;		//p0p2��p0p1��˳ʱ�뷽����
	else
		return -1;		//p0p2��p0p1����ʱ�뷽����
}
double Distance(Point p1,Point p2)		//������֮��ľ���
{
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
double DistPtoSegment(Point p0,Point p1,Point p2)	//��p0��p1p2�߶εľ���
{
	Point v1=p2-p1,v2=p1-p2,v3=p0-p1,v4=p0-p2;
	if (p1==p2)
		return Length(p0-p1);
	if (Dot(v1,v3)<0)
		return Length(v3);
	else if (Dot(v2,v4)<0)
		return Length(v4);
	else
		return fabs(Det(v1,v3))/Length(v1);
}


bool InRectAngle(Point p0,Point p1,Point p2)		//�жϵ�p0�Ƿ���p1��p2��ʾ�ľ�����
{
	return Dot(p1-p0,p2-p0)<=0;
}
bool OnSegment(Point p0,Point p1,Point p2)			//�жϵ�p0�Ƿ���p1p2�߶���
{
	return Det(p1-p0,p2-p0)==0 && Dot(p1-p0,p2-p0)<=0;
}

bool Parallel(Point p1,Point p2,Point p3,Point p4)	//�ж�p1p2��p3p4�߶��Ƿ�ƽ��
{
	return Det(p2-p1,p4-p3)==0;
}

double DistPtoSegment1(Point p0,Point p1,Point p2)	//��p0��p1p2�߶εľ���
{
	if (p1==p2)
		return Length(p0-p1);
	if (Dot(p2-p1,p0-p1)<0)
		return Length(p1-p1);
	else if (Dot(p2-p1,p0-p2)>0)
		return Length(p0-p2);
	else
		return fabs(Det(p2-p1,p0-p1))/Length(p2-p1);
}
bool SegIntersect(Point p1,Point p2,Point p3,Point p4)	//�ж�p1p2��p3p4���߶��Ƿ��ཻ
{
	int d1,d2,d3,d4;
	d1=Direction(p3,p1,p4);		//��p3p1��p3p4���ĸ�������
	d2=Direction(p3,p2,p4);		//��p3p2��p3p4���ĸ�������
	d3=Direction(p1,p3,p2);		//��p1p3��p1p2���ĸ�������
	d4=Direction(p1,p4,p2);		//��p1p4��p1p2���ĸ�������
	if (d1*d2<0 && d3*d4<0)
		return true;
	if (d1==0 && OnSegment(p1,p3,p4))		//��d1Ϊ0��p1��p3p4�߶���
		return true;
	else if (d2==0 && OnSegment(p2,p3,p4))	//��d2Ϊ0��p2��p3p4�߶���
		return true;
	else if (d3==0 && OnSegment(p3,p1,p2))	//��d3Ϊ0��p3��p1p2�߶���
		return true;
	else if (d4==0 && OnSegment(p4,p1,p2))	//��d4Ϊ0��p4��p1p2�߶���
		return true;
	else
		return false;
}
bool PointInPolygon(Point p0,vector<Point> a)	//�жϵ�p0�Ƿ��ڵ㼯a���γɵĶ������
{	int i,cnt=0;		//cnt�ۼӽ������
	double x;
	Point p1,p2;
	for (i=0;i<a.size();i++)
	{	p1=a[i]; p2=a[i+1];
		if (OnSegment(p0,p1,p2))
			return true;							//�����p0�ڶ���α�p1p2��,����true
		//�������y=p0.y��p1p2�Ľ���
		if (p1.y==p2.y) continue;					//���p1p2��ˮƽ��,ֱ������
		//������������ǽ�����p1p2�ӳ�����
		if (p0.y<p1.y && p0.y<p2.y) continue;		//p0��p1p2�߶��·�,ֱ������
		if (p0.y>=p1.y && p0.y>=p2.y) continue;		//p0��p1p2�߶��Ϸ�,ֱ������
		x=(p0.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;	//�󽻵������xֵ
		if (x>p0.x) cnt++;							//ֻͳ�����ߵ�һ��
	}
	return (cnt%2==1);
}
double triangleArea(Point p1,Point p2,Point p3)	//�����������
{
	return fabs(Det(p1-p2,p3-p2))/2;
}

double polyArea(vector<Point> p)	//���������
{
	double ans=0.0;
	for (int i=1;i<p.size()-1;i++)
		ans+=Det(p[i]-p[0],p[i+1]-p[0]);
	return fabs(ans)/2;
}
/*
void main()
{
	vector<Point> a;
	a.push_back(Point(5,0));
	a.push_back(Point(9,3));
	a.push_back(Point(10,7));
	a.push_back(Point(4,9));
	a.push_back(Point(0,6));
	a.push_back(Point(3,5));
	a.push_back(Point(0,2));
	for (int i=1;i<a.size()-1;i++)
		printf("(p[%d]-p[0])��(p[%d]-p[0])/2=%g\n",i,i+1,Det(a[i]-a[0],a[i+1]-a[0])/2);
	printf("Area=%g\n",polyArea(a));
}
*/