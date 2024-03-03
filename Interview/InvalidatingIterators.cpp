/*
 * =====================================================================================
 *
 *       Filename:  InvalidatingIterators.cpp
 *
 *    Description:  test Invalidating Iterators for vector
 *
 *        Version:  1.0
 *        Created:  3/3/2024 3:12:16 PM
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
#include	<stdlib.h>

using namespace std;
#define EXIT_SUCCESS 0
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:     https://blog.csdn.net/DEXTERFUTIAN/article/details/128771392
 *                   https://blog.csdn.net/lujiandong1/article/details/49872763
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    vector< int >arr = {
        1,2,3,4
    };
    auto it = arr.begin();
//    arr.insert( it, 20 );    /* normal */
    it = arr.insert( it, 20 );    /* 将insert以后的迭代器赋值给it，更新it */
    arr.insert( it, 10 );    /* error */

    
    for ( auto a : arr ) {
        cout << a << ' ';
    }
    cout << endl << "$$$$$$$$$$$$$$$$$" << endl;

    std::vector<int> vec;
    vec.reserve(6); // 预分配6个元素的空间
    vec.push_back(1); // 初始化前四个元素
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    auto it2 = vec.begin();
    cout << *it2 << endl;
    vec.erase(it2);
//     vec.erase(it2++);
//    vec.insert( it2, 21 );    /* invaild */
//    vec.insert( it2++, 21 );   
    cout << *it2 << endl;
//    for ( auto a : arr ) {
//        cout << a << ' ';
//    }

    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
