#include "LQueue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
{
	LQueue Queue;	/* Define a stack */
	InitLQueue(&Queue);
	system("cls");
	do {
		menu();
	} while(Option(&Queue));
	return 0;
}
