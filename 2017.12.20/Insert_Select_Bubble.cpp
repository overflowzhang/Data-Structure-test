#include <iostream>
using namespace std;

void Insert_Sort(int *a,int n)
{
	int i,j;
	for(i=2;i<=n;++i)
		if(a[i]<a[i-1])
		{
			a[0] = a[i];
			a[i] = a[i-1];
			for(j=i-2;a[0]<a[j];--j)
				a[j+1] = a[j];
			a[j+1] = a[0];
		}
}

void Select_Sort(int *a,int n)
{
	int i,j,k;	
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
		{
			if(a[k]>a[j])
				k = j;
		}
		if(k!=i)
		{
			int tmp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}

	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
}

void MP_Sort(int *a,int n)
{
	int i,j,temp;
	for(int i=1;i<=n;i++)
		for(j=1;j<=n-i+1;j++)
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

	for(i=1;i<=n;i++)
		cout<<a[i]<<" ";
}
int main()
{
	int a[100]={0};
	int n;
	cout<<"输入数的个数："<<endl;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	cout<<"插入排序的结果为："<<endl;
	Insert_Sort(a,n);

	cout<<"选择排序的结果为："<<endl;
	Select_Sort(a,n);

	cout<<"冒泡排序的结果为："<<endl;
	MP_Sort(a,n);
}