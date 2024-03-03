/*
 * =====================================================================================
 *
 *       Filename:  shared_ptr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2/29/2024 8:53:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include < iostream > 
template < typename T > 
class shared_ptr
{
private:
  T * ptr;
  size_t *count;

public:
//构造函数
explicit shared_ptr (T * p = nullptr):ptr (p),
    count (new size_t (1))
  {
  }

  // 拷贝构造函数
  shared_ptr (const shared_ptr < T > &other):ptr (other.ptr),
    count (other.count)
  {
    ++(*count);
  }

  // 析构函数
  ~shared_ptr ()
  {
    if (--(*count) == 0)
      {
	delete ptr;
	delete count;
      }
  }

  // 重载赋值运算符
  shared_ptr < T > &operator= (const shared_ptr < T > &other)
  {
    if (this != &other)
      {
	// 递减当前计数器
	if (--(*count) == 0)
	  {
	    delete ptr;
	    delete count;
	  }

	// 更新指针和计数器
	ptr = other.ptr;
	count = other.count;
	++(*count);
      }
    return *this;
  }

  // 解引用操作符
  T & operator* ()const
  {
    return *ptr;
  }

  // 指针访问操作符
  T *operator-> () const
  {
    return ptr;
  }

  // 获取引用计数
  size_t use_count () const
  {
    return *count;
  }
};

int
main ()
{
  shared_ptr < int >ptr1 (new int (42));
  shared_ptr < int >ptr2 = ptr1;
  std::cout << "ptr1 count: " << ptr1.use_count () << std::endl;
  std::cout << "ptr2 count: " << ptr2.use_count () << std::endl;
  return 0;
}

indent: Standard input: 79: Error:Unexpected end of file
