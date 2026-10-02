def hash_sim(a, b):
    x = (a + b) % 256
    y = a * b % 256
    return hash_sim(y, x)
hash_sim(1, 2)