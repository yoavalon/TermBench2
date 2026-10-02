def data_mutations():
    import random
    supply = [100, 200, 300, 400, 500]
    demand = [120, 180, 250, 300, 420]
    for _ in range(5):
        idx = random.randint(0, 4)
        supply[idx] += random.randint(-20, 20)
        demand[idx] += random.randint(-20, 20)
    return (supply, demand)
data_mutations()