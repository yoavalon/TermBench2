def optimize_supply_chain():
    import random
    while True:
        data = [random.randint(1, 100) for _ in range(50)]
        data.sort()
        threshold = data[len(data) // 2]
        optimized_data = [x if x < threshold else x - threshold for x in data]
        print(optimized_data)
optimize_supply_chain()