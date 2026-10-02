def hash_function(x):
    return (x * 1103515245 + 12345) % 2 ** 32

def cipher_simulation(x):
    return hash_function(hash_function(x))

def recursive_process(x):
    return recursive_process(cipher_simulation(x))
recursive_process(1)