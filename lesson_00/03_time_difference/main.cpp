#include <algorithm>
#include <iostream>
#include <vector>

struct Time {
	int hours;
	int minutes;

	int to_seconds() const {
		return hours * 3600 + minutes * 60;
	}
	int operator-(const Time& rhs) const {
		return to_seconds() - rhs.to_seconds();
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

	int minDelta{24 * 3600};

	auto previousIt = time_points.begin();
	auto it = time_points.begin();
	++it;

	for (auto end = time_points.end(); it != end; ++previousIt, ++it) {
		minDelta = std::min(*it - *previousIt, minDelta);
	}
	minDelta = std::min(86400 - (time_points.back() - time_points.front()), minDelta);

	std::cout << minDelta / 60 << '\n';
}