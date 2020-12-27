#pragma once
#include"struct.h"

//消除雨滴
void clearRainLine(drop* p) //以黑 or blue表示雨线消失
{
	if (p->startY <= 550)
		setcolor(BLACK);//设置雨线的颜色，用蓝色表示雨消失
	else
		setcolor(BLUE);//设置雨线的颜色，黑色也可以表示雨消失
	//setlinestyle(PS_SOLID, 1);// 设置当前画线样式(实线，宽度是1)
	line(p->startX, p->startY, p->curX, p->curY);//画直线
}

//消除水波
void clearRainCircle(drop* p) //以blue色表示水圈消失
{
	int x1, x2, y1, y2;
	setcolor(BLUE);//将绘图背景色设置成蓝色
	x1 = p->water.x - p->water.curR - 5;
	x2 = p->water.x + p->water.curR + 5;
	y1 = p->water.y - p->water.curR + 5;
	y2 = p->water.y + p->water.curR - 5;//和生成水圈椭圆的参数保持一致
	ellipse(x1, y1, x2, y2);//将画出的椭圆的颜色与池塘的颜色保持一致，表示水圈消失
}

//全部清除
void clearAll() //画图结束，释放空间
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
