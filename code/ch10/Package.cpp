//���͹������-��Ʒ�����㷨
#include "Fundament.cpp"	//����Point���������㷨
//----��Ʒ�����㷨
bool cmp(Point aj,Point ai,Point ak)
{
	int d=Direction(aj,ai,ak);
	if (d==0)		//����ʱ,��ajai�����򷵻�true
		return Distance(aj,ak)<Distance(aj,ai);
	else if (d>0)	//ajai��ajak��˳ʱ�뷽����,����true
		return true;
	else			//���򷵻�false
		return false;
}
void Package(vector<Point> a,vector<int> &ch)	//��Ʒ�����㷨
{
	int i,j,k,tmp;
	j=0;
	for (i=1;i<a.size();i++)
		if (a[i].x<a[j].x || (a[i].x==a[j].x && a[i].y<a[j].y))
			j=i;			//���������͵�j
	tmp=j;					//tmp�������
	while (true)
	{
		k=-1;
		ch.push_back(j);	//����aj��Ϊ͹���ϵ�һ����
		for (i=0;i<a.size();i++)
			if (i!=j && (k==-1 || cmp(a[j],a[i],a[k])))
				k=i;		//��aj�����ҽǶ���С�ĵ�ai
		if (k==tmp) break;	//�ҳ����ʱ����
		j=k;
	}
}
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
	Point st[MAXN];
	vector<int> ch;
	Package(a,ch);
	printf("�����\n");
	printf("   ͹���Ķ���: ");
	for (vector<int>::iterator it=ch.begin();it!=ch.end();it++)
		printf("%d ",*it);
	printf("\n");
}
