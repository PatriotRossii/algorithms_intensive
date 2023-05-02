import sys

def remove_vowels(string):
	return string.replace("e", "a").replace("i", "a").replace("o", "a").replace("u", "a")

n = int(sys.stdin.readline().strip())
first_class = sys.stdin.readline().strip().split()
second_class = {
	element.lower(): element
	for element in reversed(first_class)
}
third_class = {
	remove_vowels(key): value
	for key, value in second_class.items()
}
first_class = set(first_class)

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
