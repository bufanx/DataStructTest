#pragma once
#include"struct.h"

//生成下一个雨点的位置
void updateRainLineData(drop* p)
{
	if (MouseHit())//如果有鼠标信息就获取，没有就不获取
		//检测当前是否有鼠标消息
		m = GetMouseMsg();//获取一个鼠标消息。如果当前鼠标消息队列中没有，就一直等待。
	p->curY += p->rainLineStep;//Y的增量为rainLineStep
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

//更新水波
void updateRainCircleData(drop* p) //控制水圈的大小
{
	p->water.curR += p->water.rainCircleStep;
}
