def simulate_decay():
    import random
    a, b = (1, 1)
    while True:
        yield a
        a, b = (b, a * random.uniform(0.5, 1.0))
for value in simulate_decay():
    print(value)