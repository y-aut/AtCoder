N = int(input())
S = input()

flg = False
for c in S:
    if c == "|":
        if flg:
            print("out")
            exit()
        flg = True
    elif c == "*":
        if flg:
            print("in")
        else:
            print("out")
        exit()
