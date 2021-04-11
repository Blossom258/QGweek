#include "LQueue.h"
int Option(LQueue *queue)
{
	int input; /* Logging user input */
	scanf_s("%d",&input);
	if(getchar() != '\n') { /* Prevent illegal input */
		printf("��������������������룡\n");
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
				printf("���г���Ϊ��%d\n",LengthLQueue(queue));
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//IsEmpty
			case 3: {
				system("cls");
				if(IsEmptyLQueue(queue)) {
					printf("����Ϊ�գ�\n");
				} else {
					printf("���в�Ϊ�գ�\n");
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
					printf("����Ϊ��");
				}
				if(GetHeadLQueue(queue,&e)) {
					printf("��ͷԪ��Ϊ��");
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
					printf("����Ϊ��");
				}
				if(DeLQueue(queue)) {
					printf("ɾ���ɹ���\n");
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
					printf("����Ϊ��\n");
				}
				else
				{
					ClearLQueue(queue);
					printf("��ճɹ���\n");
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
					printf("����Ϊ��");
				}
				printf("��ǰ����Ϊ:\n");
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
				printf("������0-8֮������֣�\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}
		}
	}
	return 1;
}
