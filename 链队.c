#include <stdio.h>
#include <stdlib.h>
#define datatype int
typedef struct node
{
    datatype data;
    struct node* next;
}QNode;                                     //链队结点的类型

typedef struct
{
    QNode *front,*rear;
}LQueue;



LQueue* Init_LQueue()
{   //创建一个带头结点的空队
    LQueue *q;
    QNode* p;
    q = malloc(sizeof(LQueue));     //申请头尾指针节点
    p = malloc(sizeof(QNode));      //申请链队节点
    p->next=NULL;
    q->front = q->rear = p;
    return q;
}

void In_LQueue(LQueue*q,datatype x)
{//入队
    QNode*p;
    p = malloc(sizeof(QNode));
    p->data = x;
    p->next = NULL;
    q->rear->next = p;                          
    q->rear = p;                                     
}

int Empty_LQueue(LQueue*q)
{//判队空
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

int Out_LQueue(LQueue*q,datatype*x)
{
    QNode *p;
    if(Empty_LQueue(q))
    {
        printf("队空！");
        return 0;
    }
    else
    {
        p = q->front->next;        
        q->front->next = p->next;
        *x = p->data;
        free(p);
        if(q->front->next==NULL)
            q->rear = q->front;
                                     //只有一个元素时，出队后队空，此时还要修改队尾指针
        return 1;
    }
}

int main()
{
    LQueue * q =(LQueue*) malloc(siziof(LQueue));
    return 0;
}
