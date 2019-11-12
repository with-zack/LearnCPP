#include "print_value_by_digit.hpp"
#include <vector> // 这是一个“容器”，也被称为向量
#include <iostream>
void print_value_by_digit(unsigned int x)
{
	// 创建一个容器，用于存放各位的数字
	std::vector<unsigned int> digits;
	// 将局部变量x的值赋给B，unsigned是指无符号，也就是只有正数没有负数
	unsigned int B = x;
	/*
	下面利用的是C++中整型数据（也就是整数int，即integer的简写）的性质，B除以10后，最后一位到了小数点后
	但是由于B是一个整数，其实最后一位就消失了、被忽略了，再乘以10后就相当于把原来的x的最后一位变成了0
	例如：假设原来的x是123，除以10 后成了12（而不是12.3），再乘10，就成了120.
	123- 120，我们就得到了最后一位数字
	*/
	unsigned int digit = B - B/10u*10u; // 10u中的u代表unsigned，你也可以不写u，直接写成10
	// 得到了数字之后将之存放到容器内
	digits.push_back(digit);
	B /= 10u;   // B /= 10u 相对于 B = B/10u，现在B变成了12
	// 循环结构：当B不等于0时，也就是当B还有有效数字时，循环运行大括号里面的内容
	while (B != 0)
	{
		// 继续获得最后一位数字，即digit被赋值为12-10，即2；
		digit = B - B/10u * 10u;
		digits.push_back(digit);
		B /= 10u; // 现在B=1， 回过头到while那一行
	}
	// 现在因为B=0了，结束循环后，所有的数字都已经存放到容器里
	std::reverse(digits.begin(), digits.end()); // 本来的顺序是3， 2，1我们将它反过来，现在顺序是1，2，3
	for (unsigned int i = 0; i < digits.size(); i++)
	{
		std::cout << digits[i] << " "; // 输出到控制台
	}
	std::cout << std::endl; // 输出结束符
}