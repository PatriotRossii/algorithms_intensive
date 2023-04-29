#include <string_view>
#include <iostream>
#include <string>

bool can_replace(std::string_view palindrome) {
	if (palindrome.size() == 1)
		return false;
	for (const char& x: palindrome)
		if (x != 'a')
			return true;
	return false;
}

bool is_palidrome(std::string_view s)
{
    return std::equal(begin(s), begin(s) + size(s) / 2, rbegin(s));
}

int main() {
	std::string palindrome; std::cin >> palindrome;
	if (!can_replace(palindrome)) {
		std::cout << '\n';
		return 0;
	}

	while (is_palidrome(palindrome)) {
		for (auto& x: palindrome)
			if (x != 'a') {
				x = static_cast<char>(
					static_cast<int>(x) - 1
				);
				break;
			}
		if (is_palidrome(palindrome))
			break
	}

	std::cout << palindrome << '\n';
}