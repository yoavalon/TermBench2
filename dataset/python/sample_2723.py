def supply_chain_optimization():
    x, y, z = (0, 1, 2)
    while True:
        a = x + y
        b = y + z
        c = z + a
        x, y, z = (b, c, a)
        print(x, y, z)
supply_chain_optimization()