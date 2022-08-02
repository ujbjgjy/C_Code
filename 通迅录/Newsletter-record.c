#include "header.h"

void Initialize(struct Newsletter_type* ps)
{
	ps->deda = (struct Newsletter*)malloc(CURREMT * sizeof(struct Newsletter));
	ps->size = 0;
	ps->current = CURREMT;
	Load(ps);//�����ļ��е�ͨѸ¼��Ϣ
}

void Load(struct Newsletter_type* ps)
{
	Newsletter tmp = { 0 };
	FILE* pf = fopen("Newsletter_file.obj", "rb");
	if (pf == NULL)
	{
		printf("Load:%s\n", strerror(errno));
		return;
	}

	while (fread(&tmp, sizeof(Newsletter), 1, pf))
	{
		increase(ps);//����ռ䲻�������ݡ�
		ps->deda[ps->size] = tmp;
		ps->size++;
	}

	fclose(pf);
	pf = NULL;
}

int increase(struct Newsletter_type* ps)
{
	if (ps->size == ps->current)
	{
		Newsletter* ptr = (Newsletter*)realloc(ps->deda, (ps->current + CURREMT) * sizeof(Newsletter));
		if (ptr != NULL)
		{
			ps->deda = ptr;
			ps->current += CURREMT;
			printf("����\n");
		}
		else
		{
			printf("����ʧ��\n");
			return -1;
		}
	}
}



void ADD(struct Newsletter_type* ps)
{
	if(increase(ps)== -1) return;

	printf("����������=>");
	scanf("%s", ps->deda[ps->size].name);
	int tmp = check(ps);
	while (tmp != -1)
	{
		printf("�����ظ�������������\n");
		printf("����������=>");
		scanf("%s", ps->deda[ps->size].name);
		tmp = check(ps);
	}
	printf("����������=>");
	scanf("%d", &(ps->deda[ps->size].aeg));
	printf("�������Ա�=>");
	scanf("%s", ps->deda[ps->size].sex);
	printf("������绰=>");
	scanf("%s", ps->deda[ps->size].phone);
	printf("������סַ=>");
	scanf("%s", ps->deda[ps->size].address);
	ps->size++;
	system("cls");
	printf("��ӳɹ�\n");
}

void Print(const struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѸ¼Ϊ��\n");
	}
	else
	{
		system("cls");
		printf("%-12s %-5s %-5s %-12s %-10s\n", "����", "����", "�Ա�", "�绰", "סַ");
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			printf("%-12s %-5d %-5s %-12s %-10s\n", ps->deda[i].name,
													ps->deda[i].aeg,
													ps->deda[i].sex,
													ps->deda[i].phone,
													ps->deda[i].address);
		}
	}
}

int check(const struct Newsletter_type* ps)
{
	if (ps->size == 0) return -1;
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->deda[ps->size].name, ps->deda[i].name))
		{
			return i;
		}
	}
	return -1;
}

void Delete(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѸΪ��\n");
		return;
	}

	printf("��������Ҫɾ��������=>");
	scanf("%s", ps->deda[ps->size].name);
	int i=check(ps);
	if (i != -1)
	{
		for (; i < ps->size-1; i++)
		{
			memcpy(&(ps->deda[i]), &(ps->deda[i + 1]), sizeof(ps->deda[0]));
		}
		ps->size--;
		system("cls");
		printf("ɾ���ɹ�\n");
	}
	else
	{
		printf("�Ҳ���\n");
	}
}

void Check(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѸΪ��\n");
		return;
	}

	printf("��������Ҫ���ҵ�����=>");
	scanf("%s", ps->deda[ps->size].name);
	int i = check(ps);
	if (i != -1)
	{
		system("cls");
		printf("%-12s %-5s %-5s %-12s %-10s\n", "����", "����", "�Ա�", "�绰", "סַ");
		printf("%-12s %-5d %-5s %-12s %-10s\n", ps->deda[i].name,
												ps->deda[i].aeg,
												ps->deda[i].sex,
												ps->deda[i].phone,
												ps->deda[i].address);
	}
	else
	{
		printf("�Ҳ�����Ҫ���ҵ�����\n");
	}
}

void Change(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѸΪ��\n");
		return;
	}

	printf("��������Ҫ�޸ĵ�����=>");
	scanf("%s", ps->deda[ps->size].name);
	int i = check(ps);
	if (i != -1)
	{
		printf("���ڴ���������=>");
		scanf("%s", ps->deda[i].name);
		printf("���ڴ���������=>");
		scanf("%d", &(ps->deda[i].aeg));
		printf("���ڴ������Ա�=>");
		scanf("%s", ps->deda[i].sex);
		printf("���ڴ�����绰=>");
		scanf("%s", ps->deda[i].phone);
		printf("���ڴ�����סַ=>");
		scanf("%s", ps->deda[i].address);
		system("cls");
		printf("�޸ĳɹ�\n");
	}
	else
	{
		printf("�Ҳ�����Ҫ���ҵ�����\n");
	}
}

void Sorting(struct Newsletter_type* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѸΪ��\n");
		return;
	}

	int i = 0,j=0;

	for (i = 0; i < ps->size-1; i++)
	{
		int flag = 1;
		for (j = 0; j < ps->size - 1 - i; j++)
		{
			if (ps->deda[j].aeg > ps->deda[j + 1].aeg)
			{
				Newsletter tmp ={0};
				memcpy(&tmp, &(ps->deda[j + 1]), sizeof(ps->deda[0]));
				memcpy(&(ps->deda[j + 1]), &(ps->deda[j]), sizeof(ps->deda[0]));
				memcpy(&(ps->deda[j]), &tmp, sizeof(ps->deda[0]));
				flag = 0;
			}
		}
		if (flag == 1)
		{
			break;
		}
	}
	system("cls");
	printf("����ɹ�\n");
}

void Save(struct Newsletter_type* ps)
{
	FILE* pf = fopen("Newsletter_file.obj", "wb");
	if (pf == NULL)
	{
		printf("Save:%s", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->deda[i]), sizeof(Newsletter), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
