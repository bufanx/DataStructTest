#pragma once

#include"struct.h"

drop* creatDrop(void)//函数返回一个指向rainDrop类型的结构体
{
	drop* p;//定义结构体类型
	p = (drop*)malloc(sizeof(drop));//动态分配内存
	p->startY = 120;//雨点下落起始Y位置赋初值
	p->startX = rand() % 1000; //rand()函数是产生随机数的一个随机函数，包涵在#include<stdlib.h>头文件中
	p->startY = p->startY + rand() % 630;
	p->endY = 590 + rand() % 50;//雨点结束位置赋值
	p->curX = p->startX;//雨点降落过程中为X赋值
	p->curY = p->startY;//雨点降落过程中为Y赋值
	p->rainLineStep = 8;//雨线顺序赋初值
	p->rainLineLength = 10;//雨线长度赋初值
	p->status = 0;
	p->rainColor = RGB(rand() % 256, rand() % 256, rand() % 256);
	//RGB(red, green, blue)
	//red 0 到 255 间的整数，代表颜色中的红色成分。
	//green 0 到 255 间的整数，代表颜色中的绿色成分。
	//blue 0 到 255 间的整数，代表颜色中的蓝色成分。
	p->water.x = p->startX;//水圈开始的X是雨滴的X
	p->water.y = p->endY;//水圈的Y是雨滴结束的Y
	p->water.r = rand() % 30;//水圈的最大半径随机确定
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
void creatRain(void) //创建链表
{//创建的是循环链表，不断生成雨滴
	drop* p1, * p2;//定义两个指向rainDrop类型的结构体指针
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