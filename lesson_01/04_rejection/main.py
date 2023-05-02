import sys

def remove_vowels(string):
	return string.replace("a", "#").replace("e", "#").replace("i", "#").replace("o", "#").replace("u", "#")

n = int(sys.stdin.readline().strip())
words = sys.stdin.readline().strip().split()

first_class = set()
second_class = {}
third_class = {}

for word in words:
	first_class.add(word)
	word_lower = word.lower()
	if word_lower not in second_class:
		second_class[word_lower] = word
	word_unvowel = remove_vowels(word_lower)
	if word_unvowel not in third_class:
		third_class[word_unvowel] = word

k = int(sys.stdin.readline().strip())
elements = sys.stdin.readline().strip().split()

res = []
for element in elements:
	if element in first_class:
		res.append(element)
		continue

	element = element.lower()
	if element in second_class:
		res.append(second_class[element])
		continue

	element = remove_vowels(element)
	if element in third_class:
		res.append(third_class[element])
		continue

	res.append('')

print(' '.join(res))
