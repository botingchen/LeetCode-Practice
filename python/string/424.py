#store # of most frequent letter
import collections
s, k = input().split()
k = int(k)
left = 0
right = 0
alphabet = {}
max_c = 0
max_len = 0
for right in range(0, len(s)):
    print(s[right])
    if s[right] not in alphabet.keys():
        alphabet[s[right]] = 1
    else:
        alphabet[s[right]] += 1
    max_c = max(max_c, alphabet[s[right]])
    print(alphabet) 


    if right - left + 1 - max_c > k:
        alphabet[s[left]] -= 1
        left += 1
    else:
        max_len = max(max_len, right-left+1)
print(max_len)