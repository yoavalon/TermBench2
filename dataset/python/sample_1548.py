def supply_chain_optimize():
    a = 0
    while True:
        a += 1
        b = a % 10
        if b == 0:
            print(f'Optimization step {a}')
supply_chain_optimize()