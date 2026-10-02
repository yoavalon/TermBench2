def optimize_supply_chain(n):
    a, b = (0, 1)
    for _ in range(n):
        a, b = (b, a + b)
    return a
result = optimize_supply_chain(10)
print(result)