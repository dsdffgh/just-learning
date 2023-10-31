#include <stdio.h>
#include<stdlib.h>
#if 1

struct Node
{
    int data;
    struct Node* next;
};//声明结构体

struct Node* head;//头节点

void headInsert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    //struct Node* temp = new struct Node();
    (*temp).data = x;//temp -> data = x;
    /******************************/
    //temp -> next = NULL;
    //if(head != NULL) temp -> next = head;//插入到第一个节
    //head = temp;
    //上面三行可用下面代替,包含了链表为空的情况
    /**************************** **/
    temp -> next = head;//插入到第一个节点?
    head = temp;
    //return head;//同样需要传参并返回
    
}

void Print()//如果head不是全局变量，则需要传入参数 Print(struct Node* head)
// 那么不需要新建temp，函数中直接用head就行,这个head和主函数里的不一样，只是个临时变量?
{
    struct Node* temp = head;//使用临时变量而不是链表头，否则会失去节点地址
    printf("list is");
    while(temp != NULL)//遍历链表
    {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    /*
    假如是在尾部添加节点，则需要在遍历后用：
    temp->next = last;
    last指向要添加在尾部的节点
    */
    printf("\n");
}

int main()
{
	head = NULL;

    int n,i,x;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&x);
        headInsert(x);
        //head = Insert(head,x);  head不是全局变量的时侯
        //Insert(&head,x);另一种方法是通过引用传递特定的头节点
        //则传入函数的时候要用指向指针的指针 void Insert(struct Node** pointerToHead, int x)
        Print();
    }
}
#endif

#if 0

struct Node
{
    int data;
    struct Node* next;
};//声明结构体

struct Node* headInsert(struct Node* head, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//struct Node* temp = new struct Node();
    (*temp).data = x;//temp -> data = x;
    temp -> next = head;//插入到第一个节?
    head = temp;

    return head;
}

void Print(struct Node* head)
// 那么不需要新建temp，函数中直接用head就行,这个head和主函数里的不一样，只是个临时变??
{
    printf("list is");
    while(head != NULL)//遍历链表
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
	struct Node* head = NULL;

    int n,i,x;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&x);
        head = headInsert(head,x);  //head不是全局变量的时侯
        //Insert(&head,x);另一种方法是通过引用传递特定的头节点
        //则传入函数的时候要用指向指针的指针 void Insert(struct Node** pointerToHead, int x)
        Print(head);
    }
}
#endif

#if 0
//自己试着写还是不会
struct Node
{
    int data;
    struct Node* next;
};

void headInsert(struct Node** pointerTohead,int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = *pointerTohead;
    *pointerTohead = temp;
}

void print(struct Node* head)
{
    printf("list is ");
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    int n,i = 0,x;
    printf("E   nter\n");
    scanf("%d",&n);

    while(i++ <= n)
    {
        scanf("%d",&x);
        headInsert(&head,x);
        print(head);
    }
}

#endif

#if 0

struct Node
{
    int data;
    struct Node* next;
};

void headInsert(struct Node** pointerToHead, int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));//struct Node* temp = new struct Node();

    /******************************/
    //temp -> next = NULL;
    //if(* pointerToHead != NULL) temp -> next = * pointerToHead;//插入到第一个节??
    //* pointerToHead = temp;
    //上面三行可用下面代替,包含了链表为空的情况
    /**************************** **/

    (*temp).data = x;//temp -> data = x;
    temp -> next = * pointerToHead;//插入到第一个节??
    * pointerToHead = temp;

}

void Print(struct Node* head)
// 那么不需要新建temp，函数中直接用head就行,这个head和主函数里的不一样，只是个临时变??
{
    printf("list is ");
    while(head != NULL)//遍历链表
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
	struct Node* head = NULL;

    int n,i,x;
    scanf("%d",&n);
    for(i = 0;i<n;i++)
    {
        scanf("%d",&x);
        headInsert(&head,x);
        Print(head);
    }
}

#endif