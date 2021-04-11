#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node* head = (Node*)malloc(sizeof(Node));
	Q->front = Q->rear = head;
	Q->front->next = NULL;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node* p;
	for(p=Q->front;p;p = Q->front ) {
		Q->front = Q->front->next;
		free(p);
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if (IsEmptyLQueue(Q)) {
		
		return FALSE;
	}
	unsigned int typeSize;
	if(datatype[0] == 'i') {
		typeSize = sizeof(int);
	} else if(datatype[0] == 'd') {
		typeSize = sizeof(double);
	} else if(datatype[0] == 'c') {
		typeSize = sizeof(char);
	} else {
		typeSize = sizeof(Q->front->next->data);
	}
	memcpy(e,Q->front->next->data,typeSize);
	return TRUE;
}
/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue *Q, void *data)
{
	Node *p = (Node*)malloc(sizeof(Node));
	if(!p){ 
		
		return FALSE;
	}
	p->data = (void*)malloc(21);
	memcpy(p->data, data, 20);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;	
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	Node* p;
	if(IsEmptyLQueue(Q)){
	
		return FALSE;
	}
	p = Q->front->next;
	Q->front->next = p->next;
	
	if(Q->rear == p){
		Q->rear = Q->front;
	}
	free(p);
	Q->length--;
	return TRUE;
}

void ChangeDataType(LQueue *Q){
	int i;
	int j=0;
	for(i=1;i<=Q->length;i++){
		datatype[j++]=datatype[i];
	}
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node* p;
	for(p=Q->front->next;p;p = p->next ) {
		free(p);
		Q->length--;
	}
	Q->rear = Q->front;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	pprint = 0;
	Node* p; 
	if (IsEmptyLQueue(Q)) {
		
		return FALSE;
	}
	int i = 0;
	
	for(p=Q->front->next;p;p = p->next){
		foo(p->data);
	}
	printf("\n");
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q

 *  @notice      : None
 */
void LPrint(void *q)
{
	if(datatype[pprint] == 'i') {
		printf("%d  ",*(int*)q);
		pprint++;
	} else if(datatype[pprint] == 'd') {
		printf("%.2f  ",*(double*)q);
		pprint++;
	} else if(datatype[pprint] == 'c') {
		printf("%c  ",*(char*)q);
		pprint++;
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
{
	printf("\n\n                    \n\n");
	printf("                                                 20�����11�෽��\n");
	printf_s("                                                 ��ʽ���й��ܲ˵� \n");
	printf_s("                                ---------------------- ---------------------- \n");
	printf_s("                                ********************************************* \n");
	printf_s("                                    * 1.���в���Ԫ�� * * 2.ͳ�ƶ��г��� * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 3.�ж϶���Ϊ�� * * 4.���ض�ͷԪ�� * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 5.ɾ����ͷԪ�� * * 6.��ձ��ζ��� * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 7.��ӡ����Ԫ�� * * 0.�˳����ζ��� * \n");
	printf_s("                                ********************** ********************** \n");
	printf("\n\n                    \n\n");
	printf("			                       ��ѡ���ܱ��:");
}
