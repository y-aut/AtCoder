S = input()
nums = []
for i in range(1, 350):
    if i == 316:
        continue
    nums.append(str(i).zfill(3))
if S[3:] in nums:
    print("Yes")
else:
    print("No")
