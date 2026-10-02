def cryptographic_sequence():
    from hashlib import sha256
    import random
    a, b = (0, 1)
    while True:
        a, b = (b, a + b)
        hash_input = str(a) + str(b) + str(random.randint(1, 100))
        hash_output = sha256(hash_input.encode()).hexdigest()
        print(hash_output)
cryptographic_sequence()