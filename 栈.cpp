#include <iostream>
using namespace std;
class MyStack
    {
       public:
        MyStack(int size);      //分配内存初始化栈空间，设定栈容量，栈顶
       ~MyStack();                            //回收栈空间内存
       bool stackEmpty();                //判断栈是否为空
       bool stackFull();                      //判断栈是否为满
       void clearStack();                    //清空栈
       int stackLength();                   //已有元素的个数
       bool push(char elem);            //元素入栈，栈顶上升
       bool pop(char &elem);            //元素出栈，栈顶下降
       void stackTraverse();               //遍历栈中所有元素

       private:
       char*m_pBuffer;         //栈空间指针
       int m_iSize;                                 //栈容量
       int m_iTop;                                 //栈顶，栈中元素个数
    };

    MyStack::MyStack(int size)              //分配内存初始化栈空间，设定栈容量，栈顶
  {
        m_iSize = size;
        m_pBuffer=new char[size];
        m_iTop = 0;
  }

  MyStack::~MyStack()                             //回收栈空间内存
  {
        delete []m_pBuffer;
  }

    bool MyStack:: stackEmpty()             //判断栈是否为空
    {
        if(0==m_iTop)
            return true;
        else
            return false;
    }

    bool MyStack:: stackFull()                   //判断栈是否为满
    {
        if(m_iTop>=m_iSize)
            return true;
        else
            return false;
    }

    void MyStack:: clearStack()                    //清空栈
    {
        m_iTop = 0;
    }

    int MyStack:: stackLength()                   //已有元素的个数
    {
        return m_iTop;
    }

    bool MyStack:: push(char elem)            //元素入栈，栈顶上升
    {
        if(stackFull())
        {
           return false;
        }
            m_pBuffer[m_iTop] = elem;
            m_iTop++;
            return true;
    }

    bool MyStack:: pop(char &elem)           //元素出栈，栈顶下降
    {
        if(!stackFull())
            return false;
        m_iTop--;
        elem = m_pBuffer[m_iTop];
        return true;
    }

    void MyStack::stackTraverse()              //遍历栈中所有元素
    {
        cout<<"正序输出："<<endl;
        for(int i =0;i<m_iTop;i++)
            cout<<m_pBuffer[i]<<" ";
            cout<<endl;
            cout<<"倒序输出："<<endl;
        for(int i=m_iTop-1;i>=0;i--)
            cout<<m_pBuffer[i]<<" ";
    }

int main()
{
    MyStack *p_Stack = new MyStack(5);

    p_Stack->push('x');
    p_Stack->push('y');
    p_Stack->push('z');


    p_Stack->stackTraverse();

    char elem ;
    p_Stack->pop(elem);
    cout<<elem<<endl;
    p_Stack->clearStack();

    if(p_Stack->stackEmpty())
        cout<<"Stack is Empty!"<<endl;
    else
        cout<<"Stack is not Empty!"<<endl;
        cout<<p_Stack->stackLength()<<endl;


    delete p_Stack;
    p_Stack = NULL;

    return 0;
}
