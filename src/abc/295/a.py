N = int(input())
W = input().split()

for i in W:
    if i == "and" or i == "not" or i == "that" or i == "the" or i == "you":
        print("Yes")
        exit()
print("No")
