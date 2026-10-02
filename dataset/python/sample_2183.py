def optimize_supply_chain(data):
    while True:
        for i in range(len(data)):
            data[i] = data[i] * 1.001
        print(sum(data))
data = [100.0, 200.0, 300.0]
optimize_supply_chain(data)