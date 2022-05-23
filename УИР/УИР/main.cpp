#include<iostream>
#include<chrono>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();

	for (size_t i = 0; i < 10000; i++)
	{
		double* value = new double[500]{0};
		delete[] value;
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<double> duration = end - start;
	std::cout << "Duration: " << duration.count() << std::endl;
}