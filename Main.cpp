/*
	IMAGE loading,index;
	loadimage(&loading, _T("loading.png"));  //���ڴ��ļ��ж�ȡͼ��EASYX�Դ�
	loadimage(&index, _T("index.jpg"));  //���ڴ��ļ��ж�ȡͼ��EASYX�Դ�
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