#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//#define MAX 100
#define CURREMT 3//��ʼ������

typedef struct Newsletter
{
	char name[12];//����
	int aeg;//����
	char sex[5];//�Ա�
	char phone[12];//�绰
	char address[10];//סַ
}Newsletter;

typedef struct Newsletter_type
{
	struct Newsletter* deda;
	int current;//��ǰ����
	int size;//�±�λ��
}Newsletter_type;

//��������
void Initialize(struct Newsletter_type* ps);//��ʼ��
int increase(struct Newsletter_type* ps);//����
void ADD(struct Newsletter_type* ps);//���
void Print(const struct Newsletter_type* ps);//��ʾ
void Delete(struct Newsletter_type* ps);//ɾ��
void Check(struct Newsletter_type* ps);//����
void Change(struct Newsletter_type* ps);//�޸�
void Sorting(struct Newsletter_type* ps);//����
void Save(struct Newsletter_type* ps);//����
void Load(struct Newsletter_type* ps);//����

int check(const struct Newsletter_type* ps);//�������֣��ҵ�������ͬ���±꣬�Ҳ�������-1