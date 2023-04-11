S = input()

B_ind = -1
R_ind = -1
K_ind = -1
for i in range(8):
    if S[i] == "B":
        if B_ind == -1:
            B_ind = i
        else:
            if (i - B_ind) % 2 == 0:
                print("No")
                exit()
    elif S[i] == "R":
        if R_ind == -1:
            R_ind = i
        elif K_ind == -1:
            print("No")
            exit()
    elif S[i] == "K":
        if R_ind == -1:
            print("No")
            exit()
        else:
            K_ind = i

print("Yes")
