#include "LQueue.h"

void CallEnLQueue(LQueue *Q)
{
	int input;
	int i;
	printf("������Ҫ�����Ԫ��������");
	scanf_s("%d",&input);
	if(getchar() != '\n') { /* Prevent illegal input */
		printf("��������������������룡\n");
		fflush(stdin);
		system("pause");
		system("cls");
	} else {
		for(i=0; i<input; i++) {
			printf("��ȷ����%d��Ԫ�ص�Ԫ�����ͣ�",i+1);
			printf("(1. ���� 2. �ַ��� 3. ������ )\n");
			scanf_s("%d",&type);
			if(getchar() != '\n' || (type<1 || type>4)) {
				printf("�����������������룡\n");
				fflush(stdin);
				continue;
			} else {
				printf("�������%d��Ҫ���������:",i+1);
			}
			switch(type) {
				case 1: {
					int data;
					scanf_s("%d", &data);
					if(getchar() != '\n') { /* Prevent illegal input */
						printf("��������������������룡\n");
						fflush(stdin);
						continue;
					} else {
						datatype[Q->length]='i';
						if(EnLQueue(Q, &data)) {
							printf("����ɹ���\n");
						} else {
							printf("����ʧ�ܣ�\n");
						}
						break;
					}
				}
				case 2: {
					char data ;
					scanf_s("%c", &data);
					if(getchar() != '\n') { /* Prevent illegal input */
						printf("��������������������룡\n");
						fflush(stdin);
						continue;
					} else {
						datatype[Q->length]='c';
						if(EnLQueue(Q, &data)) {
							printf("����ɹ���\n");
						} else {
							printf("����ʧ�ܣ�\n");
						}
						break;
					}
				}
				case 3: {
					double data;
					scanf_s("%lf", &data);
					if(getchar() != '\n') { /* Prevent illegal input */
						printf("��������������������룡\n");
						fflush(stdin);
						continue;
					} else {
						datatype[Q->length]='d';
						if(EnLQueue(Q, &data)) {
							printf("����ɹ���\n");
						} else {
							printf("����ʧ�ܣ�\n");
						}
						break;
					}
				}
			
			}
		}
	}
}



