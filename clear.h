#pragma once
#include"struct.h"

//�������
void clearRainLine(drop* p) //�Ժ� or blue��ʾ������ʧ
{
	if (p->startY <= 550)
		setcolor(BLACK);//�������ߵ���ɫ������ɫ��ʾ����ʧ
	else
		setcolor(BLUE);//�������ߵ���ɫ����ɫҲ���Ա�ʾ����ʧ
	//setlinestyle(PS_SOLID, 1);// ���õ�ǰ������ʽ(ʵ�ߣ������1)
	line(p->startX, p->startY, p->curX, p->curY);//��ֱ��
}

//����ˮ��
void clearRainCircle(drop* p) //��blueɫ��ʾˮȦ��ʧ
{
	int x1, x2, y1, y2;
	setcolor(BLUE);//����ͼ����ɫ���ó���ɫ
	x1 = p->water.x - p->water.curR - 5;
	x2 = p->water.x + p->water.curR + 5;
	y1 = p->water.y - p->water.curR + 5;
	y2 = p->water.y + p->water.curR - 5;//������ˮȦ��Բ�Ĳ�������һ��
	ellipse(x1, y1, x2, y2);//����������Բ����ɫ���������ɫ����һ�£���ʾˮȦ��ʧ
}

//ȫ�����
void clearAll() //��ͼ�������ͷſռ�
{
	drop* p, * pf;
	p = head;
	while (p != head)
	{
		pf = p;
		p = p->next;
		free(pf);
	}
	closegraph();
}
