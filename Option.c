#include "AQueue.h"
int Option(AQueue *queue)
{
	int input; /* Logging user input */
	scanf_s("%d",&input);
	if(getchar() != '\n') { /* Prevent illegal input */
		printf("你的输入有误，请检查输入！\n");
		fflush(stdin);
		system("pause");
		system("cls");
	} else {
		switch(input) {
				//EnAQueue
			case 1: {
				system("cls");
				CallEnQueue(queue);
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Length
			case 2: {
				system("cls");
				if (IsEmptyAQueue(queue))
				{
					printf("队列为空\n");
				}
				printf("当前队列长度为：%d\n",LengthAQueue(queue));
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//IsEmpty
			case 3: {
				system("cls");
				if(IsEmptyAQueue(queue)) {
					printf("队列为空！\n");
				} else {
					printf("队列不为空！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//IsFull
			case 4: {
				system("cls");
			
				if(IsFullAQueue(queue)) {
					printf("队列已满！\n");
				} else {
					printf("队列未满！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//GetHead
			case 5: {
				void *e;
				system("cls");
				if (IsEmptyAQueue(queue))
				{
					printf("队列为空\n");
				}
				if(GetHeadAQueue(queue,&e)) {
					printf("当前队头元素为：");
					pri = 0;
					APrint(&e);
					printf("\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Delete
			case 6: {
				system("cls");
				if (IsEmptyAQueue(queue))
				{
					printf("队列为空\n");
				}
				if(DeAQueue(queue)) {
					printf("删除成功！\n");
					ChangeDataType(queue);
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Clear
			case 7: {
				system("cls");
				if (IsEmptyAQueue(queue))
				{
					printf("队列为空\n");
				}
				else
				{
				ClearAQueue(queue);
				printf("清空成功！\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Traverse
			case 8: {
				system("cls");
				printf("当前队列为:\n");
				TraverseAQueue(queue,APrint);
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			// exit
			case 0: {
				system("cls");
				DestoryAQueue(queue);
				fflush(stdin);
				system("cls");
				return 0;
			}
			default: {
				printf("请输入0-8！\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}
		}
	}
	return 1;
}
