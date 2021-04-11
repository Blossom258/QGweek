#include "LQueue.h"

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
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
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
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
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q

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
	printf("                                                 20计算机11班方铭\n");
	printf_s("                                                 链式队列功能菜单 \n");
	printf_s("                                ---------------------- ---------------------- \n");
	printf_s("                                ********************************************* \n");
	printf_s("                                    * 1.队列插入元素 * * 2.统计队列长度 * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 3.判断队列为空 * * 4.返回队头元素 * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 5.删除队头元素 * * 6.清空本次队列 * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 7.打印队列元素 * * 0.退出本次队列 * \n");
	printf_s("                                ********************** ********************** \n");
	printf("\n\n                    \n\n");
	printf("			                       请选择功能编号:");
}
