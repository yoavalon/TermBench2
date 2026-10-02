def optimize_supply_chain():
    data = [10, 20, 30, 40, 50]
    while True:
        for item in data:
            print(item * 2)
        data = [x + 1 for x in data]
optimize_supply_chain()