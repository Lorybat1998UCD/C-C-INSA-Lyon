// Programmation INSA Lyon 3IF.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<int> euclideanDivision(int &val, stack<int> &v);

int main()
{
	stack<int> v;
    cout << "Hello! Welcome to the binary/decimal converter!" << endl <<"To get started, select " <<
		endl <<"1. for binary to decimal, or "<< endl << "2. for decimal to binary)"; 
	string valstring;
	int choice, val;
	cin >> choice;

	if (choice == 1) {
		cout << "Enter the binary  number below" << endl;
		getline(std::cin, valstring);

		int decimal = 0;
		for (int i = 0; i < valstring.length; i++) {
			if (valstring.at(i) == '1')
				decimal = decimal * 2 + 1;
			else if (valstring.at(i) == '0')
				decimal = decimal * 2;
			else break;
		}
		cout << "Decimal equivalent :" << decimal;
	}

	else if (choice == 2) {
		cout << "Enter the decimal number below" << endl;
		cin >> val;
				
		stack<int> stack = euclideanDivision(val, v);
		//recursively divide by 2 and take remainder
		while (!stack.empty()) {
			cout << &stack.top;
			stack.pop();
		}
		cout << endl;
	}
}

stack<int> euclideanDivision(int &val, stack<int> &v)
{
	while (val > 0) {
		int remainder = val % 2;
		val = val / 2;
		v.push(remainder);
	}
	return v;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
