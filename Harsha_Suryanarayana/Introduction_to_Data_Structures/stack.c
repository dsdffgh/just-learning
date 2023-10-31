#include <stdio.h>
#include <stdlib.h>
#if 1
//����ʵ�� ջ �� ����ʵ��ʡ��
struct stack
{
    int data;
    struct stack *link;
};
struct stack *top = NULL;

void Push(int data)
{
    struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
    temp->data = data;
    temp->link = top;
    top = temp;
}

void Pop()
{
    struct stack *temp;
    if (top == NULL)
        return;
    temp = top;
    top = top->link;
    free(temp);
}

void Print(struct stack *head)//_using_recursion
{
    // �ȴ�ӡ�ٵݹ�
    if (head != NULL)
    {
        printf("%d ", head->data);
        Print(head->link);
    }
    else
        printf("\n");
}

int main()
{
    Push(2); // 2
    Push(3); // 3,2
    Push(4); // 4,3,2
    Push(5); // 5,4,3,2
    printf("left is top\n");
    Print(top);
    Pop();
    Print(top);
    Pop();
    Print(top);
}
#endif