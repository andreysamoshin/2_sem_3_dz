#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <chrono>
#include <random>
#include <set>


// template of the function which calculates hash
template < typename T >
void hash_combine(std::size_t& seed, const T& value) noexcept
{
	seed ^= std::hash < T >()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

// 
template < typename T >
void hash_value(std::size_t& seed, const T& value) noexcept
{
	hash_combine(seed, value);
}

template < typename T, typename ... Types >
void hash_value(std::size_t& seed, const T& value, const Types & ... args) noexcept
{
	hash_combine(seed, value);
	hash_value(seed, args...);
}

template < typename ... Types >
std::size_t hash_value(const Types & ... args) noexcept
{
	std::size_t seed = 0;
	hash_value(seed, args...);
	return seed;
}


std::vector < std::string > make_random_words(std::size_t N, std::size_t length) // length = 10 - good enough
{
	std::uniform_int_distribution <> letter(97, 122);
	std::default_random_engine e(static_cast <std::size_t> (
		std::chrono::system_clock::now().time_since_epoch().count()));

	std::vector < std::string > wordss;

	for (std::string s(length, '_'); std::size(wordss) < N; wordss.push_back(s))
		for (auto& c : s)
			c = letter(e);

	return wordss;
}

int main(int argc, char** argv)
{
	int n;
	std::cin >> n;
	while (n < 100000000)
	{ 
		std::cin >> n;
		std::vector <std::string> words;
		std::set < int > hashes;
		int collisions = 0;

		for (int i = 0U; i < n; i++)
		{
			int amount_1 = hashes.size();
			auto word = make_random_words(1, 10);
			auto hash = hash_value(word[0]);
			words.push_back(word[0]);
			hashes.insert(hash);
			int amount_2 = hashes.size();

			if (amount_1 == amount_2)
			{
				collisions += 1;
			}
		}
		std::cout << collisions << std::endl;

			//std::cout << i << " " << collisions << std::endl;
	}

	system("pause");

	return EXIT_SUCCESS;
}

