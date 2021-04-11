#include "AQueue.h"
#include<Windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	AQueue queue;	/* Define a stack */
	InitAQueue(&queue);
	printf("已为您初始化队列，即将进入操作页面！");
	Sleep(0);
	system("cls");
	do {
		menu();
	} while(Option(&queue));
	return 0;
}
