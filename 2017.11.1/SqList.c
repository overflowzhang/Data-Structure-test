#include <stdio.h>
#include <stdlib.h>

typedef struct{
    //学生信息的定义
    char no[8];        //8位学号
    char name[20];    //姓名
    int price;             //成绩
}Student;

typedef struct{
    //顺序表的定义
    Student * elem;          //指向数据元素的基地址
    int length;                   //线性表的当前长度
}SqList;
//************************************************
void Init_List(SqList *L,int List_Size){
    //建立一个空的顺序表
    L->elem = (Student*)malloc(sizeof(Student)*List_Size);
    if(L->elem)
        L->length = List_Size;
}

//************************************************
void Scanf_List(SqList *L){
    //输入学生信息
    int i;
    char ch;
    for(i=0;i<L->length;i++)
    {
        printf("请输入第%d个学生的信息:\n",i+1);
        scanf("%s",L->elem[i].no);
        scanf("%s",L->elem[i].name);
        scanf("%d",&L->elem[i].price);
        ch = getchar();
    }
}
//************************************************
void Print_List(SqList *L){
    //显示学生信息
    int i;
    printf("学生的信息：\n");
    for( i=0;i<L->length;i++)
    {
        printf("%s  ",L->elem[i].no);
        printf("%s  ",L->elem[i].name);
        printf("%d  \n",L->elem[i].price);
    }
}
//************************************************
void Find_name(SqList *L,char* c){
    //根据姓名进行查找，输出学生的学号和成绩
    int i;
    int a=0;
    for(i=0;i<L->length;i++)
    {
        if(strcmp(L->elem[i].name,c)==0)
        {
            printf("该学生的学号为：%s  \n",L->elem[i].no);
            printf("该学生的成绩为：%d\n",L->elem[i].price);
            ++a;
        }
    }
    if(a==0)
    {
        printf("未找到该学生的信息！\n");
    }
}
//**************************************************
void Find_Persition(SqList *L,int i){
    //根据指定的位置返回相应的学生信息
    printf("第%d个学生的信息为：\n",i);
    printf("%s  ",L->elem[i-1].no);
    printf("%s  ",L->elem[i-1].name);
    printf("%d\n",L->elem[i-1].price);
}
//*************************************************
void Sq_Insert(SqList *L,int m){
    //给定一个学生信息，插入到表中指定位置
    Student T;                    //输入待插入的学生信息
    Student *p,*q;
    char ch;
    if(m<0||m>L->length)
    {
        printf("输入的位置有错！\n");
    }
    scanf("%s",T.no);
    scanf("%s",T.name);
    scanf("%d",&T.price);
    L->elem = (Student*)malloc((L->length+1)*sizeof(Student));
    q = &L->elem[m-1];
    for(p=&L->elem[L->length-1];p>=q;--p)
        *(p+1) = *p;                                       //第m个学生后 都向后移一个位置
    *q = T;
    ++L->length;
}
//**************************************************************
void Sq_Delete(SqList *L,int m){
    //删除指定位置的学生信息
    int i;
    if(m<=0||m>L->length)
        printf("该位置无效！\n");
    else if(m==1)
        L = NULL;
    else
    {
        for(i=m;i<L->length;i++)
        {
            L->elem[i-1] = L->elem[i];
        }
    }
    printf("删除成功！\n");
}
//***************************************
int Sq_Num(SqList *L){
    return L->length;
}

//**************************************
int main()
{
    SqList L;
    int m,n,a;
    char c[20] ;
    char name[20];
    printf("录入信息成功后可进行的操作如下：\n");
    printf("1 -> 逐个显示学生表中所有学生的相关信息\n");
    printf("2 -> 根据姓名进行查找,显示此学生的学号和成绩\n");
    printf("3 -> 根据指定位置查找学生信息\n");
    printf("4 -> 将学生信息插入到指定位置\n");
    printf("5 -> 删除指定位置的学生记录\n");
    printf("6 -> 统计表中当前学生个数\n");
    printf("按 0 结束~\n\n");

    printf("您需要录入几个学生的信息：\n");
    scanf("%d",&n);
    Init_List(&L,n);                                   //初始化顺序表
    Scanf_List(&L);                                //输入学生信息

        while(1)
    {
        printf("请输入您要进行的操作：\n");
        scanf("%d",&m);
        switch(m){
        case 1:
            Print_List(&L);                                              //显示学生信息
            break;
        case 2:
            printf("请输入您要查找的学生姓名：\n");
            scanf("%s",name);
            Find_name(&L,name);                                       //根据姓名查找学生信息
            break;
        case 3:
            printf("您要查找第几个学生的信息：\n");
            scanf("%d",&a);
            Find_Persition(&L,a);                                             //查找指定位置学生信息
            break;
        case 4:
            printf("需要在哪个位置插入学生信息：\n");
            scanf("%d",&a);
            Sq_Insert(&L,a);                                         //在指定位置插入学生信息
            break;
        case 5:
            printf("待删除学生的位置：\n");
            scanf("%d",&a);
            Sq_Delete(&L,a);                                          //删除指定位置学生信息
            break;
        case 6:
            printf("当前表中学生的个数为： %d\n",Sq_Num(&L));
            break;
        case 0:
            exit(0);
        }
    }


    return 0;
}
