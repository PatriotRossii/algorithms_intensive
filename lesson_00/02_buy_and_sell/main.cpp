#include <iostream>
#include <vector>
#include <utility>

int main() {
	// Бюджет денежных единиц
	constexpr double budget = 1024;
	// Количество дней
	int n; std::cin >> n;

	// Цены за 1000 кубометров газа за n дней
	std::vector<int> prices(n);
	for (auto& x : prices) {
		std::cin >> x;
	}

	// Индекс дня, когда выгодней всего купить газ
	int min_index = 0;
	// Максимальное количество газа, которое мы можем купить
	double max_gas = budget / prices[0];
	// Максимальная прибыль
	double max_revenue = 0;

	// Ответ
	std::pair<int, int> answer{0, 0};

	for (int i = 1; i != n; ++i) {
		// Наша выручка — наш газ, помноженный на цену продажи, минус деньги, которые мы вложили в покупку
		int revenue = max_gas * prices[i] - budget;
		if (revenue > max_revenue) {
			max_revenue = revenue;
			answer = {min_index + 1, i + 1};
		}
		// Может оказаться, что сегодня мы можем купить больше газа, чем у нас было — это выгодно
		if (budget / prices[i] > max_gas) {
			min_index = i;
			max_gas = budget / prices[i];
		}
	}

	std::cout << answer.first << ' ' << answer.second << '\n';
}