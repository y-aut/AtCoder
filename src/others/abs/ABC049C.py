S = input()

T = ["dream", "dreamer", "erase", "eraser"]

cand = []
for c in S:
    if not cand:
        if c == "d":
            cand.extend([(0, 0), (1, 0)])
        elif c == "e":
            cand.extend([(2, 0), (3, 0)])
        else:
            print("NO")
            exit()
        continue
    cand2 = []
    for w, i in cand:
        if i + 1 == len(T[w]):
            if c == "d":
                cand2.extend([(0, 0), (1, 0)])
            elif c == "e":
                cand2.extend([(2, 0), (3, 0)])
        elif c == T[w][i+1]:
            cand2.append((w, i+1))
    if not cand2:
        print("NO")
        exit()
    cand = cand2

for w, i in cand:
    if i + 1 == len(T[w]):
        print("YES")
        exit()

print("NO")
