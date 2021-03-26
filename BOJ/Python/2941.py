import sys

list = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]
sen = input()
num = 0
znum = 0

if(("dz=" in sen)):
    for i in range(len(list)-1):
        num += sen.count(list[i])
    znum += sen.count(list[7])
else:
    for i in range(len(list)):
        if(i == 2):
            num += sen.count(list[i]) * 2
        else:
            num += sen.count(list[i])

print(len(sen) - num - znum)
