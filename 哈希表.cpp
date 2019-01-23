#include <stdio.h>
#include <stdlib.h>

//链表节点
typedef struct _Link_Node
{
    unisigned short id;
    unisigned short data;
    struct _Link_Node *next;
}Link_Node,*Link_Node_Ptr;

//哈希表头
typedef struct _Hash_Header
{
    struct _Link_Node *next;
}Hash_Header,*Hash_Header_Ptr;
//哈希表
Hash_Header_Ptr Hash_Table[100];
unsigned char hash_func(unisigned short id)
{
    unsigned char pos = 0;

    pos = id % 100;

    return pos;
}
Link_Node_Ptr init_link_node(void)
{
    Link_Node_Ptr node;

    //申请节点
    node = (Link_Node_Ptr) malloc(sizeof(Link_Node));
    //初始化长度为0
    node->next = NULL;

    return node;
}
Hash_Header_Ptr init_hash_header_node(void)
{
    Hash_Header_Ptr node;

    //申请节点
    node = (Hash_Header_Ptr) malloc(sizeof(Hash_Header));
    //初始化长度为0
    node->next = NULL;

    return node;
}
void init_hash_table(void)
{
    unsigned char i = 0;

    for (i = 0;i < 100;i++)
    {
        Hash_Table[i] = init_hash_header_node();
        Hash_Table[i]->next = NULL;
    }
}
void append_link_node(Link_Node_Ptr new_node)
{
    Link_Node_Ptr node;
    unsigned char pos = 0;

    //新节点下一个指向为空
    new_node->next = NULL;

    //用哈希函数获得位置
    pos = hash_func(new_node->id);

    //判断是否为空链表
    if (Hash_Table[pos]->next == NULL)
    {
        //空链表
        Hash_Table[pos]->next = new_node;
    }
    else
    {
        //不是空链表
        //获取根节点
        node = Hash_Table[pos]->next;

        //遍历
        while (node->next != NULL)
        {
            node = node->next;
        }

        //插入
        node->next = new_node;
    }
}
Link_Node_Ptr search_link_node(unisigned short id,unsigned char *root)
{
    Link_Node_Ptr node;
    unsigned char pos = 0;

    //用哈希函数获得位置
    pos = hash_func(id);

    //获取根节点
    node = Hash_Table[pos]->next;

    //判断单链表是否存在
    if (node == NULL)
    {
        return 0;
    }

    //判断是否是根节点
    if (node->id == id)
    {
        //是根节点
        *root = 1;
        return node;
    }
    else
    {
        //不是根节点
        *root = 0;
        //遍历
        while (node->next != NULL)
        {
            if (node->next->id == id)
            {
                return node;
            }
            else
            {
                node = node->next;
            }
        }

        return 0;
    }
}
void delete_link_node(Link_Node_Ptr node)
{
    Link_Node_Ptr delete_node;

    //重定向需要删除的前一个节点
    delete_node = node->next;
    node->next = delete_node->next;

    //删除节点
    free(delete_node);
    delete_node = NULL;
}
void delete_link_root_node(Link_Node_Ptr node)
{
    unsigned char pos = 0;

    //用哈希函数获得位置
    pos = hash_func(node->id);

    //哈希表头清空
    if (node != NULL)
    {
        Hash_Table[pos]->next = node->next;
        //删除节点
        free(node);
        node = NULL;
    }
}
unisigned short get_node_num(void)
{
    Link_Node_Ptr node;
    unisigned short i = 0;
    unisigned short num = 0;

    //遍历
    for (i = 0;i < 100;i++)
    {
        //获取根节点
        node = Hash_Table[i]->next;
        //遍历
        while (node != NULL)
        {
            num++;
            node = node->next;
        }
    }
    return num;
}
Link_Node_Ptr get_node_from_index(unisigned short index,unsigned char *root)
{
    Link_Node_Ptr node;
    unisigned short i = 0;
    unisigned short num = 0;

    //遍历
    for (i = 0;i < 100;i++)
    {
        //获取根节点
        node = Hash_Table[i]->next;
        //判断单链表是否存在
        if (node == NULL)
        {
            continue;
        }

        //根节点
        num++;
        if (num == index)
        {
            //是根节点
            *root = 1;
            return node;
        }

        //遍历
        while (node->next != NULL)
        {
            num++;
            if (num == index)
            {
                //不是根节点
                *root = 0;
                return node;
            }
            node = node->next;
        }
    }

    return 0;
}
void drop_hash()
{
    Link_Node_Ptr node;
    unisigned short i = 0;
    Link_Node_Ptr node_next;

    //遍历
    for (i = 0;i < 100;i++)
    {
        //获取根节点
        node = Hash_Table[i]->next;

        while (1)
        {
            //判断单链表是否存在
            if (node == NULL)
            {
                //不存在
                Hash_Table[i]->next = NULL;
                break;
            }

            //根节点下一个节点
            node_next = node->next;
            //删除根节点
            free(node);
            //重指定根节点
            node = node_next;
        }
    }
}
void printf_hash()
{
    Link_Node_Ptr node;
    unsigned char root = 0;
    unsigned char i = 0;
    unsigned char num = 0;

    printf("-------------打印hash表-------------\n");

    num = get_node_num();
    for (i = 1;i <= num;i++)
    {
        node = get_node_from_index(i,&root);
        if (node != 0)
        {
            if (root)
            {
                printf("根节点:节点号%d,id为%d\n",i,node->id);
            }
            else
            {
                printf("普通节点:节点号%d,id为%d\n",i,node->next->id);
            }
        }
    }
}
int main()
{
    Link_Node_Ptr node;
    unsigned char temp = 0;
    unsigned char root = 0;
    unsigned char i = 0;

    init_hash_table();

    //插入数据id = 1,data = 2;
    node = init_link_node();
    node->id = 1;
    node->data = 2;
    append_link_node(node);

    //查询节点数
    printf("1节点数为%d\n",get_node_num());

    node = init_link_node();
    node->id = 100;
    node->data = 101;
    append_link_node(node);

    node = init_link_node();
    node->id = 1002;
    node->data = 1001;
    append_link_node(node);

    node = init_link_node();
    node->id = 10000;
    node->data = 10001;
    append_link_node(node);

    node = init_link_node();
    node->id = 1000;
    node->data = 10001;
    append_link_node(node);

    node = init_link_node();
    node->id = 2;
    node->data = 10001;
    append_link_node(node);

    //查询节点数
    printf("2节点数为%d\n",get_node_num());

    //查询id = 1000;
    node = search_link_node(100,&temp);
    if (node != 0)
    {
        if (temp == 0)
        {
            printf("删除普通节点:所需查询id的值为%d,数据为%d\n",node->next->id,node->next->data);

            //删除
            delete_link_node(node);
        }
        else
        {
            //根节点
            printf("删除根节点所需查询id的值为%d,数据为%d\n",node->id,node->data);

            //删除
            delete_link_root_node(node);
        }
    }
    else
    {
        printf("查询失败\n");
    }
    //查询id = 1000;
    node = search_link_node(1001,&temp);
    if (node != 0)
    {
        if (temp == 0)
        {
            printf("所需查询id的值为%d\n",node->next->data);
        }
        else
        {
            //根节点
            printf("所需查询id的值为%d\n",node->data);
        }
    }
    else
    {
        printf("查询失败\n");
    }
    //查询节点数
    printf("节点数为%d\n",get_node_num());
    printf_hash();
    getchar();
    return 0;
}
