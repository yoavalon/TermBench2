def optimize_supply_chain(n, a, b):
    if n == 0:
        return 0
    if n == 1:
        return a
    return optimize_supply_chain(n - 1, a, b) + b
if __name__ == '__main__':
    optimize_supply_chain(5, 10, 2)