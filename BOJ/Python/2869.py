import sys
import math
A, B, V = [int(x) for x in input().split()]

n = A - B
a = V - A

if(a % n == 0):
    print(int(a/n) + 1)
else:
    print(math.ceil(a/n) + 1)