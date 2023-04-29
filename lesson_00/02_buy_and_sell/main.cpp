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

	// Согласно условию, цена — целое число от 1 до 5000
	int minimum_price = 5000;
	int maximum_price = 1;
	int buy_date{-1}, sell_date{-1};

	for (auto i = static_cast<size_t>(0), size = prices.size(); i != size; ++i) {
		auto price = prices[i];
		if (price <= budget && price < minimum_price) {
			minimum_price = price;
			buy_date = i;
			maximum_price = 1;
		}
		if (buy_date != -1 && price > maximum_price) {
			maximum_price = price;
			sell_date = i;
		}
	}

	if (buy_date < sell_date && minimum_price < maximum_price) {
		std::cout << buy_date + 1 << ' ' << sell_date + 1 << '\n';
	} else {
		std::cout << 0 << ' ' << 0 << '\n';
	}
}