def simulate():
    a, b = (1, 1)
    while True:
        a, b = (b, a + b)
        if a > 1000:
            break
    return a
simulate()