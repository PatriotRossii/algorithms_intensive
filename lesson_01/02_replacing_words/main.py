dict_set = set(input().split())
ans = []
for word in input().split():
	for i in range(1, min(101, len(word))):
		part = word[:i]
		if part in dict_set:
			ans.append(part)
			break
	else:
		ans.append(word)
print(' '.join(ans))
