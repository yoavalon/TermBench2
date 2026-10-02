import random

def permute_p_values():
    n = 1000
    p_values = [random.random() for _ in range(n)]
    while True:
        random.shuffle(p_values)
permute_p_values()