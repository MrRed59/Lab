#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#include"Money.h"

typedef std::map<int, Money> TMap;
typedef TMap::iterator it;
Money temp;


struct Greater_temp
{
	bool operator()(const std::pair<int, Money>& m_temp)
	{
		return (m_temp.second > temp);
	}
};

struct Comp_less
{
	bool operator()(const std::pair<int, Money>& _Left, const std::pair<int, Money>& _Right)
	const{
		return (_Left.second > _Right.second);
	}
};

struct Equal_temp
{
	bool operator()(std::pair<int, Money> m_temp)
	{
		return(m_temp.second == temp);
	}
};

TMap make_map(const size_t n)
{
	Money money;
	TMap tmoney;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> money;
		tmoney.insert(std::make_pair(i, money));
	}
	return tmoney;
}

void print_map(TMap m)
{
	for (size_t i = 0; i < m.size(); i++)
		std::cout << i << " : " << m[i] << " " << std::endl;
}

Money arithmetic_mean(TMap v)
{
	Money s{};
	for (size_t i = 0; i < v.size(); i++)
		s += v[i];
	return s / v.size();
}

void division(TMap& v)
{
	it i = std::max_element(v.begin(), v.end());
	Money m = i->second;
	for (size_t i = 0; i < v.size(); i++)
		v[i] = v[i] / m;
}

void add_sum_max_min(TMap& s)
{
	it i = std::max_element(s.begin(), s.end());
	Money sum_min_max = i->second;
	i = std::max_element(s.begin(), s.end());
	sum_min_max += i->second;
	for (size_t i = 0; i < s.size(); i++)
		s[i] += sum_min_max;
}


int main()
{
	size_t n;
	std::cout << "N? ";
	std::cin >> n;
	TMap tmoney;
	tmoney = make_map(n);
	print_map(tmoney);

	it i;
	i = std::max_element(tmoney.begin(), tmoney.end());
	std::cout << "Max: " << i->second << std::endl;
	Money money_max = i->second;
	temp = arithmetic_mean(tmoney);
	std::cout << "Arithmetic mean: " << temp << std::endl;


	std::cout << "Search: " << std::endl;
	std::cin >> temp;
	i = std::find_if(tmoney.begin(), tmoney.end(), Equal_temp());
	if (i != tmoney.end())
		std::cout << i->second << std::endl;
	else
		std::cout << "Not such element!" << std::endl;

	std::cout << "Removing the minimum element: " << std::endl;
	i = std::min_element(tmoney.begin(), tmoney.end());
	temp = i->second;
	i = tmoney.find(i->first);
	tmoney.erase(i);
	print_map(tmoney);

	std::cout << "Division: " << std::endl;
	division(tmoney);
	print_map(tmoney);

	std::cout << "Add a minimal element: " << std::endl;
	i = std::min_element(tmoney.begin(), tmoney.end());
	tmoney.insert(std::make_pair(i->first, i->second));
	print_map(tmoney);

	std::cout << "Add the sum of the maximum and minimum: " << std::endl;
	add_sum_max_min(tmoney);
	print_map(tmoney);

	return 0;
}