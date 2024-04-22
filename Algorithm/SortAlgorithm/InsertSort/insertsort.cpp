/*
 * =====================================================================================
 *
 *       Filename:  insertsort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  3/1/2024 10:05:07 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

void insert_sort(int arr[])
{
    int length = sizeof(arr)/sizeof(arr[0]);
    for(int i = 1; i < length; i++ )
    {
        int j = i;
        while((j>0)&&(arr[j] < arr[j-1]))
        {
            swap(s[j], s[j-1]);
            j = j-1;
        }
    }
}
