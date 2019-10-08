#include<stdio.h>
#define MAX 1025
//问题表示
int k;							//棋盘大小
int x,y;						//特殊方格的位置
int board[MAX][MAX];
int tile=1;									//L型骨牌的编号,从1开始
void ChessBoard(int tr,int tc,int dr,int dc,int size)
{
	if(size==1) return;						//递归出口
	int t=tile++;							//取一个L型骨，其牌号为tile
	int s=size/2;							//分割棋盘
	//考虑左上角象限
	if(dr<tr+s && dc<tc+s)					//特殊方格在此象限中
		ChessBoard(tr,tc,dr,dc,s);
	else									//此象限中无特殊方格
	{
		board[tr+s-1][tc+s-1]=t;				//用t号L型骨牌覆盖右下角
		ChessBoard(tr,tc,tr+s-1,tc+s-1,s);	//将右下角作为特殊方格继续处理该象限
	}
	//考虑右上角象限
	if(dr<tr+s && dc>=tc+s)  
		ChessBoard(tr,tc+s,dr,dc,s);		//特殊方格在此象限中 
	else									//此象限中无特殊方格
	{
		board[tr+s-1][tc+s]=t;					//用t号L型骨牌覆盖左下角
		ChessBoard(tr,tc+s,tr+s-1,tc+s,s);  	//将左下角作为特殊方格继续处理该象限
	}
	//处理左下角象限
	if(dr>=tr+s && dc<tc+s)					//特殊方格在此象限中
		ChessBoard(tr+s,tc,dr,dc,s);  
	else 									//此象限中无特殊方格
	{
		board[tr+s][tc+s-1]=t;  				//用t号L型骨牌覆盖右上角
        	ChessBoard(tr+s,tc,tr+s,tc+s-1,s);	//将右上角作为特殊方格继续处理该象限
   	}
	//处理右下角象限
	if(dr>=tr+s && dc>=tc+s)					//特殊方格在此象限中
		ChessBoard(tr+s,tc+s,dr,dc,s); 
	else									//此象限中无特殊方格
	{	
		board[tr+s][tc+s]=t;  					//用t号L型骨牌覆盖左上角
		ChessBoard(tr+s,tc+s,tr+s,tc+s,s);  	//将左上角作为特殊方格继续处理该象限
	}
}
void main()  
{
	k=3;
	x=1; y=2;
	int size=1<<k;
	ChessBoard(0, 0, x, y, size);
	for(int i=0; i<size; i++)					//输出方案
	{
		for(int j=0; j<size;j++)
			printf("%4d",board[i][j]);
		printf("\n");
	}
}
