#include <iostream>

int main() {
	int n; std::cin >> n;

	if (n == 1) {
		std::cout << 1 << '\n';
	} else {
		int i{0};
		for (; n >= 0; n -= i, ++i) { }
		std::cout << i - 2 << '\n';
	}
}