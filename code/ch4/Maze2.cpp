#include <stdio.h>
#define MAXQ 100					//���д�С
#define MAxN 10						//����Թ���С
//�����ʾ
int n=8;							//�Թ���С
char Maze[MAxN][MAxN]=
{	{'O','X','X','X','X','X','X','X'},
	{'O','O','O','O','O','X','X','X'},
	{'X','O','X','X','O','O','O','X'},
	{'X','O','X','X','O','X','X','O'},
	{'X','O','X','X','X','X','X','X'},
	{'X','O','X','X','O','O','O','X'},
	{'X','O','O','O','O','X','O','O'},
	{'X','X','X','X','X','X','X','O'}
};
int H[4] = {0, 1, 0, -1};			//ˮƽƫ����,�±��Ӧ��λ��0��3
int V[4] = {-1, 0, 1, 0};			//��ֱƫ����
struct Position						//����Ԫ������
{
	int x,y;						//��ǰ����λ��
	int pre;						//ǰ��������±�
};
Position qu[MAXQ];					//����һ������qu
int front=-1,rear=-1;				//�����ͷ�Ͷ�β

void disppath(int front)			//���һ���Թ�·��
{
	int i,j;
	for (i=0; i<n;i++)				//������'*'��Ϊ'O'
		for (j=0;j<n;j++)
			if (Maze[i][j]=='*')
				Maze[i][j]='O';
	int k=front;
	while (k!=-1)					//��·���ϵķ����Ϊ' '
	{
		Maze[qu[k].x][qu[k].y]=' ';
		k=qu[k].pre;
	}
	for (i=0; i<n;i++)				//����Թ�·��
	{	printf("    ");
		for(int j=0; j<n;j++)
			printf("%c",Maze[i][j]);
		printf("\n");
	}
}
void BFS(int x,int y)			 //���(x,y)������һ���Թ�·��
{
	Position p,p1,p2;
	p.x=x; p.y=y; p.pre=-1;			//������ڽ��
	Maze[p.x][p.y]='*';				//��Ϊ'*'�����ظ�����
	rear++; qu[rear]=p;				//��ڷ������
	while (front!=rear)				//�Ӳ���ѭ��
	{
		front++; p1=qu[front];		//���ӷ���p1;
		if (p1.x==n-1 && p1.y==n-1)	//�ҵ�����
		{
			disppath(front);		//���·��
			return;
		}
		for (int k=0;k<4;k++)		//��̽p1��ÿ�����ڷ�λ
		{
			p2.x=p1.x+V[k];			//�ҵ�p1�����ڷ���p2
			p2.y=p1.y+H[k];
			if (p2.x>=0 && p2.y>=0 && p2.x<n && p2.y<n && Maze[p2.x][p2.y]=='O')
			{	//����p2��Ч���ҿ���
				Maze[p2.x][p2.y]='*';	//��Ϊ'*'�����ظ�����
				p2.pre=front;
				rear++;	qu[rear]=p2;	//����p2����
			}
		}
	}
}
void main()
{
	int x=0,y=0;		//ָ�����,����Ĭ��Ϊ(n-1,n-1)
	printf("һ���Թ�·��:\n");
	BFS(x,y);			//��(0,0)->(7,7)��һ���Թ�·��
}
