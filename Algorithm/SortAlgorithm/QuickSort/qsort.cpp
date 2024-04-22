/*
 * =====================================================================================
 *
 *       Filename:  qsort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  3/1/2024 4:05:34 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>

namespace quick_sort{
template < typename T > void
swap (T * a, T * b)
{

  T temp = *a;
  *a = *b;
  *b = temp;
}

template < typename T > int
partition (T s[], int low, int high)
{
  int pivot = high;
  int firsthigh = low;

  for (int i = low; i < high; i++)
    {
      if (s[i] < s[pivot])//cmp
	{
	  swap (s + i, s + firsthigh);
	  firsthigh++;
	}
    }

  swap (s + pivot, s + firsthigh);
  return firsthigh;
}

template < typename T > void
quicksort (T s[], int low, int high)
{
  if (high-low > 0)
    {
      int p = partition (s, low, high);
      quicksort (s, low, p - 1);
      quicksort (s, p + 1, high);

    }
}
}//namespace quick_sort
int
main ()
{
  int arr[] = {
    3, 6, 8, 2, 5, 1, 9, 4, 7
  };
  int n = sizeof (arr) / sizeof (arr[0]);

  std::cout << "Original array: ";
  for (int i = 0; i < n; i++)
    {

      std::cout << arr[i] << " ";
    }
  std::cout << std::endl;

  quick_sort::quicksort (arr, 0, n - 1);

  std::cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    {
      std::cout << arr[i] << " ";
    }
  std::cout << std::endl;

  return 0;
}
