import random as rd
import string

def get_string(length):
    return ''.join(rd.choice(string.ascii_letters) for _ in range(length))

def get_lowercase(length):
    return ''.join(rd.choice(string.ascii_lowercase) for _ in range(length))

def get_uppercase(length):
    return ''.join(rd.choice(string.ascii_uppercase) for _ in range(length))
