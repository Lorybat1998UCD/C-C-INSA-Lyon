// Programmation INSA Lyon 3IF.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
stack<int> euclideanDivision(int &val, stack<int> &v);
int binaryToDecimal(long long binary);

int main()
{
	stack<int> v;
	cout << "Hello! Welcome to the binary/decimal converter!" << endl << "To get started, select " <<
		endl << "   1. for binary to decimal, or " << endl << "   2. for decimal to binary" << endl << endl;
	int choice, val;
	cin >> choice;

	if (choice == 1) {
		long long n;

		cout << "Enter a binary number: ";
		cin >> n;

		cout << "Decimal equivalent:  " << binaryToDecimal(n);
		return 0;
	}
	else if (choice == 2) {
		cout << "Enter the decimal number below" << endl;
		cin >> val;

		stack<int> stack = euclideanDivision(val, v);
		
		int i = 1;
		while (!stack.empty()) {

			cout << stack.top();
			stack.pop();
			i++;
		}
		cout << endl;
	}

}
	 int binaryToDecimal(long long binary)
	{
		int decimal = 0, i = 0, remainder;
		while (binary != 0)
		{
			remainder = binary % 10;
			binary /= 10;
			decimal += remainder * pow(2, i);
			++i;
		}
		return decimal;
	}
	

//recursive division by 2 until we reach base case (val == 1 || val == 0)
stack<int> euclideanDivision(int &val, stack<int> &v)
{
	while (val > 0) {
		int remainder = val % 2;
		val = val / 2;
		v.push(remainder);
	}
	return v;
}
