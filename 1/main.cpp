#include <iostream>
#include "print_value_by_digit.hpp"
using namespace std;
int main()
{
	cout << "Enter the number and press 'Enter'" << endl;
	unsigned int value;
	cin >> value;
	print_value_by_digit(value);
}