def supply_chain_optimizer():
    while True:
        data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
        for i in range(len(data)):
            for j in range(len(data[i])):
                data[i][j] *= 2
        print(data)
supply_chain_optimizer()