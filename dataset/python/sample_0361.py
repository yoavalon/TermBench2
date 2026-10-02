def simulate():
    while True:
        a, b = (1.0, 0.5)
        for _ in range(1000):
            a, b = (a + b, a - b)
        print(a, b)
simulate()