#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Person
{
public:
	Person(char* name, int age)
	{
		this->m_Name = new char[strlen(name)+1];
		strcpy(this->m_Name, name);

		this->m_Age = age;
	}

	//拷贝构造函数
	Person(const Person & p)
	{
		this->m_Name = new char[strlen(p.m_Name) + 1];
strcpy(this->m_Name, p.m_Name);
this->m_Age = p.m_Age;
	}


	//系统会默认给一个类 创建至少3个函数   默认构造 、 析构、 拷贝构造（简单值拷贝） operator= (值拷贝)

	Person& operator=(const Person& p)
	{
		//先判断原来堆区是否有数据，如果有先释放
		if (this->m_Name != NULL)
		{
			delete[] this->m_Name;
			this->m_Name = NULL;
		}
		this->m_Name = new char[strlen(p.m_Name) + 1];
		strcpy(this->m_Name, p.m_Name);



		//this->m_Name = p.m_Name;
		this->m_Age = p.m_Age;

		return *this;
	}

	~Person()
	{
		if (this->m_Name != NULL)
		{
			//cout << "析构" << endl;
			delete[] this->m_Name;
			this->m_Name = NULL;
		}

	}

	char* m_Name;
	int m_Age;
};


void test01()
{
	Person p1("Tom", 18);

	Person p2("Jerry", 19);

	p1 = p2;

	cout << "p1 姓名： " << p1.m_Name << " 年龄： " << p1.m_Age << endl;

	cout << "p2 姓名： " << p2.m_Name << " 年龄： " << p2.m_Age << endl;

	Person p3(" ", 0);
	p3 = p1 = p2;

	cout << "p3 姓名： " << p3.m_Name << " 年龄： " << p3.m_Age << endl;

	Person p4(p3);
	cout << "p4 姓名： " << p4.m_Name << " 年龄： " << p4.m_Age << endl;
}



void printf01(int val)
{
	cout << val << "";
}

void test033()
{
	vector<vector<int>> res;
	vector<int> res1;


	for (int i = 0;i < 10;i++)
		res1.push_back(i);
	for (int i = 0;i < 10;i++)
		res.push_back(res1);

	//for_each(res1.begin(), res1.end(), printf01);
	for (auto res2 : res)
	{
		cout << endl;
		for (auto res1 : res2)
		{
			cout << res1;
		}
	}
}


void printfs(int val)
{
	cout << val;
}


void printfs02(vector<int> val)
{
	for(auto index : val)
	cout << index;
}

void ForEach()
{
	vector<vector<int>> res;
	vector<int> res1;


	for (int i = 0;i < 10;i++)
		res1.push_back(i);
	for (int i = 0;i < 10;i++)
		res.push_back(res1);
	
	for_each(res.begin(), res.end(), printfs02);
	for_each(res1.begin(), res1.end(), printfs);



}



int main() {

	ForEach();

	//test033();
	//test01();

	/*int a = 10;
	int b = 20;
	int c;
	c = a = b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;*/

	system("pause");
	return EXIT_SUCCESS;
}