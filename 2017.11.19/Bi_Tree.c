#include <stdio.h>
#include <malloc.h>

#define ERROR 0
#define OK    1
#define FALSE 0
#define TRUE  1

typedef struct treenode
{
	char data;
	struct treenode *lchild;
	struct treenode *rchild;
}treenode,*Tree;

int Init_Tree(treenode *node){
	node = NULL;
	return OK;
}

void Creat_Tree(Tree* tree){//����������������ָ�룩
	char data;
	char ch;
	printf("������ڵ��ֵ������Ϊ�ַ���\n");
	scanf("%c",&data);
	ch = getchar();      //���ջس�
	if('0'==data)
		*tree = NULL;
	else
	{
		*tree = (treenode*)malloc(sizeof(treenode));
		if(*tree)
		{
			(*tree)->data = data;
			Creat_Tree(&((*tree)->lchild));
			Creat_Tree(&((*tree)->rchild));
		}

	}
}

void All_Path(treenode *tree,char path[],int pathLength)//�������Ҷ�ӽڵ㵽���ڵ��·��
{
    int i;
	if(tree)
	{
		if(tree->lchild==NULL&&tree->rchild==NULL)
		{
			path[pathLength] = tree->data;
			printf("%c�ڵ㵽���ڵ��·����\n",tree->data);
			for(i = pathLength;i>=0;i--)
			{
				printf("%c ",tree->data);
			}
			printf("\n");
		}
		else
		{
			path[pathLength++] = tree->data;
			All_Path(tree->lchild,path,pathLength+1);
			All_Path(tree->rchild,path,pathLength+1);
		}
	}
}



int Tree_Depth(treenode *tree){//�����������
	int i=0;
	int j=0;
	if(tree)
	{
		if(tree->lchild)
			i = Tree_Depth(tree->lchild);
		if(tree->rchild)
			j = Tree_Depth(tree->rchild);
		return i>j ? i+1 : j+1;
	}
	else
		return 0;
}

int Leaf_Node_count(treenode *tree)
{
    int count;
    if(!tree)
        count=0;
    if((tree->lchild==NULL)&&(tree->rchild==NULL))
        return 1;
    else
        return Leaf_Node_count(tree->lchild) + Leaf_Node_count(tree->rchild);
}

int Node_count(treenode *tree)
{
    if(!tree)
        return 0;
    else
        return 1 + Node_count(tree->lchild) + Node_count(tree->rchild);
}

void Leaf_Load(treenode *tree)
{
    if(!tree)
        return;
    if((tree->lchild==NULL)&&(tree->rchild==NULL))
        printf(" %c",tree->data);
    printf(" %c",tree->data);
}

void Preorder(treenode *tree){//ǰ�����������
	if(tree)
	{
		printf("%c ",tree->data);
		Preorder(tree->lchild);
		Preorder(tree->rchild);
	}

}

void Inorder(treenode *tree){//�������������
	if(tree)
	{
		Inorder(tree->lchild);
		printf("%c ",tree->data);
		Inorder(tree->rchild);
	}
}

void Postorder(treenode *tree){//�������������
	if(tree)
	{
		Postorder(tree->lchild);
		Postorder(tree->rchild);
		printf("%c ",tree->data);
	}

}


int main()
{
    char path[100];
    int pathLength=0;
	Tree p_tree;
	Init_Tree(p_tree);
	printf("�սڵ��� '0' ��ʾ~\n");

	Creat_Tree(&p_tree);
	printf("���������Ϊ�� %d\n\n",Tree_Depth(p_tree));

	printf("�ڵ�ĸ���Ϊ��%d\n\n",Node_count(p_tree));

	printf("Ҷ�ӽڵ�ĸ���Ϊ:   %d\n\n",Leaf_Node_count(p_tree));

	printf("����Ϊ1�Ľڵ������%d\n\n",Leaf_Node_count(p_tree));


	printf("\n");

	printf("ǰ�������������\n");
	Preorder(p_tree);
	printf("\n\n");

	printf("���������������\n");

	Inorder(p_tree);
	printf("\n\n");

	printf("���������������\n");
	Postorder(p_tree);
	printf("\n\n");

    printf("Ҷ�ӽڵ㵽���ڵ��·����\n");
    All_Path(p_tree,path,pathLength);
    printf("\n");

	return 0;
}
