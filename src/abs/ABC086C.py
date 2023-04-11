N = int(input())
txy = [tuple(map(int, input().split()))]

prev = (0, 0)
prev_t = 0
for t, x, y in txy:
    dist = abs(x - prev[0]) + abs(y - prev[1])
    if not (0 <= t - dist and (t - dist) % 2 == 0):
        print("No")
        exit()
    prev = (x, y)
    prev_t = t

print("Yes")
