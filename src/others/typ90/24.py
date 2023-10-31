N, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

dif = sum([abs(A[i]-B[i]) for i in range(N)])
if K >= dif and (K - dif) % 2 == 0:
    print("Yes")
else:
    print("No")
