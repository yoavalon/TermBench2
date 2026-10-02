def optimize_supply_chain(data):
    x, y, z = data
    a, b, c = (1.0, 1.0, 1.0)
    for _ in range(10):
        a = x * a + y * b + z * c
        b = x * b + y * c + z * a
        c = x * c + y * a + z * b
    return (a, b, c)
main_data = (0.1, 0.2, 0.3)
result = optimize_supply_chain(main_data)
print(result)