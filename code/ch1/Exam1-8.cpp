//��1.8
#include <stdio.h>
void Hanoi(int n,char x,char y,char z)
{	if (n==1)
		printf("����Ƭ%d��%c�ᵽ%c\n",n,x,z);
	else
	{	Hanoi(n-1,x,z,y);
		printf("����Ƭ%d��%c�ᵽ%c\n",n,x,z);
		Hanoi(n-1,y,x,z);
	}
}
void main()
{
	int n=4;
	Hanoi(n,'X','Y','Z');
}
