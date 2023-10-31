// C++ Program to check for balanced parentheses in an expression using stack.
// 2023-02-20_190142.png
#include <iostream>
#include <string.h>
#include <stack>
using namespace std;

#define parentheses_left '('
#define parentheses_right ')'
#define brackets_left '['
#define brackets_right ']'
#define braces_left '{'
#define braces_right '}'

int Check_Parentheses(char *Brackets_list)
{

    stack<char> S;
    int i = 0;
    do
    {
        if (Brackets_list[i] == '{' || Brackets_list[i] == '[' || Brackets_list[i] == '(')
        {
            S.push(Brackets_list[i]);
        }
        else if (Brackets_list[i] == '}' || Brackets_list[i] == ']' || Brackets_list[i] == ')')
        {
            if (S.empty())
            {
                cout << "False!" << endl;
                return 0;
            }
            if (S.top() == parentheses_left && Brackets_list[i] == parentheses_right)
                S.pop();
            else if (S.top() == brackets_left && Brackets_list[i] == brackets_right)
                S.pop();
            else if (S.top() == braces_left && Brackets_list[i] == braces_right)
                S.pop();
            else
            {
                cout << "The Brackets isn't match" << endl;
                return 0;
            }
        }
        i++;
    } while (*(Brackets_list + i) = '\0');
    return S.empty() ? 1 : 0;
}

int main()
{
    char test1[] = {"{{[()]}}"};
    char test2[] = "{[[}";
    char test3[] = {']', '['};
    char test4[] = {"{}}"};
    char test5[] = {'{', '[', '[', '}'};

    // Check_Parentheses(test1);
    Check_Parentheses(test2);
    Check_Parentheses(test3);
    // Check_Parentheses(test4);
    Check_Parentheses(test5);

    return 0;
}