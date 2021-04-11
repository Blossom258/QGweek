#include "LQueue.h"
int Option(LQueue *queue)
{
	int input; /* Logging user input */
	scanf_s("%d",&input);
	if(getchar() != '\n') { /* Prevent illegal input */
		printf("你的输入有误，请重新输入！\n");
		fflush(stdin);
		system("pause");
		system("cls");
	} else {
		switch(input) {
				//EnAQueue
			case 1: {
				system("cls");
				CallEnLQueue(queue);
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Length
			case 2: {
				system("cls");
				printf("队列长度为：%d\n",LengthLQueue(queue));
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//IsEmpty
			case 3: {
				system("cls");
				if(IsEmptyLQueue(queue)) {
					printf("队列为空！\n");
				} else {
					printf("队列不为空！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//GetHead
			case 4: {
				void *e;
				system("cls");
				if (IsEmptyLQueue(queue))
				{
					printf("队列为空");
				}
				if(GetHeadLQueue(queue,&e)) {
					printf("队头元素为：");
					pprint = 0;
					LPrint(&e);
					printf("\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Delete
			case 5: {
				system("cls");
				if (IsEmptyLQueue(queue))
				{
					printf("队列为空");
				}
				if(DeLQueue(queue)) {
					printf("删除成功！\n");
					ChangeDataType(queue);
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Clear
			case 6: {
				system("cls");
				if (IsEmptyLQueue(queue))
				{
					printf("队列为空\n");
				}
				else
				{
					ClearLQueue(queue);
					printf("清空成功！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Traverse
			case 7: {
				system("cls");
				if (IsEmptyLQueue(queue))
				{
					printf("队列为空");
				}
				printf("当前队列为:\n");
				TraverseLQueue(queue,LPrint);
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			// exit
			case 0: {
				system("cls");
				DestoryLQueue(queue);
				fflush(stdin);
				system("cls");
				return 0;
			}
			default: {
				printf("请输入0-8之间的数字！\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}
		}
	}
	return 1;
}
