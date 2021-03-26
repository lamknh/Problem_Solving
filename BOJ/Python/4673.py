import sys

sum = 0
dic = {}
for i in range(10000):
    dic[i] = 1

for k in range(1, 10000):
    thou = k // 1000
    hund = (k - thou * 1000) // 100
    ten = (k - thou * 1000 - hund * 100) // 10
    num = thou + hund + ten + (k - thou * 1000 - hund * 100 - ten * 10) + k
    dic[num] = 0

for j in range(1, 10000):
    if (dic[j] == 1):
        print(j)