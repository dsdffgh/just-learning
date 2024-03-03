/*
 * =====================================================================================
 *
 *       Filename:  selestionsort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  3/1/2024 9:47:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <vector>
template < typename T >
void selection_sort(std::vector<T> &arr)
{
    for(int i = 0; i < static_cast<T> (arr.size())-1; i++)
    {
        int min = i;

        for(int j = i+1; j < static_cast<T>(arr.size()); j++)
        {
            if(arr[j] < arr[min])
                min = j;
        }

        std::swap(arr[min], arr[i]);
    }
}
int main() {

    std::vector<int> test1 = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    std::vector<double> test2 = {3.14, 1.41, 1.59, 2.65, 3.58, 9.79};

    std::cout << "Original array 1: ";
    for (int num : test1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selection_sort(test1);

    std::cout << "Sorted array 1: ";
    for (int num : test1) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Original array 2: ";
    for (double num : test2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    selection_sort(test2);

    std::cout << "Sorted array 2: ";
    for (double num : test2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
