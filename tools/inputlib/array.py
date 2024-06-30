import random as rd

def get_rand_array(n, min, max):
    return [rd.randint(min, max) for _ in range(n)]
