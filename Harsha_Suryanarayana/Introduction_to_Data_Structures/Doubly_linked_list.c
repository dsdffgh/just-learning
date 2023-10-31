#include <stdio.h>
#include <stdlib.h>
#if 1

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *head;

struct Node *GetNewNode(int x)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void headInsert(int data)
{
    struct Node *newNode = GetNewNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void tailInsert(int data)
{
    struct Node *newNode = GetNewNode(data);
    struct Node *temp = head;
    while (temp->next != NULL) // 遍历链表
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void Print()
{
    struct Node *temp = head; // 使用临时变量而不是链表头，否则会失去节点地址
    printf("list is ");
    while (temp != NULL) // 遍历链表
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL;
    headInsert(2);
    headInsert(3);
    headInsert(9);
    tailInsert(6);
    tailInsert(8);
    tailInsert(11);
    Print();
}

#endif