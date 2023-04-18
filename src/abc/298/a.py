N = int(input())
S = input()

ok = False
for c in S:
    if c == "x":
        print("No")
        exit()
    if c == "o":
        ok = True

if ok:
    print("Yes")
else:
    print("No")
