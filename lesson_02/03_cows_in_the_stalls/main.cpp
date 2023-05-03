#include <iostream>
#include <vector>

int main() {
	int n, k; std::cin >> n >> k;
	std::vector<int> positions(n);
	for (auto &x: positions) {
		std::cin >> x;
	}

	auto first = positions.begin() + (n / 2) - 1, second = --positions.end();
	int result = positions.back() - positions.front();
	while (k--) {
		result = std::min(
			*second - *first, result
		);
		--first, --second;
	}

	std::cout << result << '\n';
}