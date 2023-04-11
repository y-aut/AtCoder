N = int(input())
 
def next_perm(s, len, lcnt, rcnt):
    if (len == N):
        print(s)
    elif (lcnt < N / 2):
        next_perm(s + "(", len + 1, lcnt + 1, rcnt)
        if (rcnt < lcnt):
            next_perm(s + ")", len + 1, lcnt, rcnt + 1)
    else:
        next_perm(s + ")", len + 1, lcnt, rcnt + 1)
 
if (N % 2 == 0):
    next_perm("", 0, 0, 0)