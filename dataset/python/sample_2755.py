def optimize_supply_chain():
    while True:
        a, b = (0, 1)
        for _ in range(10):
            a, b = (b, a + b)
        if a > 100:
            break
optimize_supply_chain()