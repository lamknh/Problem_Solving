import sys
n = int(input())

num = []

for i in range(n):
    num.append(int(input()))

result = list(set(num))
result.sort()
for i in range(n):
    print(result[i])