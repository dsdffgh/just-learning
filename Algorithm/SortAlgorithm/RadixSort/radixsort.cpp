/* ************************************************************************
> File Name:     radixsort.cpp
> Author:        
> 微信公众号:    
> Created Time:  2024年04月24日 星期三 08时47分14秒
> Description:   
 ************************************************************************/
#include <iostream>
#include <vector>
#include <climits>
#include <math.h>
using namespace::std;
void radixsort(int num[], int size)
{
    int high = 10;
    // 0-9 共10个桶，每个桶容量为high
    vector<vector<int>> bucket(10,vector<int>(high,INT_MAX));
    int maxData = num[0];
    int target = 0;
    while(target<size)
    {
        maxData=maxData < num[target]? num[target]:maxData;
        target++;
    }
    int length = 0;
    int tmp = maxData;
    while(tmp)
    {
        tmp/=10;length++;
    }

    //i遍历桶，j遍历桶中数据
    //将个位数入桶
    int j = 0;
    for(int target = 0; target < size ;target++)
    {
        int i = num[target] % 10;
        while(bucket[i][j] != INT_MAX && j < high)
        {
            j++;
        }
        bucket[i][j] = num[target];
    }
    for(int digit = 1; digit < length; digit++)
    {
        for(int target = 0; target < size ;target++)
        {
            int i = num[target]/static_cast<int>(pow(10,digit)) % 10;
            j=0;
            while(bucket[i][j] != INT_MAX && j < high)
            {
                j++;
            }
            bucket[i][j] = num[target];
        }

        for(int i = 0, target = 0; i < 10;i++ )
        {
            for(int j = 0; j <high; j++){

            if(bucket[i][j]!=INT_MAX) {
                num[target++] = bucket[i][j];
                bucket[i][j] = INT_MAX;
            }
            else break;
            }
        }
    }
}
int main()
{
    int num[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int size = sizeof(num) / sizeof(num[0]);
    radixsort(num, size);
    for (int i = 0; i < size; i++)
    {
        std::cout << num[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
