#include <iostream>

#define LIST_INIT_SIZE   80
#define LISTINCREMENT  10

using namespace std;
//*******************************************
//单向链表
struct Node
{
    int value;
    Node * next;
};
//********************************************

//双向链表
struct DNode
{
    int value ;
    DNode* next;
    DNode* piror;
};
//********************************************

//（单向链表）插入节点
void insertNode(Node *p,int i)
{
    Node *node = new Node;
    node->value = i;
    node->next = p->next;
    p->next = node;
}
//*********************************************

//(单向链表)删除节点
void deleteNode(Node *p)
{
    p->value = p->next->value;
    p->next = p->next->next;
}
//***********************************************

//用栈反向遍历链表
void printLinkedListReversinglyByStack(Node *head){
    stack<Node* > nodesStack;
    Node* pNode = head;
    //遍历链表
    while (pNode != NULL) {
        nodesStack.push(pNode);
        pNode = pNode->next;
    }
    while (!nodesStack.empty()) {
        pNode=nodesStack.top();
        printf("%d\t", pNode->value);
        nodesStack.pop();
    }
}
//***********************************************

//递归反向遍历链表
void printLinkedListReversinglyRecursively(Node *head){
    if (head!=NULL) {
        if (head->next!=NULL) {
            printLinkedListReversinglyRecursively(head->next);
        }
        printf("%d\t", head->value);
    }
}
//***********************************************

//找出中间节点（fast每走两步，slow走一步）
Node* findMidNode(Node* head){
    Node* slow = head;
    Node* fast = head;
    while (fast->next != 0&&fast->next->next!=0) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
//**************************************************

//找出倒数第k个节点65t
Node* findKNode(Node* head,int k){
    Node *temp1 = head;

    Node *temp2 = head;
    while (k-->0) {
        if(temp2 == NULL){
            return NULL;
        }
        temp2 =temp2->next;
	}	
    while (temp2->next != NULL&&temp2->next->next!=NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}
//*******************************************************

//翻转链表
Node * reverseLinkedList(Node* head,int k){
    Node *reversedHead = NULL;
    Node *pNode = head;
    Node *pre = NULL;
    while (pNode!=NULL) {
        if (pNode->next==NULL) {
            reversedHead = pNode;
        }
        Node* nxt = pNode->next;
        pNode->next = pre;
        pre=pNode;
        pNode=nxt;
    }
    return reversedHead;
}
//********************************************************

int main()
{

    return 0;
}
