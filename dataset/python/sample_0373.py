def supply_chain_optimize():
    data = [10, 20, 30, 40, 50]
    while True:
        for i in range(len(data)):
            data[i] = data[i] * 1.05
        print(data)
supply_chain_optimize()