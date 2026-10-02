def sequence(a, b, n):
    for _ in range(n):
        a, b = (b, a + b)
    return a
sequence(0, 1, 10)