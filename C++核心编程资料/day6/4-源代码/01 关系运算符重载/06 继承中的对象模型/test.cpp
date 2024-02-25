#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Base
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};



class Son :public Base
{
public:
	//父类中私有属性，子类继承了，但是编译器给隐藏，因此访问不到
	int m_D;

	void add()
	{
		m_A = 3;
		m_B = 1;
		//m_C = 2;
	}
};


void test01()
{
	Son son;
	Base base;
	base.m_A = 5;
	cout << sizeof(Son) << endl; // 16 、4 、 12  
}

int main(){

	test01();

	system("pause");
	return EXIT_SUCCESS;
}