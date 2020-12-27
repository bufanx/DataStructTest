#pragma once

#include"create.h"
#include"clear.h"
#include"update.h"
#include"draw.h"
#include <conio.h>

void rainDropDown(drop* p) //控制雨的路径
{
	if (p->curY >= p->endY)//雨线的末尾到达产生水圈的位置
	{
		clearRainLine(p);//清除雨线
		p->status = 1;//雨线的末尾到达产生水圈的位置
	}
	else
	{
		clearRainLine(p);//清除雨线
		updateRainLineData(p);//更新雨线下落路径
		drawRainLine(p);//画出雨线
		if (m.mkLButton == true && p->curX % 999 == 1)//此处条件在于减少打雷的概率
			thunder(p);
	}
}

void fallToWater(drop* p) //控制雨圈雨点的衔接
{
	if (p->water.curR >= p->water.r)
	{
		clearRainCircle(p);//清除水圈
		recreatDrop(p);
	}
	else
	{
		clearRainCircle(p);
		updateRainCircleData(p);//更新水圈
		drawRainCircle(p);//画出水圈
	}
}

void rain() //控制全程雨的开始到结束
{
	drop* p;
	p = head;
	while (!kbhit())
	{
		if (p->status == 0)
			rainDropDown(p);//清除所有
		else
			fallToWater(p);
		//PlaySound("C:\\rain.wav", NULL, SND_FILENAME | SND_ASYNC); //vc++最简单的声音函数
		p = p->next;
	}
}

//程序开始的入口
void run()
{
	load();
	pond();
	creatRain();
	wuyun();
	rain();
	clearAll();
}