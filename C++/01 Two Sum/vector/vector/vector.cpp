// vector.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<int> vi(2, 9);

	cout << "size:" << vi.size() << " capacity:" << vi.capacity()<<endl;
	vi.push_back(1);
	cout << "size:" << vi.size() << " capacity:" << vi.capacity() << endl;
	vi.push_back(2);
	cout << "size:" << vi.size() << " capacity:" << vi.capacity() << endl;
	vi.push_back(3);
	cout << "size:" << vi.size() << " capacity:" << vi.capacity() << endl;
	vi.push_back(4);
	cout << "size:" << vi.size() << " capacity:" << vi.capacity() << endl;
	vi.push_back(5);
	cout << "size:" << vi.size() << " capacity:" << vi.capacity() << endl;

	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;

	vector<int>::iterator it = find(vi.begin(), vi.end(), 2);
	vi.insert(it, 3, 8);
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;

	vector<int>::iterator it2 = find(vi.begin(), vi.end(), 4);
	vi.erase(it2);
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;

	vi.erase(vi.begin(), vi.end());
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;
	
	cout << "size:" << vi.size() << " capacity:" << vi.capacity() << endl;
	
	vi.push_back(3);
	vi.push_back(4);
	vi.push_back(5);
	vi.push_back(10);
	vi.push_back(9);
	vi.push_back(6);
	sort(vi.begin(),vi.end());
	for (int i = 0; i < vi.size(); i++)
		cout << vi[i] << " ";
	cout << endl;

    return 0;
}

