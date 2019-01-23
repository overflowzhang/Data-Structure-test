#include <iostream>
#define Stack_Size 50
using namespace std;

 class MyStack
 {
     private:
         int *base;
         int *top;
        int m_length;
     public:
         MyStack(int size);
         bool Is_Empty();
         bool Is_Full();
         void Clear_Stack();
         void Push(int elem);
         void Pop(int &elem);
         int Stack_Length();
 };

     MyStack::MyStack(int size)              //分配内存初始化栈空间，设定栈容量，栈顶
  {
        int *base = new int[size];
        top = base;
        m_length = 0;
  }


    bool MyStack:: Is_Empty()             //判断栈是否为空
    {
        if(base==top)
            return true;
        else
            return false;
    }

    bool MyStack:: Is_Full()                   //判断栈是否为满
    {
        if(m_length==Stack_Size)
            return true;
        else
            return false;
    }

    void MyStack:: Clear_Stack()                    //清空栈
    {
        top = base;
    }

    int MyStack:: Stack_Length()                   //已有元素的个数
    {
        return m_length;
    }

    void MyStack:: Push(int elem)            //元素入栈，栈顶上升
    {
        *top = elem;
        top++;
    }

    void MyStack:: Pop(int &elem)           //元素出栈，栈顶下降
    {
        top--;
        elem = *top;
    }

int main()
{
    int m,n,elem=0;
    MyStack *p_Stack = new MyStack(Stack_Size);
    cout<<"您要将十进制数转换成几进制数："<<endl;
    cin>>m;
    cout<<"请输入一个十进制数："<<endl;
    cin>>n;

    while(n!=0)
    {//将余数压入栈中
        p_Stack->Push(n%m);
        n = n/m;
        cout<<"11111111111"<<endl;
        cout<<n<<endl;
    }

    cout<<"转换成"<<m<<"进制后的数:"<<endl;
    cout<<"2222222222"<<endl;
    while(!(p_Stack->Is_Empty()))
    {//将栈中所有元素弹出
        p_Stack->Pop(elem);
        //cout<<"333333333333"<<endl;
        cout<<elem<<endl;
        /*switch (elem)
        {
        case 10:
            cout<<'A';
        case 11:
            cout<<'B';
        case 12:
            cout<<'C';
        case 13:
            cout<<'D';
        case 14:
            cout<<'E';
        case 15:
            cout<<'F';
        default:
            cout<<elem;
        }*/

    }
    return 0;
}
