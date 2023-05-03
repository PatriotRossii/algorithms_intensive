#include <iostream>
#include <vector>

bool invites(int lhs, int rhs) {
	return !(
		(rhs <= 0.5 * lhs + 7) ||
		(rhs > lhs) ||
		(rhs > 100 && lhs < 100)
	);
}

int main() {
	int n; std::cin >> n;
	std::vector<int> ages(n);
	for (auto& x : ages) {
		std::cin >> x;
	}

	int result{};
	for (auto iIt = ages.begin(), end = ages.end(); iIt != end; ++iIt) {
		int iElement = *iIt;
		for (auto jIt = iIt + 1; jIt != end; ++jIt) {
			int jElement = *jIt;
			result += invites(iElement, jElement);
			result += invites(jElement, iElement);
		}
	}
	std::cout << result << '\n';
}
