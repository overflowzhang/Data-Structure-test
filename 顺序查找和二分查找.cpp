#include <iostream>

using namespace std;

void fun_1(int *a,int n,int value)
{
    int i;
    a[0] = value;
    for( i=n;i>=1;--i)
    {
        if(a[i]==a[0])
            {
                cout<<"在第"<<i<<"个位置找到该数字"<<endl;
                break;
            }
    }
    if(0==i)
        cout<<"未找到该数字！"<<endl;
}

void fun_2(int *a,int n,int value)
{
    int first=1;
    int last=n;
    int mid;
    a[0] = value;
    while(first<=last)
    {
        mid = (first+last)/2;
        if(a[mid]==a[0])
            {
                cout<<"查找成功，位于第"<<mid<<"个数字"<<endl;
                return ;
            }
        else if(a[mid]>a[0])
            last = mid  - 1;
        else
            first = mid + 1;
    }
}
int main()
{
    int a[100];
    int n,m;
    cout<<"请输入数字的个数："<<endl;
    cin>>n;
    cout<<"输入不重复的数字："<<endl;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    cout<<"输入将要查找的数字："<<endl;
    cin>>m;

    cout<<endl<<"用顺序查找的方法："<<endl;
    fun_1(a,n,m);
    cout<<endl<<"用二分查找的方法："<<endl;
    fun_2(a,n,m);

    return 0;
}
