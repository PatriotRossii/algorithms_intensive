#include <string_view>
#include <iostream>
#include <string>

int main() {
	std::string palindrome; std::cin >> palindrome;

	if (palindrome.size() == 1) {
		std::cout << '\n';
		return 0;
	}
	for (auto i = static_cast<size_t>(0), size = palindrome.size() / 2; i != size; ++i) {
		auto& x = palindrome[i];
		if (x != 'a') {
			x = 'a';
			goto finish;
		}
	}
	palindrome[palindrome.size() - 1] = 'b';

finish:
	std::cout << palindrome << '\n';
}