import random as rd

def get_array(length, min, max):
    return [rd.randint(min, max) for _ in range(length)]

# 総和が sum となる長さ length の正整数列を生成する
def get_positive_array_sum(length, sum):
    res = [1] * length
    for _ in range(sum - length):
        res[rd.randint(0, length - 1)] += 1
    return res
