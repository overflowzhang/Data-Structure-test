#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char no[8];
    char name[20];
    int price;
}Student;

typedef struct LNode{
    Student data;
    struct LNode *next;
}LNode,*LinkList;
//**************************************************
LinkList Init_List(int num){
    LNode* p;
    LNode* q;
    LNode* head = (LNode*)malloc(sizeof(LNode));
    head -> next = NULL;
    printf("链表创建成功，待输入学生信息：\n");
    q = head;
    if(!head)
        printf("链表建立失败！");
    while(num--)
    {//为链表添加节点的同时录入学生的信息
        p = (LNode*)malloc(sizeof(LNode));
        p->next = NULL;

        scanf("%s",p->data.no);
        scanf("%s",p->data.name);
        scanf("%d",&p->data.price);

        q->next = p;
        q = q->next;
        p = NULL;
    }
    return head;
}
//*******************************************
void Print_List(LinkList head){
    LNode* p;
    p = head->next;
    while(p)
    {
        printf("%s\t",p->data.no);
        printf("%s\t",p->data.name);
        printf("%d\t",p->data.price);
        printf("\n");
        p = p->next;
    }
}
//*********************************************
void Find_Name(LinkList head,char* s){
    LNode*p;
    int a=0;
    p = head->next;
    while(p)
    {
        if(strcmp(p->data.name,s)==0)
        {
            printf("学号：%s\n",p->data.no);
            printf("成绩：%d\n",p->data.price);
            ++a;
        }
        p = p->next;
    }
    if(!a)
        printf("未找到该学生的信息！\n");
}
//*********************************************
void Find_Area(LinkList head,int position){
    LNode* p;
    int a=0;
    p = head->next;
    while(p)
    {
        ++a;
        if(a==position)
        {
            printf("%s\t",p->data.no);
            printf("%s\t",p->data.name);
            printf("%d\n",p->data.price);
            break;
        }
        else
            p = p->next;
    }
}
//********************************************
void Insert_Node(LinkList head,int position){
    int a=0;
    LNode* p;
    LNode* q = (LNode*)malloc(sizeof(LNode));
    q->next = NULL;
    printf("请输入待插入的学生信息：\n");
    scanf("%s",q->data.no);
    scanf("%s",q->data.name);
    scanf("%d",&q->data.price);
    p = head->next;
    if(position==1)                   //判断是否插入到首节点的位置
    {
        head->next = q;
        q->next = p;
    }
    else
    {
        while(p)
        {
            ++a;
            if((a+1)==position)
            {
                q->next = p->next;
                p->next = q;
                printf("信息插入成功！\n");
                break;
            }
            else
                p = p->next;
    }
    }
}
//*********************************************
void Delete_Node(LinkList head,int position){
    LNode* p,*q;
    int a = 0;
    p = head->next;
    if(position==1)                               //判断是否插入到首节点的位置
    {
        head->next = p->next;
        free(p);
        printf("该记录删除成功！\n");
    }
    else
    {
        p = p->next;   //当前p指定首节点的下一个
        while(p)
        {
            ++a;
            if((a+1)==position)
            {
                q = p;
                p->next = p->next->next;
                free(q);
                printf("该记录删除成功！\n");
            }
            else
                p = p->next;
        }
    }

}
//*********************************************
int Num_Link(LinkList head){
    LNode*p;
    int num= 0;
    p = head->next;
    while(p)
    {
        ++num;
        p = p->next;
    }
    return num;
}
//**********************************************
int main()
{
    int num,a,m;
    char name[20];
    LinkList head;
    printf("录入信息成功后可进行的操作如下：\n");
    printf("1 -> 逐个显示学生表中所有学生的相关信息\n");
    printf("2 -> 根据姓名进行查找,显示此学生的学号和成绩\n");
    printf("3 -> 根据指定位置查找学生信息\n");
    printf("4 -> 将学生信息插入到指定位置\n");
    printf("5 -> 删除指定位置的学生记录\n");
    printf("6 -> 统计表中当前学生个数\n");
    printf("按 0 结束~\n\n");

    printf("您需要录入几个学生的信息：\n");
    scanf("%d",&num);
    head = Init_List(num);                                    //创建有num个节点的链表

    while(1)
    {
        printf("请输入您要进行的操作：\n");
        scanf("%d",&m);
        switch(m){
        case 1:
            Print_List(head);                                              //显示学生信息
            break;
        case 2:
            printf("请输入您要查找的学生姓名：\n");
            scanf("%s",name);
            Find_Name(head,name);                                       //根据姓名查找学生信息
            break;
        case 3:
            printf("您要查找第几个学生的信息：\n");
            scanf("%d",&a);
            Find_Area(head,a);                                             //查找指定位置学生信息
            break;
        case 4:
            printf("需要在哪个位置插入学生信息：\n");
            scanf("%d",&a);
            Insert_Node(head,a);                                         //在指定位置插入学生信息
            break;
        case 5:
            printf("待删除学生的位置：\n");
            scanf("%d",&a);
            Delete_Node(head,a);                                          //删除指定位置学生信息
            break;
        case 6:
            printf("当前表中学生的个数为： %d\n",Num_Link(head));
            break;
        case 0:
            exit(0);
        }
    }

    return 0;
}
