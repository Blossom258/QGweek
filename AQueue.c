#include "AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	int i;
	Q->length = MAXQUEUE;
	for(i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void *)malloc(21);
	}
	Q->front = Q->rear = 0;
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	int i = 0;
 	while (Q->length--)
         free(Q->data[i++]);
	Q->data[0] = NULL;
}



/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(LengthAQueue(Q)==MAXQUEUE-1) {
		return TRUE;
	} else
		return FALSE;
}

/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	return LengthAQueue(Q) == 0 ? TRUE : FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q)) {
	
		return FALSE;
	}
	int typeSize;
	if(datatype[0] == 'i') {
		typeSize = sizeof(int);
	} else if(datatype[0] == 'd') {
		typeSize = sizeof(double);
	} else if(datatype[0] == 'c') {
		typeSize = sizeof(char);
	} else {
		typeSize = sizeof(Q->data[0]);
	}
	memcpy(e,Q->data[0],typeSize);
	return TRUE;
}



/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + Q->length)%Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q)) {
		
		return FALSE;
	}
	memcpy(Q->data[Q->rear], data, 20);
	Q->rear = (Q->rear + 1) % MAXQUEUE;
	Q->length++;
	return TRUE;

}



/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if (IsEmptyAQueue(Q))
     {
       
         return FALSE;
     }
     Q->front = (Q->front+1)%MAXQUEUE;
     Q->length--;
     return TRUE;
}



/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	pri = 0;
	if (IsEmptyAQueue(Q)) {
		
		return FALSE;
	}
	int i = 0;
	
	while (i < (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE) {
		foo(Q->data[Q->front+i]);
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}



/**
 *  @name        : void APrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 *  @notice      : None
 */
void APrint(void *q)
{
	if(datatype[pri] == 'i') {
		printf("%d  ",*(int*)q);
		pri++;
	} else if(datatype[pri] == 'd') {
		printf("%.2f  ",*(double*)q);
		pri++;
	}
	else if (datatype[pri] == 'c') {
		printf("%c  ", *(char*)q);
		pri++;
	}
}

/**
 *  @name        : void menu()
 *	@description : creat a menu
 *	@param		 : none
 *	@return		 : none
 *  @notice      : none
 */
void menu()
{	printf("\n\n                    \n\n");
	printf("                                                20�����11�෽��\n");
	printf_s("                                                 ˳����й��ܲ˵� \n");
	printf_s("                                ---------------------- ---------------------- \n");
	printf_s("                                                0.�˳����ζ��� \n");
	printf_s("                                ********************************************* \n");
	printf_s("                                    * 1.���в���Ԫ�� * * 2.ͳ�ƶ��г��� * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 3.�ж϶���Ϊ�� * * 4.�ж϶���Ϊ�� * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 5.���ض�ͷԪ�� * * 6.ɾ����ͷԪ�� * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 7.��ձ��ζ��� * * 8.��ӡ����Ԫ�� * \n");
	printf_s("                                ********************** ********************** \n");
	printf("\n\n                    \n\n");
	printf("			                       ��ѡ���ܱ��:");
}



void ChangeDataType(AQueue* Q)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= Q->length; i++)
	{
		datatype[j++] = datatype[i];
	}
}
