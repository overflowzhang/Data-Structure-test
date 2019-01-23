#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define LIST_INIT_SIZE        80                        //线性表存储空间的初始分配量
#define LISTINCREMENT     10                          //线性表存储空间的分配增量
typedef int ElemType;                                      //顺序表中存放的是整数
typedef struct
{
    ElemType *elem;                                  //存储空间基址
    int length;                                             //当前长度
    int listsize;                                                // 当前分配的存储容量
}SqList;           //顺序表


void InitList(SqList &L){
    //建立一个空的顺序表
    L.elem = (ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(L.elem){
        L.length = 0;
        L.listsize = LIST_INIT_SIZE;
    }
}

void CreateSqList(SqList &L,int m){
     //初始条件：顺序表已存在
    //操作结果：将m个元素依次加入顺序表L
    int i;
    for(i=0;i<m;i++){
        scanf("%d",&L.elem[i]);
        L.length++;
        if(L.length>=L.listsize){
            L.elem = (ElemType*)realloc(L.elem,(L.length+LISTINCREMENT)*sizeof(ElemType));
            L.listsize+=LISTINCREMENT;
        }
    }
}

void ListInsert(SqList &L,int i,ElemType e){
    // 初始条件：顺序表L已存在，1<=i<=ListLength(L)+1
    // 操作结果：在顺序表L中第i个位置之前插入新的数据元素e，表长加1
    ElemType *q,*p;
    if(i<1||i>L.length+1)
        exit(-2);
    if(L.length>=L.listsize){
        L.elem = (ElemType*)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
        L.listsize+=LISTINCREMENT;
    }
    q = &L.elem[i-1];
    for(p=&(L.elem[L.length-1]);p>=q;--p)
        *(p+1) = *p;
    *q = e;
    ++L.length;
}

void ListDelete(SqList &L,int i,ElemType &e){
	// 初始条件：顺序表L已存在，1<=i<=ListLength(L)
	// 操作结果：删除顺序表L的第i个数据元素，并用e返回其值
	ElemType* p;
	if(i<1||i>L.length)
        exit(-2);
    e = L.elem[i-1];
    for(p=&L.elem[i-1];p<=&L.elem[L.length-1];p++)
        *(p-1) = *p;
    --L.length;
}

void PrintList(SqList  L){
    // 初始条件：顺序表L已存在
	// 操作结果：打印顺序表
    int i;
    for(i=0;i<L.length;i++)
        cout<<L.elem[i]<<" ";
}

int Locate(SqList L,ElemType e){
	// 初始条件：顺序表L已存在
	// 操作结果：若顺序表L中存在数据元素e，则返回e在顺序表L中第一次出现的位序;否则返回0
	int i,result = 0;
	for(i=0;i<L.length;i++){
        if(e==L.elem[i]){
            result =  i+1;
            break;
        }
	}
	return result;
}

int ListLength(SqList L){
	// 初始条件：顺序表L已存在
	// 操作结果：返回顺序表L的表长
	return L.length;
}




int main()
{
    SqList L;
    int n;
    int i;
    ElemType e;
    InitList(L);
    cout<<"请输入表长："<<endl;
    cin>>n;
    cout<<"请输入元素（空格分隔）："<<endl;
    CreateSqList(L,n);
    cout<<"顺序表为："<<endl;
   PrintList(L);
    cout<<endl;

    cout<<"顺序表的内容为："<<endl;
    PrintList(L);
    cout<<"输入插入位置和元素（空格分隔）："<<endl;
    cin>>i>>e;
    ListInsert(L,i,e);
    cout<<"顺序表为："<<endl;
    PrintList(L);
    cout<<endl;
    cout<<"输入删除位置："<<endl;
    cin>>i;
    ListDelete(L,i,e);
    cout<<"删除元素为："+e<<endl;
    cout<<"输入待查找的元素："<<endl;
    cin>>e;
    cout<<"查找结果为："+Locate(L,e)<<endl;
    cout<<"顺序表表长："+ListLength(L)<<endl;
    cout<<"按任意键结束……"<<endl;
    char ch = getchar();
    return 0;
}




