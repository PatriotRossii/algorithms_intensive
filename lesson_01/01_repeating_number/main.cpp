#include <unordered_map>
#include <iostream>
#include <vector>

int main() {
	int n, k; std::cin >> n >> k;
	std::vector<int> numbers(n);
	for (auto& x: numbers) {
		std::cin >> x;
	}

	bool repeats = false;
	std::unordered_map<int, std::size_t> indeces;
	for (std::size_t idx = 0, size = numbers.size(); idx != size; ++idx) {
		auto [it, inserted] = indeces.insert({numbers[idx], idx});
		if (!inserted) {
			auto difference = idx - it->second;
			if (difference <= k) {
				repeats = true;
				break;
			}
			it->second = idx;
		}
	}

	std::cout << (repeats ? "YES" : "NO") << '\n';
}