#include <array>
#include <vector>
#include <iostream>
#include <utility>
#include <map>
#include <unordered_set>

constexpr inline int VECTORS_COUNT = 3;

int main() {
	std::map<int, int> count;
	for (int i = 0; i != VECTORS_COUNT; ++i) {
		int n; std::cin >> n;
		std::unordered_set<int> elements;
		while (n--) {
			int element; std::cin >> element;
			elements.insert(element);
		}

		for (const auto& element: elements) {
			auto [it, inserted] = count.insert(
				{element, 1}
			);
			if (!inserted) {
				it->second += 1;
			}
		}
	}
	for (auto& [key, value]: count) {
		if (value >= 2)
			std::cout << key << ' ';
	}
	std::cout << '\n';
}