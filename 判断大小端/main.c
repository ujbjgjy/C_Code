#include <stdio.h>

int main()
{
	int i = 1;

	if (1 == *(char*)&i)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}