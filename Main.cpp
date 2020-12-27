/*
	IMAGE loading,index;
	loadimage(&loading, _T("loading.png"));  //用于从文件中读取图像，EASYX自带
	loadimage(&index, _T("index.jpg"));  //用于从文件中读取图像，EASYX自带
	int width = loading.getwidth();
	int height = loading.getheight();
	initgraph(width, height);
	putimage(0, 0, &loading);
	FlushBatchDraw();
	Sleep(5000);
	putimage(0, 0, &index);
	FlushBatchDraw();
	_getch();*/

#define true 1

#include"control.h"

int main()
{
	run();
	return 0;
}