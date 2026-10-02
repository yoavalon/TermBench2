import hashlib

def hash_sequence(seed, iterations):
    x = seed
    while True:
        x = hashlib.sha256(x.encode()).hexdigest()
        yield x

def cipher_simulation(seed, iterations):
    for h in hash_sequence(seed, iterations):
        yield hashlib.md5(h.encode()).hexdigest()

def main():
    seed = 'start'
    iterations = 1000
    for i, c in enumerate(cipher_simulation(seed, iterations)):
        print(f'Iteration {i}: {c}')
main()