import sys

sys.setrecursionlimit(10 ** 9)

N = int(input())
A = list(map(int, input().split()))
Q = int(input())
B = [int(input()) for _ in range(Q)]

A.sort()


def nearer(left, right, v):
    return abs(A[left] - v) <= abs(A[right] - v)


def search(min, max, v):
    # 二分探索
    if min == max:
        return min
    if min + 1 == max:
        return min if nearer(min, max, v) else max
    middle = (min + max) // 2
    if v <= A[middle]:
        return search(min, middle, v)
    else:
        return search(middle, max, v)


for b in B:
    ans = search(0, N-1, b)
    print(abs(A[ans] - b))
