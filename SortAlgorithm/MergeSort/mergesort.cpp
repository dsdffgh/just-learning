/*
 * =====================================================================================
 *
 *       Filename:  mergesort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  3/1/2024 7:52:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<queue>
using namespace std;
void
merge (int s[], int low, int middle, int high);

void
mergesort (int s[], int low, int high)
{
  int middle;
  if (low < high)
    {
      middle = low + (high - low) / 2;
      mergesort (s, low, middle);
      mergesort (s, middle + 1, high);
      merge (s, low, middle, high);
    }
}

void
merge (int s[], int low, int middle, int high)
{
  queue < int >buffer1, buffer2;
  for (int i = low; i <= middle; i++)
    {
      buffer1.push (s[i]);
    }
  for (int i = middle + 1; i < high; i++)
    {

      buffer2.push (s[i]);
    }

  int i = low;
  while (!(buffer1.empty() || buffer2.empty()))
    {
      if (buffer1.front () <= buffer2.front ())
	{
	  s[i++] = buffer1.front ();
	  buffer1.pop ();
	}
      else
	{

	  s[i++] = buffer2.front ();
	  buffer2.pop ();
	}
    }
  while (!buffer1.empty ())
    {

      s[i++] = buffer1.front ();
      buffer1.pop ();
    }
  while (!buffer2.empty ())
    {
      s[i++] = buffer2.front ();
      buffer2.pop ();
    }
}
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

  mergesort( arr, 0, n-1 );

  std::cout << "Sorted array: ";
  for (int i = 0; i < n; i++)
    {
      std::cout << arr[i] << " ";
    }
  std::cout << std::endl;

  return 0;
}
