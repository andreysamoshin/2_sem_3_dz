#include <iostream>
#include <set>
#include <vector>
#include <chrono>
#include <algorithm>

class Timer
{
public:
	using clock_t = std::chrono::steady_clock;
	using time_point_t = clock_t::time_point;

	Timer() : m_begin(clock_t::now()) {}

	~Timer()
	{
		auto end = clock_t::now();

		std::cout << "micro : " << std::chrono::duration_cast <std::chrono::microseconds> (end - m_begin).count() << std::endl;
	}

private:
	time_point_t m_begin;
};



int main()
{
	// Lets look at the set first


	std::set <int> random_numbers_1;
	int n;
	std::cin >> n;

	{
	Timer t;
	for (int i = 0U; i < n; i++)
	{
		random_numbers_1.insert(rand());
	}

	}



	std::vector <int> random_numbers_2;

	{
		Timer t;
		for (int i = 0U; i < n; i++)
		{
			random_numbers_2.push_back(rand());
		}
		sort(random_numbers_2.begin(), random_numbers_2.end());
	}
	

	return EXIT_SUCCESS;
}

// It seems that creating a vector and sorting it is more effective than creating a set
