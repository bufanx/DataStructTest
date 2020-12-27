#pragma once
#include<graphics.h>
//雨点落下造成的水圈
typedef struct rainCircle
{
	int x;
	int y;
	int r;//雨圈的最大半径
	int curR;//当前半径
	int rainCircleStep; //水圈产生的步骤
}wave;

//雨滴
typedef struct rainDrop
{
	int startX; //雨点开始的X值
	int startY; //雨点开始的Y值
	int endY; //雨点结束的Y值
	int curX; //雨点降落中的X值
	int curY; //雨点降落中的Y值
	COLORREF rainColor; //雨点的颜色
	int rainLineStep; //雨线的顺序
	int rainLineLength; //雨线的长度
	int status;
	wave water;//水圈结构体类型
	struct rainDrop* next;//指向下一个雨滴下落的指针
}drop;

drop* head;
MOUSEMSG m;///鼠标信息
int n = 100; //雨的数目
long msecond1, msecond2;