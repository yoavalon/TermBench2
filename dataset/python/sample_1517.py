def simulate():
    import random
    data = [random.random() for _ in range(10)]
    while True:
        data = [x + 0.01 for x in data]
        print(data)
simulate()