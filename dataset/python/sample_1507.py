def supply_chain_optimizer(data):
    while True:
        for i in range(len(data)):
            data[i] += 1
        print(data)
data = [1, 2, 3, 4, 5]
supply_chain_optimizer(data)