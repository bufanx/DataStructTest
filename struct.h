#pragma once
#include<graphics.h>
//���������ɵ�ˮȦ
typedef struct rainCircle
{
	int x;
	int y;
	int r;//��Ȧ�����뾶
	int curR;//��ǰ�뾶
	int rainCircleStep; //ˮȦ�����Ĳ���
}wave;

//���
typedef struct rainDrop
{
	int startX; //��㿪ʼ��Xֵ
	int startY; //��㿪ʼ��Yֵ
	int endY; //��������Yֵ
	int curX; //��㽵���е�Xֵ
	int curY; //��㽵���е�Yֵ
	COLORREF rainColor; //������ɫ
	int rainLineStep; //���ߵ�˳��
	int rainLineLength; //���ߵĳ���
	int status;
	wave water;//ˮȦ�ṹ������
	struct rainDrop* next;//ָ����һ����������ָ��
}drop;

drop* head;
MOUSEMSG m;///�����Ϣ
int n = 100; //�����Ŀ
long msecond1, msecond2;