#pragma once

#include"struct.h"

drop* creatDrop(void)//��������һ��ָ��rainDrop���͵Ľṹ��
{
	drop* p;//����ṹ������
	p = (drop*)malloc(sizeof(drop));//��̬�����ڴ�
	p->startY = 120;//���������ʼYλ�ø���ֵ
	p->startX = rand() % 1000; //rand()�����ǲ����������һ�����������������#include<stdlib.h>ͷ�ļ���
	p->startY = p->startY + rand() % 630;
	p->endY = 590 + rand() % 50;//������λ�ø�ֵ
	p->curX = p->startX;//��㽵�������ΪX��ֵ
	p->curY = p->startY;//��㽵�������ΪY��ֵ
	p->rainLineStep = 8;//����˳�򸳳�ֵ
	p->rainLineLength = 10;//���߳��ȸ���ֵ
	p->status = 0;
	p->rainColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	//RGB(red, green, blue)
	//red 0 �� 255 ���������������ɫ�еĺ�ɫ�ɷ֡�
	//green 0 �� 255 ���������������ɫ�е���ɫ�ɷ֡�
	//blue 0 �� 255 ���������������ɫ�е���ɫ�ɷ֡�
	p->water.x = p->startX;//ˮȦ��ʼ��X����ε�X
	p->water.y = p->endY;//ˮȦ��Y����ν�����Y
	p->water.r = rand() % 30;//ˮȦ�����뾶���ȷ��
	p->water.curR = rand() % 2;
	p->water.rainCircleStep = rand() % 2 + 1;
	p->next = NULL;
	return(p);
}
void recreatDrop(drop* p)
{
	p->startY = 120;
	p->startX = rand() % 1000;
	p->startY = p->startY + rand() % 630;
	p->endY = 590 + rand() % 50;
	p->curX = p->startX;
	p->curY = p->startY;
	p->rainLineStep = 8;
	p->rainLineLength = 10;
	p->status = 0;
	p->rainColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	p->water.x = p->startX;
	p->water.y = p->endY;
	p->water.r = rand() % 30;
	p->water.curR = rand() % 2;
	p->water.rainCircleStep = rand() % 2 + 1;
}
void creatRain(void) //��������
{//��������ѭ�����������������
	drop* p1, * p2;//��������ָ��rainDrop���͵Ľṹ��ָ��
	int i;
	p1 = p2 = creatDrop();
	head = p1;
	for (i = 0; i < n; i++)
	{
		p2 = creatDrop();
		p1->next = p2;
		p1 = p2;
	}
	p1->next = head;
}