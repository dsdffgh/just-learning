#include <iostream>
#include <string.h>
#include "stdio.h"
#include <stack> //创建栈的库函数
using namespace std;

/*class Stack
{
private:
    char A[101];
    int top;
public:
    void Push(int x);
    void Pop();
    int Top();
    bool IsEmpty();
};
用类创建一个栈
*/

#if 1
// reverse string by stack

void Reverse(char *C, int n)
{
    stack<char> S;
    // loop for push
    for (int i = 0; i < n; i++)
    {
        S.push(C[i]);
    }
    // loop for pop
    for (int i = 0; i < n; i++)
    {
        C[i] = S.top();
        S.pop();
    }
}

int main()
{
    char C[51];
    printf("Enter the string:");
    //gets(C);该函数在c++中已经不支持了
    cin.getline(C,51) ;
    Reverse(C, strlen(C));
    printf("Output is :%s\n", C);
}
#endif

#if 0
//遍历链表
//迭代方法时间复杂度是O(n),空间复杂度是O(1)
//递归都是o(n),隐式地使用了栈
void Reverse()
{
    if(head == NULL) return;
    stack<struct Node*> S;
    Node* temp = head;
    while(temp != NULL){
        S.push(temp);
        temp = temp->next;
    }
    temp = S.pop();
    head = temp;
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp -> next;
    }
}
#endif