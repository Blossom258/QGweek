#include "LQueue.h"

void CallEnLQueue(LQueue *Q)
{
	int input;
	int i;
	printf("请输入要插入的元素数量：");
	scanf_s("%d",&input);
	if(getchar() != '\n') { /* Prevent illegal input */
		printf("你的输入有误，请重新输入！\n");
		fflush(stdin);
		system("pause");
		system("cls");
	} else {
		for(i=0; i<input; i++) {
			printf("请确定第%d个元素的元素类型：",i+1);
			printf("(1. 整型 2. 字符型 3. 浮点型 )\n");
			scanf_s("%d",&type);
			if(getchar() != '\n' || (type<1 || type>4)) {
				printf("输入有误，请重新输入！\n");
				fflush(stdin);
				continue;
			} else {
				printf("请输入第%d个要插入的数据:",i+1);
			}
			switch(type) {
				case 1: {
					int data;
					scanf_s("%d", &data);
					if(getchar() != '\n') { /* Prevent illegal input */
						printf("你的输入有误，请重新输入！\n");
						fflush(stdin);
						continue;
					} else {
						datatype[Q->length]='i';
						if(EnLQueue(Q, &data)) {
							printf("插入成功！\n");
						} else {
							printf("插入失败！\n");
						}
						break;
					}
				}
				case 2: {
					char data ;
					scanf_s("%c", &data);
					if(getchar() != '\n') { /* Prevent illegal input */
						printf("你的输入有误，请重新输入！\n");
						fflush(stdin);
						continue;
					} else {
						datatype[Q->length]='c';
						if(EnLQueue(Q, &data)) {
							printf("插入成功！\n");
						} else {
							printf("插入失败！\n");
						}
						break;
					}
				}
				case 3: {
					double data;
					scanf_s("%lf", &data);
					if(getchar() != '\n') { /* Prevent illegal input */
						printf("你的输入有误，请重新输入！\n");
						fflush(stdin);
						continue;
					} else {
						datatype[Q->length]='d';
						if(EnLQueue(Q, &data)) {
							printf("插入成功！\n");
						} else {
							printf("插入失败！\n");
						}
						break;
					}
				}
			
			}
		}
	}
}



