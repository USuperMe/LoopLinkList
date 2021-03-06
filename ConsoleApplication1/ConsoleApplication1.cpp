// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace  std;
//创建循环链表
struct  Node
{
    int data;
    Node *next;
}*head, *LinkList;

Node *CreateLoopLinkList(int n) {
    Node *p;
    Node *tail;//尾指针
    LinkList = new Node;
    LinkList->next = NULL;
    head = LinkList;

    for (auto i = 0; i < n; i++) {
        p = new Node;
        p->data = i;
        LinkList->next = p;
        LinkList = p;
    }
    tail = LinkList;
    tail->next = head->next;
    //返回链表的尾指针
    return tail;
}
//遍历链表
void ForeachLinkList(Node *tail, bool isLoopLinkList = false)
{
    if (isLoopLinkList)
    {
        Node *p = tail->next;
        while (p->next != head->next)
        {
            cout << p->data << endl;
            p = p->next;
        }
        return;
    }
    // 循环链表的遍历方式,循环输出链表的元素，用于检测循环链表是否创建成功
    while (head->next)
    {
        std::cout << head->next->data << "  ";
        head = head->next;
    }
}
int main()
{
     ForeachLinkList(CreateLoopLinkList(10));
    //ForeachLinkList(CreateLoopLinkList(10), true);
    return 0;
}

