#include <iostream>

using namespace std;

int sol(int x)
{
    if(x < 0) return false;
    int num = 0;

    while (x)
    {
        num = num * 10 + x % 10;
        x /= 10;

    }
    if(x == num)
    {
        return true;
    }
    else 
        return false;
}

int main()
{
    int input  = 121;
    cout << sol(input) << endl;
    input = -121;
    cout << sol(input) << endl;

    input = -0;
    cout << sol(input) << endl;

}
