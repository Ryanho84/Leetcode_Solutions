// vector_operation.cpp : 定义控制台应用程序的入口点。
//序列式容器vector，所采用的数据结构非常简单：线性连续空间。

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main()
{
	int i;
	vector<int> iv(2, 9);
	cout << "size" << iv.size() << endl;       //2
	cout << "capacity" << iv.capacity() << endl;    //2

	iv.push_back(1);
	//新增元素时，如果超过当时的容量，则容器会扩充,扩充多少，不同版本vs不一样
	cout << "size" << iv.size() << endl;       //3
	cout << "capacity" << iv.capacity() << endl;    //4

	iv.push_back(2);
	cout << "size" << iv.size() << endl;		//4
	cout << "capacity" << iv.capacity() << endl;      //4

	iv.push_back(3);
	cout << "size" << iv.size() << endl;          //5
	cout << "capacity" << iv.capacity() << endl;      //8

	iv.push_back(4);
	cout << "size" << iv.size() << endl;          //6
	cout << "capacity" << iv.capacity() << endl;      //8

	for (i = 0; i < iv.size(); i++)
		cout << iv[i] << " ";
	cout << endl;                     //9 9 1 2 3 4

	iv.push_back(5);
	cout << "size" << iv.size() << endl;          //7
	cout << "capacity" << iv.capacity() << endl;   //8
	for (i = 0; i < iv.size(); i++)
		cout << iv[i] << " ";
	cout << endl;								//9 9 1 2 3 4 5 

	iv.pop_back();
	iv.pop_back();
	cout << "size" << iv.size() << endl;          //5
	cout << "capacity" << iv.capacity() << endl;     //8

	iv.pop_back();
	cout << "size" << iv.size() << endl;          //4
	cout << "capacity" << iv.capacity() << endl;    //8
	//begin() {return start;  使用空间的头,非可用空间}   end() {return finish; 使用空间的尾}
	vector<int>::iterator ivite = find(iv.begin(), iv.end(), 1);

	if (ivite != iv.end())
		//可区间，可单个
		iv.erase(ivite);
	cout << "size" << iv.size() << endl;          //3
	cout << "capacity" << iv.capacity() << endl;     //8
	for (i = 0; i < iv.size(); i++)
		cout << iv[i] << " ";				//9 9 2
	cout << endl;

	ivite = find(iv.begin(), iv.end(), 2);
	if (ivite != iv.end())
		//前插
		iv.insert(ivite, 3, 7);
	cout << "size" << iv.size() << endl;          //6
	cout << "capacity" << iv.capacity() << endl;     //8
	for (i = 0; i < iv.size(); i++)
		cout << iv[i] << " ";				//9 9 7 7 7 2
	cout << endl;

	iv.clear();
	cout << "size" << iv.size() << endl;          //0
	cout << "capacity" << iv.capacity() << endl;     //8

	iv.push_back(9);
	iv.push_back(10);
	iv.push_back(2);
	iv.push_back(8);
	iv.push_back(3);
	iv.push_back(4);
	iv.push_back(6);
	iv.push_back(1);
	iv.push_back(5);
	iv.push_back(7);

	sort(iv.begin(), iv.end());
	cout << "size" << iv.size() << endl;          //10
	cout << "capacity" << iv.capacity() << endl;     //16
	for (i = 0; i < iv.size(); i++)
		cout << iv[i] << " ";				//1 2 3 4 5 6 7 8 9 10
	cout << endl;

    return 0;
}

