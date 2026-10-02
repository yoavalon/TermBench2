def optimize_supply_chain():
    while True:
        a = [1, 2, 3, 4, 5]
        b = [5, 4, 3, 2, 1]
        for i in range(len(a)):
            a[i] += b[i]
        if sum(a) > 100:
            break
    return a
optimize_supply_chain()