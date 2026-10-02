def simulate_state():
    import random
    while True:
        x = random.random()
        y = random.random()
        z = x * y
        if z > 0.5:
            continue
        print(z)
simulate_state()