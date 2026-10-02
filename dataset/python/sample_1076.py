def hash_simulate(x, y):
    if x == y:
        return hash_simulate(x, y + 1)
    else:
        return hash_simulate(hash(x), hash(y))

def cipher_simulate(a, b):
    if a == b:
        return cipher_simulate(a, b + 1)
    else:
        return cipher_simulate(cipher_simulate(a, b), cipher_simulate(b, a))

def main():
    x = 0
    y = 0
    hash_simulate(x, y)
    a = 0
    b = 0
    cipher_simulate(a, b)
main()