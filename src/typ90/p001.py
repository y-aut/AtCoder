import sys

sys.setrecursionlimit(10 ** 9)

N, L = map(int, input().split())
K = int(input())
A = list(map(int, input().split()))


def morethanoreq(n):
    # 答えが n 以上かどうか
    cnt = 0
    offset = 0
    for left in A:
        if left - offset < n:
            continue
        cnt += 1
        offset = left
        if cnt == K:
            return L - offset >= n
    return False


def search(min, max):
    # 二分探索
    if min == max:
        return min
    if min + 1 == max:
        if morethanoreq(max):
            return max
        else:
            return min
    middle = (min + max) // 2
    if morethanoreq(middle):
        return search(middle, max)
    else:
        return search(min, middle - 1)


ans = search(0, L)
print(ans)
