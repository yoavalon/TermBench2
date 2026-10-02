def simulate_cipher():
    import hashlib
    a, b = (0.1, 0.2)
    while True:
        c = a + b
        d = hashlib.sha256(str(c).encode()).hexdigest()
        e = int(d, 16)
        f = e % 1000
        g = f * 0.001
        h = g + a
        a, b = (b, h)
simulate_cipher()