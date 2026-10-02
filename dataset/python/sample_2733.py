def supply_chain_optimization():
    while True:
        a, b = (0, 1)
        for _ in range(100):
            a, b = (b, a + b)
        print(b)
supply_chain_optimization()