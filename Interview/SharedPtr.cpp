/*
 * =====================================================================================
 *
 *       Filename:  SharedPtr.cpp
 *
 *    Description:  
 `noexcept` 关键字用于指示函数是否可能抛出异常。在这种情况下，`noexcept` 表示移动构造函数不会抛出异常。这对于提高代码的健壮性和性能很有帮助，因为它允许编译器在某些情况下进行优化。

 在 `MySharedPtr<MyType>&& other` 中，`&&` 是移动语义的标记，表示移动构造函数的参数。`&&` 表示右值引用，它可以接收临时对象或者可以被移动的对象。移动构造函数的存在允许在资源管理中进行高效的移动操作，避免了不必要的深拷贝。

 *
 *        Version:  1.0
 *        Created:  3/3/2024 7:29:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

template <typename T>
class MySharedPtr{
    private:
        T* ptr;
        size_t* ref_count;
    public:
        MySharedPtr( T* p = nullptr ) : ptr(p), ref_count( new size_t(1)) {}

        //  拷贝构造函数
        MySharedPtr( const MySharedPtr<T> &other ) : ptr(other.ptr), ref_count(other.ref_count)
        {
            ++(*ref_count);
        }

        //  移动构造函数
        MySharedPtr(MySharedPtr<T>&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count)
        {
            other.ptr = nullptr;other.ref_count = nullptr;
        }

        //  析构函数
        ~MySharedPtr()
        {
            release();
        }

        void release()
        {
            if( ref_count && --(*ref_count) == 0)
            {
                delete ptr;
                delete ref_count;
                ptr = nullptr;
                ref_count = nullptr;
            }
        }

        //  获取引用计数
        size_t use_count()  const
        {
            return *ref_count;
        }

        //  重载赋值运算符
        MySharedPtr<T>& operator=(const MySharedPtr<T>& other)
        {
            if ( this != &other )
            {
                release();  //  如果不先释放当前对象的资源(如果有)，直接赋值新的资源指针，可能会导致当前对象原来指向的资源内存泄漏。
                ptr = other.ptr;
                ref_count = other.ref_count;
                ++(*ref_count);
            }
            return *this;
        }

        //  重载*运算符
        T& operator*()  const
        {
            return *ptr;
        }

        //  重载->运算符
        T* operator->() const
        {
            return ptr;
        }
};


#include <stdlib.h>

#define EXIT_SUCCESS 0
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
    int
main ( int argc, char *argv[] )
{
    MySharedPtr<int> p(new int(42));

    std::cout << "Value: " << *p << std::endl;

    std::cout << "Value: " << p.operator->() << std::endl;

    std::cout << "Reference count: " << p.use_count() << std::endl;

    //  创建一个新的智能指针。访问同一个对象
    MySharedPtr<int> p2 = p;

    std::cout << "Reference count: " << p.use_count() << std::endl;
    return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
