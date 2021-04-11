#include "AQueue.h"

/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
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
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
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
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
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
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	return LengthAQueue(Q) == 0 ? TRUE : FALSE;
}



/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
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
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + Q->length)%Q->length;
}



/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
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
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
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
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}



/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
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
 *    @description : 操作函数
 *    @param         q 指针q
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
	printf("                                                20计算机11班方铭\n");
	printf_s("                                                 顺序队列功能菜单 \n");
	printf_s("                                ---------------------- ---------------------- \n");
	printf_s("                                                0.退出本次队列 \n");
	printf_s("                                ********************************************* \n");
	printf_s("                                    * 1.队列插入元素 * * 2.统计队列长度 * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 3.判断队列为空 * * 4.判断队列为满 * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 5.返回队头元素 * * 6.删除队头元素 * \n");
	printf_s("                                ********************** ********************** \n");
	printf_s("                                    * 7.清空本次队列 * * 8.打印队列元素 * \n");
	printf_s("                                ********************** ********************** \n");
	printf("\n\n                    \n\n");
	printf("			                       请选择功能编号:");
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
