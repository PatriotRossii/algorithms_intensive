#include <iostream>
#include <vector>

int main() {
	// Бюджет денежных единиц
	constexpr int budget = 1000;
	// Количество дней
	int n; std::cin >> n;

	// Цены за 1000 кубометров газа за n дней
	std::vector<int> prices(n);
	for (auto& x : prices) {
		std::cin >> x;
	}

	int buy_date{-1};
	int sell_date{-1};
	int maximum_difference{-1};

	for (auto iIt = prices.begin(), begin = prices.begin(), end = prices.end(); iIt != end; ++iIt) {
		int iElement = *iIt;
		if (iElement > budget) continue;
		for (auto jIt = iIt + 1; jIt != end; ++jIt) {
			int jElement = *jIt;
			int difference = jElement - iElement;
			if (difference > maximum_difference) {
				maximum_difference = difference;
				buy_date = iIt - begin;
				sell_date = jIt - begin;
			}
		}
	}

	if (buy_date < sell_date) {
		std::cout << buy_date + 1 << ' ' << sell_date + 1 << '\n';
	} else {
		std::cout << 0 << ' ' << 0 << '\n';
	}
}