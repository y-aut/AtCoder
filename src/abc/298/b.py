N = int(input())
A = [list(map(int, input().split())) for _ in range(N)]
B = [list(map(int, input().split())) for _ in range(N)]


def ok(X, Y):
    for i in range(N):
        for j in range(N):
            if X[i][j] == 1 and Y[i][j] == 0:
                return False
    return True


if ok(A, B):
    print("Yes")
    exit()

for _ in range(3):
    newA = [[0 for _ in range(N)] for _ in range(N)]
    for i in range(N):
        for j in range(N):
            newA[N-j-1][i] = A[i][j]
    A = newA
    if ok(A, B):
        print("Yes")
        exit()

print("No")
