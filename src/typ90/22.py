import sys

sys.setrecursionlimit(10 ** 9)

A, B, C = map(int, input().split())


def gcd(m, n):
    a = max(m, n)
    b = min(m, n)
    if a % b == 0:
        return b
    return gcd(a % b, b)


def gcd3(p, q, r):
    return gcd(gcd(p, q), r)


g = gcd3(A, B, C)
print(A // g + B // g + C // g - 3)
