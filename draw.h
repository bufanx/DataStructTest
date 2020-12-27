#pragma once

#include<Windows.h>
#include<mmsystem.h>
#include"struct.h"
#include<conio.h>
#pragma comment(lib, "winmm.lib")

//画雨线
void drawRainLine(drop* p)
{
	setlinestyle(PS_SOLID, 1);//设置当前画线样式(实线，宽度是1)
	setcolor(p->rainColor);//设置雨线的颜色，实现彩色雨
	line(p->startX, p->startY, p->curX, p->curY);//画直线
}

//画闪电并播放雷声
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
	PlaySound(TEXT("thunder.wav"), NULL, SND_FILENAME | SND_ASYNC); //vc++最简单的声音函数
}

//画雨降落后的水圈
void drawRainCircle(drop* p)
{
	int x1, x2, y1, y2;
	setcolor(p->rainColor);//画雨的颜色
	x1 = p->water.x - p->water.curR - 5;
	x2 = p->water.x + p->water.curR + 5;
	y1 = p->water.y - p->water.curR + 5;
	y2 = p->water.y + p->water.curR - 5;//确定雨滴下落后水圈椭圆的各个参数
	ellipse(x1, y1, x2, y2); //画椭圆
}

//画乌云
void wuyun()
{
	setlinecolor(DARKGRAY); //定义画线颜色
	setfillcolor(DARKGRAY); //设置填充颜色
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

//画池塘
void pond()
{
	setlinecolor(BLUE);
	line(0, 680, 1000, 680);
	setfillstyle(0, NULL, NULL);
	setfillcolor(BLUE);
	bar(0, 550, 1000, 680);
}

//加载背景
void load()
{
	IMAGE loading, index;
	loadimage(&loading, _T("loading.png"));  //用于从文件中读取图像，EASYX自带
	int width = loading.getwidth();
	int height = loading.getheight();
	initgraph(width, height);
	putimage(0, 0, &loading);
	FlushBatchDraw();
	_getch();
	initgraph(1000, 680);
}