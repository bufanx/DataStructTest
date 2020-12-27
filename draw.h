#pragma once

#include<Windows.h>
#include<mmsystem.h>
#include"struct.h"
#include<conio.h>
#pragma comment(lib, "winmm.lib")

//������
void drawRainLine(drop* p)
{
	setlinestyle(PS_SOLID, 1);//���õ�ǰ������ʽ(ʵ�ߣ������1)
	setcolor(p->rainColor);//�������ߵ���ɫ��ʵ�ֲ�ɫ��
	line(p->startX, p->startY, p->curX, p->curY);//��ֱ��
}

//�����粢��������
void thunder(drop* p)
{
	int x, y;
	x = (rand() % 800) + 100;
	y = (rand() % 200) + 200;
	setfillcolor(WHITE);
	bar(0, 250, 1000, 550);
	Sleep(1);
	setfillcolor(BLACK);
	bar(0, 250, 1000, 550);
	POINT pts[] = { {x - 30,y},{x,y},{x,y - 70},{x + 30,y},{x,y},{x,y + 70} };
	setfillcolor(WHITE);
	solidpolygon(pts, 6);
	Sleep(1);
	setfillcolor(BLACK);
	solidpolygon(pts, 6);
	PlaySound(TEXT("thunder.wav"), NULL, SND_FILENAME | SND_ASYNC); //vc++��򵥵���������
}

//���꽵����ˮȦ
void drawRainCircle(drop* p)
{
	int x1, x2, y1, y2;
	setcolor(p->rainColor);//�������ɫ
	x1 = p->water.x - p->water.curR - 5;
	x2 = p->water.x + p->water.curR + 5;
	y1 = p->water.y - p->water.curR + 5;
	y2 = p->water.y + p->water.curR - 5;//ȷ����������ˮȦ��Բ�ĸ�������
	ellipse(x1, y1, x2, y2); //����Բ
}

//������
void wuyun()
{
	setlinecolor(DARKGRAY); //���廭����ɫ
	setfillcolor(DARKGRAY); //���������ɫ
	fillellipse(20, 20, 200, 100);
	fillcircle(50, 60, 40);
	fillcircle(90, 70, 40);
	fillcircle(140, 70, 40);
	fillcircle(90, 35, 30);
	fillcircle(140, 40, 30);
	fillcircle(185, 60, 35);
	fillellipse(270, 20, 450, 100);
	fillcircle(300, 60, 40);
	fillcircle(340, 70, 40);
	fillcircle(390, 70, 40);
	fillcircle(340, 35, 30);
	fillcircle(390, 40, 30);
	fillcircle(435, 60, 35);
	fillellipse(520, 20, 700, 100);
	fillcircle(550, 60, 40);
	fillcircle(590, 70, 40);
	fillcircle(640, 70, 40);
	fillcircle(590, 35, 30);
	fillcircle(640, 40, 30);
	fillcircle(685, 60, 35);
	fillellipse(770, 20, 950, 100);
	fillcircle(800, 60, 40);
	fillcircle(840, 70, 40);
	fillcircle(890, 70, 40);
	fillcircle(840, 35, 30);
	fillcircle(890, 40, 30);
	fillcircle(935, 60, 35);
}

//������
void pond()
{
	setlinecolor(BLUE);
	line(0, 680, 1000, 680);
	setfillstyle(0, NULL, NULL);
	setfillcolor(BLUE);
	bar(0, 550, 1000, 680);
}

//���ر���
void load()
{
	IMAGE loading, index;
	loadimage(&loading, _T("loading.png"));  //���ڴ��ļ��ж�ȡͼ��EASYX�Դ�
	int width = loading.getwidth();
	int height = loading.getheight();
	initgraph(width, height);
	putimage(0, 0, &loading);
	FlushBatchDraw();
	_getch();
	initgraph(1000, 680);
}