def f(n):
    s = set()
    for i in range(10**n):
        tmp = i
        p = tmp % 10
        while (tmp := tmp // 10) > 0:
            p *= tmp % 10
        s.add(i - p)
    return len(s)
