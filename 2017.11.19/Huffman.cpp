#include <iostream>
#include <malloc.h>
using namespace std;

#define N 27               //带权值的叶子节点数或是需要编码的字符数
#define M 2*N-1           //n个叶子节点构造的哈夫曼树有2n-1个节点
#define MAX 1000

typedef struct{
	unsigned int weight;    //权重
	unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;             //动态分配数组存储哈夫曼树
typedef char* *HuffmanCode;       //动态分配数组存储哈夫曼编码表


void Select(HuffmanTree HT,int n,int &s1,int &s2)
{
	s1 = 1;
	s2 = 1;
	for(int i=1;i<=n;i++)
	{
		if(HT[i].weight<HT[s1].weight)
			s1 = i; //找到最小权重对英国的序号
	}

	HT[s1].weight = 100;  //  为了找出第二小的权重
	for(int i=1;i<=n;i++)
	{
		if(HT[i].weight<HT[s2].weight)
			s2 = i;//找到第二小权重对应的序号
	}
}

void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,double *w,int n){
	//w存放n个字符的权值（均>0），构造哈弗曼树HT，并求出n个字符的哈夫曼编码HC
	int i,m;
	HuffmanTree p;
	m = 2*n -1;
	HT = (HuffmanTree)malloc((m+1)*sizeof(HTNode));   //0号单元未用
	for(p = HT,i=1;i<=n;++i,++p,++w)
		*p = {0,*w,0,0};
	for(;i<=m;++i,++p)
		*p = {0,0,0,0};                              //两个for循环初始化哈夫曼编码表

	for(i=n+1;i<=m;++i){//建立哈夫曼树
		//在HT[1...i-1]选择parent为0且weight最小的两个结点，其序号分别为s1,s2
		int s1,s2;

		Select(HT,i-1,s1,s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}

    char *cd;
    int start;
	//---从叶子到根逆向求每个字符的哈夫曼编码---
	HC = (HuffmanCode)malloc((n+1)*sizeof(char*));  //分配n个字符编码的头指针向量
	cd = (char*)malloc(n*sizeof(char));             //分配求编码的工作空间
	cd[n-1] = "\0";                                 //编码结束符
	for(i=1;i<=n;++i){                              //逐个字符求哈夫曼编码
		start = n-1;                                //编码结束符位置
		for(int c=i,int f=HT[i].parent;f!=0;c=f,f=HT[f].parent)  //从叶子到根逆向求编码
			if(HT[f].lchild==c)
				cd[--start] = "0";
			else
				cd[--start] = "1";
			HC[i] = (char*)malloc((n-start)*sizeof(char));  //为第i个字符编码分配空间
			strcpy(HC[i],&cd[start]);                       //从cd复制编码（串）到HC
	}
	free(cd);
}//HuffmanCoding




int main()
{

	char fi[10240];
	char letter[50]={'*','a','b','c','d','e','f','g','h','i',
	                'j','k','l','m','n','o','p','q','r','s',
	                't','u','v','w','x','y','z',' '};
	double weight[50];       //各个字符的频率
	int num[50]={0,0,0,0,0,0,0,0,0,0,0,0,
				 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};                //统计各个字符出现的次数
	char c;
	int count=0;
	ofstream ofile;
	ifstream   ifile;

	HuffmanCode HC;
	HuffmanTree HT;

	ofile.open("SourceFile.txt");
	while(1)
	{
		c = ofile.get();

		for(int i=1;i<28;i++)
		{
			if(c==letter[i])
				num[i] += 1;
		}

		if(c==EOF)
			break;
		fi[count++] = c;
	}


	for(int i=1;i<28;i++)
	{
		weight[i] = (double)(num[i]/count)
	}

	HuffmanCoding(HT,HC,weight,27);

	return 0;

}
