import re
S=input()
if re.fullmatch(r'A*B*C*',S):
    print('Yes')
else:
    print('No')
