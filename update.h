#pragma once
#include"struct.h"

//������һ������λ��
void updateRainLineData(drop* p)
{
	if (MouseHit())//����������Ϣ�ͻ�ȡ��û�оͲ���ȡ
		//��⵱ǰ�Ƿ��������Ϣ
		m = GetMouseMsg();//��ȡһ�������Ϣ�������ǰ�����Ϣ������û�У���һֱ�ȴ���
	p->curY += p->rainLineStep;//Y������ΪrainLineStep
	if (m.y < 200)
		p->curY -= p->rainLineStep / 2;
	if (m.y > 450)
		p->curY += p->rainLineStep;
	p->startY = p->curY - p->rainLineLength;
	//
	if (m.x < 300)
	{
		p->curX -= p->rainLineStep;
		p->startX = p->curX + p->rainLineLength;
	}
	if (m.x > 600)
	{
		p->curX += p->rainLineStep;
		p->startX = p->curX - p->rainLineLength;
	}
}

//����ˮ��
void updateRainCircleData(drop* p) //����ˮȦ�Ĵ�С
{
	p->water.curR += p->water.rainCircleStep;
}
