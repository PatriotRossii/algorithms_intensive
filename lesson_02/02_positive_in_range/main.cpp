#include <iostream>
#include <vector>

// Example: [2, -1, 2, -2, 3]
// Prefix: [0, 1, 1, 2, 2, 3]

// Queries:
// 	(1, 1) -> prefix[1] - prefix[0] = 1
//	(1, 3) -> prefix[3] - prefix[0] = 2
//	(2, 4) -> prefix[4] - prefix[1] = 1
//	(1, 5) -> prefix[5] - prefix[0] = 3

int main() {
	int n; std::cin >> n;

	int size = n + 1;
	std::vector<int> prefix(size);
	for (int i = 1; i != size; ++ i) {
		int element; std::cin >> element;
		prefix[i] = prefix[i - 1] + (element > 0);
	}

	int queries; std::cin >> queries;
	while (queries--) {
		int l, r; std::cin >> l >> r;
		std::cout << prefix[r] - prefix[l - 1] << '\n';
	}
}