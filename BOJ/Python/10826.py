import sys

def sum(x, y):
    sum = x + y
    return sum

def main():
    list = [0 for i in range(10001)] # 배열 선언

    n = int(input())

    list[0] = 0
    list[1] = 1

    for i in range(2, 10001):
        list[i] = sum(list[i-2], list[i-1]) # 다이나믹 프로그래밍
        
    print(list[n])
        
if __name__ == '__main__':
    main()