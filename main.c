#include "AQueue.h"
#include<Windows.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	AQueue queue;	/* Define a stack */
	InitAQueue(&queue);
	printf("��Ϊ����ʼ�����У������������ҳ�棡");
	Sleep(0);
	system("cls");
	do {
		menu();
	} while(Option(&queue));
	return 0;
}
