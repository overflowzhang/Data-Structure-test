#include <iostream>
using namespace std;

typedef struct treenode{
	int key;
	struct treenode *lchild;
	struct treenode *rchild;
}treenode,*Tree;

bool Insert_Node(Tree &p,int value)
{
	if(!p)
	{
		p = new treenode;  //new 相当于 malloc  +  构造函数
		p->key = value;
		p->lchild = p->rchild = NULL;
		return true;
	}

	if(value == p->key)
		return false;
	if(value < p->key)
		return Insert_Node(p->lchild,value);
	if(value > p->key)
		return Insert_Node(p->rchild,value);
}

void Creat_Tree(Tree &p_tree,int *a,int n)
{
	p_tree = NULL;
	for(int i=0;i<n;i++)
		Insert_Node(p_tree,a[i]);
	cout<<"二叉排序树建立完成！"<<endl;
}
void PreOrder(Tree p)
{
	if(p)
	{
	    //cout<<"*";
		cout<<p->key<<" ";
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
	//cout<<"*";
}

void InOrder(Tree p)
{
	if(p)
	{
	    //cout<<"*";
		InOrder(p->lchild);
		cout<<p->key<<" ";
		InOrder(p->rchild);
	}
	//cout<<"*";
}

int main()
{
	int a[100];
	int n;
	Tree p_tree=NULL;
	cout<<"输入数字的个数："<<endl;
	cin>>n;
	cout<<"依次输入数字："<<endl;
	for(int i=0;i<n;i++)
		cin>>a[i];
	Creat_Tree(p_tree,a,n);
	cout<<endl<<"先序遍历二叉树："<<endl;
	PreOrder(p_tree);
	cout<<endl;
	cout<<endl<<"中序遍历二叉树："<<endl;
	InOrder(p_tree);
	cout<<endl;
}
