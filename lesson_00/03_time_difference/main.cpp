#include <algorithm>
#include <iostream>
#include <vector>

struct Time {
	int hours;
	int minutes;

	int to_minutes() const {
		return 60 * hours + minutes;
	}
	int operator-(const Time& rhs) const {
		return to_minutes() - rhs.to_minutes();
	}
	auto operator<=>(const Time&) const = default;
};

int main() {
	int n; std::cin >> n;
	if (n == 1) {
		std::cout << 0 << '\n';
		return 0;
	}

	std::vector<Time> time_points;
	time_points.reserve(n);
	while (n--) {
		int hours; std::cin >> hours;
		std::cin.ignore(1);
		int minutes; std::cin >> minutes;

		time_points.push_back(
			Time{
				.hours=hours,
				.minutes=minutes
			}
		);
	}
	std::sort(time_points.begin(), time_points.end());

	int minDelta = 24 * 60 - (time_points.back() - time_points.front());
	for (int i = 1, size = time_points.size(); i != size; ++i) {
		minDelta = std::min(time_points[i] - time_points[i - 1], minDelta);
	}
	std::cout << minDelta << '\n';
}