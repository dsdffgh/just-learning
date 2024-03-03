/*
 * =====================================================================================
 *
 *       Filename:  MyString.cpp
 *
 *    Description: problems/写string类的构造，析构，拷贝函数.md 
 *
 *        Version:  1.0
 *        Created:  2/29/2024 7:56:21 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Theonesssssssss (), whyunotdo@qq.com
 *   Organization:  
 *
 * =====================================================================================
 */

class MyString{
	private:
		char* m_Data;
		int m_Length;

	public:
		MyString() : m_Data(new char[1]), m_Length(0){
			m_Data[0] = '\0';
		}

		MyString(const char* str){
			m_Length = strlen(str);
			m_Data = new char[m_Length+1];
			strcpy(m_Data, str);
		}
		
		MyString(const MyString& other){
			m_Length = other.m_Length;
			if(m_Length > 0){
				m_Data = new char[m_Length+1];
				strcpy(m_Data, other.m_Data);
			}else{
				//...
			}
		}

		~MyString(){
			delete[] m_Data;
		}

		MyString& operator=(const MyString& other){
			if(&other == this){
				return *this;
			}

			delete[] m_Data;
			m_Length = other.m_Length;

			//if

			return *this;
		}
};

