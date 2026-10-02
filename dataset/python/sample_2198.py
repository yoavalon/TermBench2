def simulate_cipher():
    import hashlib
    a, b = (0.1, 0.2)
    c = a + b
    while True:
        d = hashlib.sha256(str(c).encode()).hexdigest()
        e = int(d, 16)
        f = e % 2
        if f == 0:
            c += a
        else:
            c += b
simulate_cipher()