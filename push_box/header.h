#pragma once
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define	NUMBER	10	//���ٹ�
#define	LINE	10	//��
#define COLUMN	10	//��

enum en
{
	cle,	//�յ�
	wall,	//ǽ
	tar,	//Ŀ��
	box,	//����
	fig		//����
};

//��������
void Print(const int(*ps)[NUMBER][LINE][COLUMN],int sum);//��ӡ��ͼ
int Operation(int(*ps)[NUMBER][LINE][COLUMN]);//ִ����Ϸ����
//����-1��������0�˳���Ϸ������1ͨ�سɹ�
int check(int(*ps)[NUMBER][LINE][COLUMN],int sum);//�����û������
int Location(const int(*ps)[NUMBER][LINE][COLUMN], int sum,int* x,int* y);//�ҵ���������