#include <unordered_map>
#include <iostream>

std::unordered_map<char, int> count_characters(const std::string& string) {
	std::unordered_map<char, int> result;
	for (char x: string) {
		++result[x];
	}
	return result;
}

bool is_anagram(
	const std::string& lhs, const std::string& rhs
) {
	auto lhs_dict = count_characters(lhs), rhs_dict = count_characters(rhs);
	return lhs_dict == rhs_dict;
}

int main() {
	std::string lhs, rhs;
	std::cin >> lhs >> rhs;
	std::cout << (is_anagram(lhs, rhs) ? "YES" : "NO");
}
