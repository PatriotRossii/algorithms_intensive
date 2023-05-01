#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstdlib>

int main() {
	int n; std::cin >> n;
	int treshold = n / 2;

	std::vector<int> elements(n);
	for (auto& element: elements) {
		std::cin >> element;
	}

	std::unordered_map<int, int> count;
	for (const auto& element: elements) {
		auto [it, inserted] = count.insert({element, 1});
		if (!inserted)
			it->second += 1;
		if (it->second > treshold) {
			std::cout << element << '\n';
			return EXIT_SUCCESS;
		}
	}

	return EXIT_FAILURE;
}