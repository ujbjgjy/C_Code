#include "header.h"

void game()
{
	int map[NUMBER][LINE][COLUMN] =
	{
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,1,1,1,0,0,0},
			{0,0,0,0,1,2,1,0,0,0},
			{0,1,1,1,1,3,1,0,0,0},
			{0,1,2,0,3,0,1,1,1,0},
			{0,1,1,1,3,4,3,2,1,0},
			{0,0,0,1,0,1,1,1,1,0},
			{0,0,0,1,2,1,0,0,0,0},
			{0,0,0,1,1,1,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,0,0},
			{0,1,0,4,2,2,2,1,0,0},
			{0,1,0,0,0,1,1,1,1,0},
			{1,1,1,3,0,0,0,0,1,0},
			{1,0,0,0,0,0,0,0,1,0},
			{1,0,3,0,1,3,1,0,1,0},
			{1,0,0,0,1,0,0,0,1,0},
			{1,1,1,1,1,1,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,1,0,0},
			{0,1,0,0,0,0,0,1,1,1},
			{1,1,3,1,1,1,0,0,0,1},
			{1,0,4,0,3,0,0,2,0,1},
			{1,0,2,2,1,0,2,0,1,1},
			{1,1,2,2,1,0,0,0,1,0},
			{0,1,1,1,1,1,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,1,1,1,1,0,0,0,0},
			{0,0,1,4,0,1,1,1,0,0},
			{0,0,1,0,3,0,0,1,0,0},
			{0,1,1,1,0,1,0,1,1,0},
			{0,1,2,1,0,1,0,0,1,0},
			{0,1,2,3,0,0,1,0,1,0},
			{0,1,2,0,0,0,3,0,1,0},
			{0,1,1,1,1,1,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,1,1},
			{0,0,1,1,0,0,1,0,4,1},
			{0,0,1,0,0,0,1,0,0,1},
			{0,0,1,3,0,3,0,3,0,1},
			{0,0,1,0,3,1,1,0,0,1},
			{1,1,1,0,3,0,1,0,1,1},
			{1,2,2,2,2,2,0,0,1,0},
			{1,1,1,1,1,1,1,1,1,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,0,0},
			{0,1,1,1,0,0,4,1,0,0},
			{0,1,0,0,3,2,0,1,1,0},
			{0,1,0,0,2,3,2,0,1,0},
			{0,1,1,1,0,4,3,0,1,0},
			{0,0,0,1,0,0,0,1,1,0},
			{0,0,0,1,1,1,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,0,0,0},
			{0,0,0,1,2,2,1,0,0,0},
			{0,0,1,1,0,2,1,1,0,0},
			{0,0,1,0,0,3,2,1,0,0},
			{0,1,1,0,3,0,0,1,1,0},
			{0,1,0,0,1,3,3,0,1,0},
			{0,1,0,0,4,0,0,0,1,0},
			{0,1,1,1,1,1,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,1,0},
			{0,1,1,1,0,0,0,0,1,0},
			{1,1,2,0,3,1,1,0,1,1},
			{1,2,2,3,0,3,0,0,4,1},
			{1,2,2,0,3,0,3,0,1,1},
			{1,1,1,1,1,1,1,0,1,0},
			{0,0,0,0,0,0,1,1,1,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,1,1,1,1,1,1,0},
			{0,0,0,1,0,0,0,0,1,0},
			{0,1,1,1,3,3,3,0,1,0},
			{0,1,4,0,3,2,2,0,1,0},
			{0,1,0,3,2,2,2,1,1,0},
			{0,1,1,1,1,0,0,1,0,0},
			{0,0,0,0,1,1,1,1,0,0},
			{0,0,0,0,0,0,0,0,0,0}
		},
		{
			{0,0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0,0},
			{0,1,1,1,1,1,1,0,0,0},
			{0,1,0,0,0,0,1,0,0,0},
			{0,1,0,3,3,3,1,1,0,0},
			{0,1,0,0,1,2,2,1,1,1},
			{0,1,1,0,0,2,2,3,0,1},
			{0,0,1,0,4,0,0,0,0,1},
			{0,0,1,1,1,1,1,1,1,1},
			{0,0,0,0,0,0,0,0,0,0}
		}
	};
	Print(&map,0);//��ӡ
	int iput=Operation(&map);//ִ����Ϸ����
	 
	if (iput == 1)
	{
		printf("ͨ�سɹ�\n");
	}
	else if (iput == 0)
	{
		printf("�˳�\n");
	}
	else
	{
		printf("�Ҳ�����ǰ�ؿ�������\n");
	}
}

int main()
{
	game();//��Ϸ

	getchar();
	return 0;
}