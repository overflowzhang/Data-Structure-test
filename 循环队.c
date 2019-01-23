#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1024
#define datatype int
typedef struct{                                       //循环队列
    datatype data[MAXSIZE];
    int front,rear;
    int num;
}c_SeQueue;

c_SeQueue* Init_SeQueue()
{// 置空队
    c_SeQueue*q=malloc(sizeof(c_SeQueue));
    q->front=q->rear=MAXSIZE-1;
    q->num=0;
    return q;
}

int In_SeQueue(c_SeQueue*q,datatype x)
{//入队
    if(q->front==(q->rear+1)%MAXSIZE)
        return -1;
    else{
        q->rear=(q->rear+1)%MAXSIZE;
        q->data[q->rear] = x;
        return 0;
    }
}

int Out_SeQueue(c_SeQueue*q,datatype *x)
{//出队
    if(q->front==q->rear)
        return -1;
    else
    {
        q->front = (q->front+1)%MAXSIZE;
        * x = q->data[q->front];
        return 0;
    }
}

int Empty_SeQueue(c_SeQueue*q)
{//判断队空
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}


int main()
{
    c_SeQueue * q  = (c_SeQueue*)malloc(sizeof(c_SeQueue));
    return 0;
}
