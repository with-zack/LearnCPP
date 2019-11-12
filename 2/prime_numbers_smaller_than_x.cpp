#include "prime_numbers_smaller_than_x.hpp"
#include <chrono>
std::vector<unsigned int> prime_numbers_smaller_than_x(unsigned int x)
{
	// 给定初始的几个质数，给的越多递归次数越少
	if (x <= 11)
	{
		if (x <= 2)
		{
			return (x == 2) ? std::vector<unsigned int>{2} : std::vector<unsigned int>();
		}
		if (x <= 5)
		{
			return (x == 5) ? std::vector<unsigned int>{2, 3, 5} : std::vector<unsigned int>{ 2, 3 };
		}
		return (x == 11) ? std::vector<unsigned int>{2, 3, 5, 7, 11} : std::vector<unsigned int>{2, 3, 5, 7};
	}
	std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
	unsigned int low = sqrt(x) + 1; // 保证low比真正的x的平方根稍大一点
	std::vector<unsigned int> prime_numbers = prime_numbers_smaller_than_x(low);
	unsigned int num_odd = ((x % 2) == 0) ? (x - low) / 2 : (x - low+1)/2; // 求出(low,x]区间中奇数的数目
	unsigned char* total = new unsigned char[num_odd]; // 只需要（low, x]内的数表
	for (unsigned int i = 0; i < num_odd; i++)
	{
		total[i] = 1;
	}
	// 不需要筛选偶数，故begin()+1,从3开始遍历
	for (auto factor_iter = prime_numbers.begin()+1;factor_iter!=prime_numbers.end();factor_iter++)
	{
		// 只需要产生low到x区间的合数
		unsigned int t = (low / (*factor_iter)) % 2 == 1 ? low / (*factor_iter)+2: low / (*factor_iter) + 1;
		unsigned int composite;
		if (low >> 1 << 1 == low)
		{
			for (unsigned int factor_2 = t; factor_2 <= (x / (*factor_iter)); factor_2 += 2)
			{
				composite = (*factor_iter) * factor_2;
				total[(composite - low) >> 1] = 0; //把合数的索引设为1
			}
		}
		else
		{
			for (unsigned int factor_2 = t; factor_2 <= (x / (*factor_iter)); factor_2 += 2)
			{
				composite = (*factor_iter) * factor_2;
				total[((composite - low) >> 1) - 1] = 0; //把合数的索引设为1
			}
		}
	}
	if (low >> 1 << 1 == low)
	{
		for (unsigned int i = 0; i < num_odd; i++)
		{
			if (total[i])
			{
				prime_numbers.push_back((i << 1) + low + 1);
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < num_odd; i++)
		{
			if (total[i])
			{
				prime_numbers.push_back((i << 1) + low + 2);
			}
		}
	}
	delete[] total;
	std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> span = t2 - t1;
	std::cout << "Took " << span.count() << " ms to find all " << prime_numbers.size() << " prime numbers smaller than or equal to " << x << std::endl;
	return prime_numbers;
}
