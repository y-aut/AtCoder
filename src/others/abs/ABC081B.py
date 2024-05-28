N = int(input())
A = list(map(int, input().split()))

n = 0
while True:
    for i in range(len(A)):
        if A[i] % 2 == 1:
            break
        A[i] //= 2
    else:
        n += 1
        continue
    break

print(n)
