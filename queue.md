## 顺序队列及链式队列的函数实现（泛型队列）

### 顺序队列：

#### 给出的结构体以及基本数据

```c
#define MAXQUEUE 10


typedef struct Aqueue
{
    void *data[MAXQUEUE];      //数据域
    int front;
    int rear;
   int length;        //队列长度
} AQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;
char datatype[MAXQUEUE];
int pri; 
```

#### 初始化队列

```c
void InitAQueue(AQueue *Q)
{
	int i;
	Q->length = MAXQUEUE;
	for(i = 0; i < MAXQUEUE; i++) {
		Q->data[i] = (void *)malloc(20); //不知道什么数据类型，就给他20个字节空间吧
	}
	Q->front = Q->rear = 0;
}

```

#### 销毁队列

```c
void DestoryAQueue(AQueue *Q)
{
	int i = 0;
 	while (Q->length--)
         free(Q->data[i++]);
	Q->data[0] = NULL;
}
```

#### 判断队列是否为满

```c
Status IsFullAQueue(const AQueue *Q)
{
	if(LengthAQueue(Q)==MAXQUEUE-1) {
		return TRUE;
	} else
		return FALSE;
}
```

#### 判断队列是否为空

```c
Status IsEmptyAQueue(const AQueue *Q)
{
	return LengthAQueue(Q) == 0 ? TRUE : FALSE;
}

```

#### 返回队列头元素

```c
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
```

#### 队列长度

```c
int LengthAQueue(AQueue *Q)
{
	return (Q->rear - Q->front + Q->length)%Q->length;
}
```

#### 入队

```
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
```

#### 出队

```c
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
```

#### 清空队列

```c
void ClearAQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
}
```

#### 遍历以及打印队列元素

```c
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

```

#### 泛型打印

```c
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
```

#### 删除元素后讲打印类型向前推一位

```c
void ChangeDataType(AQueue* Q)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= Q->length; i++)
	{
		datatype[j++] = datatype[i];
	}
}
```

### 链式队列：

#### 给出的结构体以及基本数据

```c
typedef struct node
{
    void *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;  //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
char datatype[30];			
int pri;
```

#### 初始化队列

```c
void InitLQueue(LQueue *Q)
{
	Node* head = (Node*)malloc(sizeof(Node));
	Q->front = Q->rear = head;
	Q->front->next = NULL;
	Q->length = 0;
}

```

#### 销毁队列

```c
void DestoryLQueue(LQueue *Q)
{
	Node* p;
	for(p=Q->front;p;p = Q->front ) {
		Q->front = Q->front->next;
		free(p);
	}
}		
```

#### 判断队列是否为空

```c
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->rear == Q->front)
		return TRUE;
	else
		return FALSE;
}
```

#### 返回队列头元素

```C
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
```

#### 队列长度

```c
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}
```

#### 入队

```c
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
```

#### 出队

```c
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
```

#### 清空队列

```c
void ClearLQueue(LQueue *Q)
{
	Node* p;
	for(p=Q->front->next;p;p = p->next ) {
		free(p);
		Q->length--;
	}
	Q->rear = Q->front;
}
```

#### 遍历以及打印队列元素

```C
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
```

#### 泛型打印

```C
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
```

