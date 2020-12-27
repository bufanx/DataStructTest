#pragma once

#include"create.h"
#include"clear.h"
#include"update.h"
#include"draw.h"
#include <conio.h>

void rainDropDown(drop* p) //�������·��
{
	if (p->curY >= p->endY)//���ߵ�ĩβ�������ˮȦ��λ��
	{
		clearRainLine(p);//�������
		p->status = 1;//���ߵ�ĩβ�������ˮȦ��λ��
	}
	else
	{
		clearRainLine(p);//�������
		updateRainLineData(p);//������������·��
		drawRainLine(p);//��������
		if (m.mkLButton == true && p->curX % 999 == 1)//�˴��������ڼ��ٴ��׵ĸ���
			thunder(p);
	}
}

void fallToWater(drop* p) //������Ȧ�����ν�
{
	if (p->water.curR >= p->water.r)
	{
		clearRainCircle(p);//���ˮȦ
		recreatDrop(p);
	}
	else
	{
		clearRainCircle(p);
		updateRainCircleData(p);//����ˮȦ
		drawRainCircle(p);//����ˮȦ
	}
}

void rain() //����ȫ����Ŀ�ʼ������
{
	drop* p;
	p = head;
	while (!kbhit())
	{
		if (p->status == 0)
			rainDropDown(p);//�������
		else
			fallToWater(p);
		//PlaySound("C:\\rain.wav", NULL, SND_FILENAME | SND_ASYNC); //vc++��򵥵���������
		p = p->next;
	}
}

//����ʼ�����
void run()
{
	load();
	pond();
	creatRain();
	wuyun();
	rain();
	clearAll();
}