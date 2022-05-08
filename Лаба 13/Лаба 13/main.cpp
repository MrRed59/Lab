#include<iostream>
#include<vector>
#include<algorithm>

#include"Money.h"

typedef std::vector<Money> TMoney;
Money temp;

struct Greater_temp
{
	bool operator()(Money& m_temp)
	{
		return (m_temp > temp);
	}
};

struct Comp_less
{
	bool operator()(const Money& _Left, const Money& _Right)
	const{
		return (_Left > _Right);
	}
};

struct Equal_temp
{
	bool operator()(Money& m_temp)
	const{
		return(m_temp == temp);
	}
};

TMoney make_vector(const size_t n)
{
	Money money;
	TMoney tmoney;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> money;
		tmoney.push_back(money);
	}
	return tmoney;
}

void print_vector(const TMoney& tmoney)
{
	for (auto &i: tmoney)
	{
		std::cout << i << ": ";
	}
	std::cout << std::endl;
}

Money arithmetic_mean(const TMoney& tmoney)
{
	Money temp = tmoney[0];
	for (size_t i = 0; i < tmoney.size(); i++)
		temp += tmoney[i];
	return temp / tmoney.size();
}

void division(Money& money)
{
	money /= temp;
}


int main()
{
	size_t n;
	std::cout << "N? ";
	std::cin >> n;
	TMoney tmoney;
	tmoney = make_vector(n);
	print_vector(tmoney);

	TMoney::iterator i;
	i = std::max_element(tmoney.begin(), tmoney.end());
	std::cout << "Max: " << *i << std::endl;
	Money money_max = *i;
	temp = arithmetic_mean(tmoney);
	std::cout << "Arithmetic mean: " << temp << std::endl;
	std::replace_if(tmoney.begin(), tmoney.end(), Greater_temp(), money_max);
	std::cout << "Replacement: " << std::endl;
	print_vector(tmoney);

	std::cout << "Descending sort: " << std::endl;
	std::sort(tmoney.begin(), tmoney.end(), Comp_less());
	print_vector(tmoney);

	std::cout << "Ascending sort: " << std::endl;
	std::sort(tmoney.begin(), tmoney.end());
	print_vector(tmoney);

	std::cout << "Search: " << std::endl;
	std::cin >> temp;
	i = std::find_if(tmoney.begin(), tmoney.end(), Equal_temp());
	if (i != tmoney.end())
		std::cout << *i << std::endl;
	else
		std::cout << "Not such element!" << std::endl;

	std::cout << "Deletion: " << std::endl;
	i = std::min_element(tmoney.begin(), tmoney.end());
	temp = *i;
	i = std::remove_if(tmoney.begin(), tmoney.end(), Equal_temp());
	tmoney.erase(i, tmoney.end());
	print_vector(tmoney);

	std::cout << "Division: " << std::endl;
	i = std::max_element(tmoney.begin(), tmoney.end());
	temp = *i;
	std::for_each(tmoney.begin(), tmoney.end(), division);
	print_vector(tmoney);

	return 0;
}