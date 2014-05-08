a = raw_input()
b = raw_input()
in_a = [0] * 26
in_b = [0] * 26

for c in a:
    in_a[ord(c) - 97] += 1
for c in b:
    in_b[ord(c) - 97] += 1
print sum([abs(x - y) for x, y in zip(in_a, in_b)])
