#include "header.h"

void meun()
{
	printf("**************************\n");
	printf("*1:add	       2:delete  *\n");
	printf("*3:check       4:change  *\n");
	printf("*5:show        6:sorting *\n");
	printf("*7:save        0:exit    *\n");
	printf("**************************\n");
}
int main()
{
	int input = 0;

	struct Newsletter_type con = { 0 };
	Initialize(&con);
	do
	{
		meun();
		printf("==>");
		scanf("%d", &input);
		switch (input)
		{
		case 1://���
			ADD(&con);
			break;
		case 2://ɾ��
			Delete(&con);
			break;
		case 3://����
			Check(&con);
			break;
		case 4://�޸�
			Change(&con);
			break;
		case 5://��ʾ
			Print(&con);
			break;
		case 6://����
			Sorting(&con);
			Print(&con);
			break;
		case 0://�˳�
			printf("exit\n");
			Save(&con);
			free(con.deda);
			con.deda = NULL;
			return 0;
			break;
		case 7:
			Save(&con);
			break;
		default://�������
			printf("error\n");
			break;
		}
		
	} while (1);




	return 0;
}