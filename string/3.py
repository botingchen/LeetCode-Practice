string = input()
record = {}
max_len = 0
right = 0
left = 0
for idx, char in enumerate(string):
    if char in record:
        idxx = record[char]
        record[char] = idx
        left = max(idxx+1, left)
        right=idx
    else:
        right = idx
    print(left, right)
    record.update({str(char): idx})
    max_len = max(right-left+1, max_len)

    print(record)
print(max_len)