#include "AQueue.h"
int Option(AQueue *queue)
{
	int input; /* Logging user input */
	scanf_s("%d",&input);
	if(getchar() != '\n') { /* Prevent illegal input */
		printf("������������������룡\n");
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
					printf("����Ϊ��\n");
				}
				printf("��ǰ���г���Ϊ��%d\n",LengthAQueue(queue));
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//IsEmpty
			case 3: {
				system("cls");
				if(IsEmptyAQueue(queue)) {
					printf("����Ϊ�գ�\n");
				} else {
					printf("���в�Ϊ�գ�\n");
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
					printf("����������\n");
				} else {
					printf("����δ����\n");
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
					printf("����Ϊ��\n");
				}
				if(GetHeadAQueue(queue,&e)) {
					printf("��ǰ��ͷԪ��Ϊ��");
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
					printf("����Ϊ��\n");
				}
				if(DeAQueue(queue)) {
					printf("ɾ���ɹ���\n");
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
					printf("����Ϊ��\n");
				}
				else
				{
				ClearAQueue(queue);
				printf("��ճɹ���\n");
				}
				fflush(stdin);
				system("pause");
				system("cls");
				break;
			}
			//Traverse
			case 8: {
				system("cls");
				printf("��ǰ����Ϊ:\n");
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
				printf("������0-8��\n");
				fflush(stdin);
				system("pause");
				system("cls");
			}
		}
	}
	return 1;
}
