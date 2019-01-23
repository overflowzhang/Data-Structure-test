#include <iostream>
#include <string.h>
using namespace std;

typedef struct node{
    string name;
    struct node *next;
}QNode;                            //链队节点的类型

class LQueue
{
public:
    QNode *front;
    QNode *rear;
    int Length = 0;

    LQueue();
    void In_LQueue(string s);
    void Out_LQueue(string &s);
    int Get_Length();
};
//***********************************************
LQueue::LQueue()
{
    front = rear = NULL;         //建立一个不含头结点的队列
}

//**********************************************
void LQueue::In_LQueue(string s)
{
    QNode *p =  new QNode();
    p->name = s;
    p->next = NULL;
    Length++;
    if(Length==1)
        front = rear = p;
    else
        {
            rear->next = p;
            rear = p;
            rear->next = NULL;
        }
    cout<<"入队成功！"<<endl<<endl;
}
//*********************************************
void LQueue::Out_LQueue(string &s)
{
    s = front->name;
    front = front->next;
    cout<<s<<"成功出队！"<<endl<<endl;
    Length--;
}
//********************************************

int LQueue::Get_Length()
{
    return Length;
}
int main()
{
    int m,n,e,i=0;
    string s;
    char ch;
    LQueue   *p1_lqueue = new LQueue();
    LQueue   *p2_lqueue = new LQueue();
    cout<<"每支舞跳完后，接着进行下一段舞，按N退出~"<<endl<<endl;
    while(1)
    {
        i++;
        cout<<"第"<<i<<"支舞即将开始, 请做好准备！"<<endl;

        cout<<"输入男队列中的舞者数："<<endl;
        cin>>m;
        cout<<"逐个输入舞者的名字(换行符隔开)："<<endl;
        for(int i =0;i<m;i++)
        {
            cin>>s;
            p1_lqueue->In_LQueue(s);               //舞者逐个进入男队
        }
        cout<<"输入女队列中的舞者数："<<endl;
        cin>>n;
        cout<<"逐个输入舞者的名字(换行符隔开):"<<endl;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            p2_lqueue->In_LQueue(s);            //舞者逐个进入女队
        }

        if(m>n)
            e = n;
        else
            e = m;                                          //e为较短队列中的舞者数

        cout<<"现在进入配对阶段->"<<endl;
        for(int i=0;i<e;i++)
        {
            string s1,s2;
            p1_lqueue->Out_LQueue(s1);
            p2_lqueue->Out_LQueue(s2);
            cout<<s1<<"和"<<s2<<"配对成功！"<<endl<<endl;
        }

        if(m==n)
            cout<<"男女舞伴配对完毕！ 无剩余舞者！"<<endl<<endl;
        else if(m>n)
            {
                cout<<"当前队中剩余人数："<<p1_lqueue->Get_Length()<<endl;
                cout<<"剩余男队中在队首的舞者为："<<p1_lqueue->front->name<<endl;
            }
        else
            {
                cout<<"当前队中剩余人数："<<p2_lqueue->Get_Length()<<endl;
                cout<<"剩余女队中在队首的舞者为："<<p2_lqueue->front->name<<endl;
            }

        cout<<"是否接着跳下一支 Y/N："<<endl;
        cin>>ch;
        if('Y'==ch||'y'==ch)
            continue;
        else
            return 0;
    }
    return 0;
}


