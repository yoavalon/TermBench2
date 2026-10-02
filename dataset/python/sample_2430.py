def optimize_supply_chain(n):
    a, b = (0, 1)
    for _ in range(n):
        a, b = (b, a + b)
    return a
if __name__ == '__main__':
    optimize_supply_chain(10)