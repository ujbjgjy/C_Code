#include "header.h"

void Print(const int(*ps)[NUMBER][LINE][COLUMN],int sum)//��ӡ��ͼ
{
	int i=0, j=0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if ((*ps)[sum][i][j] == cle)
				printf("  ");
			else
				printf("%d ", (*ps)[sum][i][j]);
		}
		printf("\n");
	}
}

int Operation(int(*ps)[NUMBER][LINE][COLUMN])//ִ����Ϸ����
{
	int sum = 0;//��ǰ�ؿ�
	int i = 0, j = 0;
	if(Location(ps, sum, &i, &j)) return -1;

	int iput = 1;
	while (iput!=27||iput!=-1)
	{
		char mob = getch();
		iput = mob;
		switch (mob)
		{
		case 'h':
		case 72:
			if ((*ps)[sum][i - 1][j] == cle || (*ps)[sum][i - 1][j] == tar)//ǰ��1�յػ�Ŀ��
			{
				(*ps)[sum][i - 1][j] += fig;//ǰ��1�յ�Ŀ��+����
				(*ps)[sum][i][j] -= fig;//ԭλ-����
				--i;
			}
			else if ((*ps)[sum][i - 1][j] == box || (*ps)[sum][i - 1][j] == box + tar)//ǰ�������ӻ�����+Ŀ��
			{
				if ((*ps)[sum][i - 2][j] != wall && (*ps)[sum][i - 2][j] != box && (*ps)[sum][i - 2][j] != box)//ǰ�治����ǽ������
				{
					(*ps)[sum][i - 2][j] += box;
					(*ps)[sum][i - 1][j] = (*ps)[sum][i - 1][j]-box+fig;
					(*ps)[sum][i][j] -= fig;
					--i;
				}
			}
			break;
		case 'l':
		case 80:
			if ((*ps)[sum][i + 1][j] == cle || (*ps)[sum][i + 1][j] == tar)//ǰ��1�յػ�Ŀ��
			{
				(*ps)[sum][i + 1][j] += fig;//ǰ��1�յ�Ŀ��+����
				(*ps)[sum][i][j] -= fig;//ԭλ-����
				++i;
			}
			else if ((*ps)[sum][i + 1][j] == box || (*ps)[sum][i + 1][j] == box + tar)//ǰ�������ӻ�����+Ŀ��
			{
				if ((*ps)[sum][i + 2][j] != wall && (*ps)[sum][i + 2][j] != box && (*ps)[sum][i + 2][j] != box+tar)//ǰ�治����ǽ������
				{
					(*ps)[sum][i + 2][j] += box;
					(*ps)[sum][i + 1][j] = (*ps)[sum][i + 1][j] - box + fig;
					(*ps)[sum][i][j] -= fig;
					++i;
				}
			}
			break;
		case 'j':
		case 75:
			if ((*ps)[sum][i][j - 1] == cle || (*ps)[sum][i][j - 1] == tar)//ǰ��1�յػ�Ŀ��
			{
				(*ps)[sum][i][j - 1] += fig;//ǰ��1�յ�Ŀ��+����
				(*ps)[sum][i][j] -= fig;//ԭλ-����
				--j;
			}
			else if ((*ps)[sum][i][j - 1] == box || (*ps)[sum][i][j - 1] == box + tar)//ǰ�������ӻ�����+Ŀ��
			{
				if ((*ps)[sum][i][j - 2] != wall && (*ps)[sum][i][j - 2] != box && (*ps)[sum][i][j - 2] != box + tar)//ǰ�治����ǽ������
				{
					(*ps)[sum][i][j - 2] += box;
					(*ps)[sum][i][j - 1] = (*ps)[sum][i][j - 1] - box + fig;
					(*ps)[sum][i][j] -= fig;
					--j;
				}
			}
			break;
		case 'k':
		case 77:
			if ((*ps)[sum][i][j + 1] == cle || (*ps)[sum][i][j + 1] == tar)//ǰ��1�յػ�Ŀ��
			{
				(*ps)[sum][i][j + 1] += fig;//ǰ��1�յ�Ŀ��+����
				(*ps)[sum][i][j] -= fig;//ԭλ-����
				++j;
			}
			else if ((*ps)[sum][i][j + 1] == box || (*ps)[sum][i][j + 1] == box + tar)//ǰ�������ӻ�����+Ŀ��
			{
				if ((*ps)[sum][i][j + 2] != wall && (*ps)[sum][i][j + 2] != box && (*ps)[sum][i][j + 2] != box + tar)//ǰ�治����ǽ������
				{
					(*ps)[sum][i][j + 2] += box;
					(*ps)[sum][i][j + 1] = (*ps)[sum][i][j + 1] - box + fig;
					(*ps)[sum][i][j] -= fig;
					++j;
				}
			}
			break;
		}

		system("cls");
		if (!check(ps,sum))
		{
			if (sum < NUMBER)
			{
				++sum;
				if (Location(ps, sum, &i, &j)) return -1;//ÿ��һ������������
			}
			else
			{
				return 1;
			}
		}
		Print(ps, sum);
	}

	if (iput == 27)
		return 0;
	else
		return 1;
}

int check(int(*ps)[NUMBER][LINE][COLUMN],int sum)//�����û������
{
	int i = 0, j = 0;
	int cost = 0;//������ٸ�����
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if ((*ps)[sum][i][j] == box)
				cost++;
		}
	}
	return cost;
}

int Location(const int(*ps)[NUMBER][LINE][COLUMN], int sum, int* x, int* y)//�ҵ���������
{
	int i = 0, j = 0;
	for (i = 0; i < LINE; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			if ((*ps)[sum][i][j] == fig || (*ps)[sum][i][j] == fig + tar)
				break;
		}
		if ((*ps)[sum][i][j] == fig || (*ps)[sum][i][j] == fig + tar)
			break;
	}
	if ((*ps)[sum][i][j] != fig && (*ps)[sum][i][j] != fig + tar)
	{
		return 1;
	}
	else
	{
		*x = i, *y = j;
		return 0;
	}
}